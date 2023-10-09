#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    while (1)
    {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Sleep for a while to allow the thread to run
    sleep(3);

    // Request cancellation of the thread
    if (pthread_cancel(thread_id) != 0)
    {
        perror("pthread_cancel");
        return 1;
    }

    // The thread will be terminated immediately
    printf("Main thread finished.\n");
    return 0;
}