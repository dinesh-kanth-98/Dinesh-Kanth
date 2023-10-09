#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    // Disable thread cancellation
    int old_cancel_state;
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancel_state);

    for (int i = 0; i < 5; i++)
    {
        printf("Thread: Working %d\n", i);
        sleep(1); // Simulate some work
    }

    // Re-enable thread cancellation
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &old_cancel_state);

    printf("Thread: Cancellation enabled.\n");

    // Keep running and checking for cancellation
    while (1)
    {
        pthread_testcancel(); // Check for cancellation points
        printf("Thread: Running (checking for cancellation)...\n");
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t thread_id;

    // Create a thread
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    sleep(9); // Let the thread run for a while

    // Cancel the thread
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

    printf("Main thread: Thread has exited.\n");

    return 0;
}
