#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    // Set cancellation state to Deferred
    pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL);
    int i=0;
    while (1)
    {
        i=0;
        printf("Thread is running...\n");
        while (i < 10)
        {
            printf("loop is running : %d\n",i++);
        }
        
        sleep(1); // A cancellation point
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
    usleep(3);
    printf("Main thread: Awake from sleep.\n");

    // Request cancellation of the thread (deferred until the next cancellation point)
    if (pthread_cancel(thread_id) != 0)
    {
        perror("pthread_cancel");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread finished.\n");
    return 0;
}