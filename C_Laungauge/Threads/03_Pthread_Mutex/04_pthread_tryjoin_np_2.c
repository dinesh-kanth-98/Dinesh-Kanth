#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_INCREMENTS 10000

// Shared counter variable
int counter = 0;

// Mutex for synchronizing access to the counter
pthread_mutex_t mutex;

// Function to be executed by threads
void *increment_counter(void *arg)
{
    for (int i = 0; i < NUM_INCREMENTS; i++)
    {
        // Lock the mutex before modifying the shared counter
        pthread_mutex_lock(&mutex);

        // Critical section: Increment the counter
        counter++;

        // Unlock the mutex after modifying the shared counter
        pthread_mutex_unlock(&mutex);
    }
    sleep(5);
    return NULL;
}

int main()
{
    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        perror("pthread_mutex_init");
        return 1;
    }

    pthread_t threads[NUM_THREADS];

    // Create multiple threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0)
        {
            perror("pthread_create");
            return 1;
        }
    }

    int cnt = 0;
    while (1)
    {
        // Wait for all threads to finish
        for (int i = 0; i < NUM_THREADS; i++)
        {
            // printf("in loop:%d\n", i);
            if (pthread_tryjoin_np(threads[i], NULL) == 0)
            {
                printf("pthread_join :%d\n", i);
                cnt++;
                // return 1;
            }
        }
        if (cnt == 4)
            break;
    }
    // Print the final value of the shared counter
    printf("Final counter value: %d\n", counter);

    // Destroy the mutex
    if (pthread_mutex_destroy(&mutex) != 0)
    {
        perror("pthread_mutex_destroy");
        return 1;
    }

    return 0;
}