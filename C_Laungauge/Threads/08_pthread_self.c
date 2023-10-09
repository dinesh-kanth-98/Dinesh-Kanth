#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    pthread_t thread_id = pthread_self(); // Get the thread ID of the current thread
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main()
{
    pthread_t thread_id;

    // Create a thread and pass NULL as the argument
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0)
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

    pthread_t main_thread_id = pthread_self(); // Get the thread ID of the main thread
    printf("Main Thread ID: %lu\n", (unsigned long)main_thread_id);

    return 0;
}
