#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void *subthread_function1(void *arg)
{
    // Subthread 1 logic
    printf("Subthread 1 is working\n");
    sleep(3); // Sleep for a longer time

    pthread_exit(NULL);
}

void *subthread_function2(void *arg)
{
    // Subthread 2 logic
    printf("Subthread 2 is working\n");
    sleep(2);

    pthread_exit(NULL);
}

void *thread_function(void *arg)
{
    int thread_id = *((int *)arg);
    pthread_t subthreads[NUM_THREADS];
    int subthread_ids[NUM_THREADS];
    int subthread_exited[NUM_THREADS] = {0}; // Flags to track subthread exit status
    int i;

    // Create and run multiple subthreads within thread1 with different functions
    if (pthread_create(&subthreads[0], NULL, subthread_function1, NULL) != 0)
    {
        perror("Subthread 1 creation failed");
        return NULL;
    }

    if (pthread_create(&subthreads[1], NULL, subthread_function2, NULL) != 0)
    {
        perror("Subthread 2 creation failed");
        return NULL;
    }

    // Check for subthread exits in a non-blocking way
    while (1)
    {
        for (i = 0; i < NUM_THREADS; i++)
        {
            if (!subthread_exited[i])
            {
                int ret = pthread_tryjoin_np(subthreads[i], NULL);
                if (ret == 0)
                {
                    printf("Subthread %d has exited.\n", i + 1);
                    subthread_exited[i] = 1; // Mark as exited
                }
                else if (ret == EBUSY)
                {
                    // Subthread is still running
                }
                else
                {
                    perror("pthread_tryjoin_np failed");
                    return NULL;
                }
            }
        }

        // Check if all subthreads have exited
        int all_exited = 1;
        for (i = 0; i < NUM_THREADS; i++)
        {
            if (!subthread_exited[i])
            {
                all_exited = 0;
                break;
            }
        }

        if (all_exited)
        {
            break; // All subthreads have exited
        }

        usleep(100000); // Sleep for a short time before checking again
    }

    printf("Thread %d has completed all subthreads.\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1;
    int thread_id = 1;

    // Create thread1
    if (pthread_create(&thread1, NULL, thread_function, &thread_id) != 0)
    {
        perror("Thread 1 creation failed");
        return 1;
    }

    // Wait for thread1 to finish (including its subthreads)
    if (pthread_join(thread1, NULL) != 0)
    {
        perror("Thread 1 join failed");
        return 1;
    }

    printf("All threads have completed.\n");

    return 0;
}
