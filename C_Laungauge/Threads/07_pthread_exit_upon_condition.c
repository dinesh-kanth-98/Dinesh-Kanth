#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int *shared_data = (int *)arg;

    // Perform some work in the thread
    while (*shared_data < 10)
    {
        printf("Thread: Value = %d\n", *shared_data);

        // Check a condition, and if met, exit the thread
        if (*shared_data == 5)
        {
            printf("Thread: Exiting early due to condition.\n");
            pthread_exit(NULL);
        }

        (*shared_data)++;
    }

    printf("Thread: Completed.\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id;
    // int shared_data = 0;
    int shared_data = 11;

    // Create a thread and pass shared_data as an argument
    if (pthread_create(&thread_id, NULL, thread_function, &shared_data) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread: Thread has exited.\n");

    return 0;
}
