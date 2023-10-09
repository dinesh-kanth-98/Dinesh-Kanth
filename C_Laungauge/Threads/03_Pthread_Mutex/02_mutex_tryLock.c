#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Shared counter
int counter = 0;

// Mutex for protecting the shared counter
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function that increments the shared counter
void *increment_counter(void *thread_id)
{
    int id = *(int *)thread_id;

    // Attempt to lock the mutex (trylock)
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("Thread %d: Locked the mutex\n", id);

        // Critical section: Increment the shared counter
        counter++;

        printf("Thread %d: Incremented counter: %d\n", id, counter);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
        printf("Thread %d: Unlocked the mutex\n", id);
    }
    else
    {
        // Mutex was locked by another thread
        printf("Thread %d: Mutex is already locked by another thread\n", id);
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create and launch multiple threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", counter);

    return 0;
}
