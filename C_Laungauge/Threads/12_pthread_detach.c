#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *background_thread(void *arg)
{
    // Perform some background tasks
    for (int i = 1; i <= 5; i++)
    {
        printf("Background Thread: Working on task %d\n", i);
        sleep(1);
    }

    printf("Background Thread Exiting \n");

    // The thread will exit automatically when it's done
    return NULL;
}

int main()
{
    pthread_t thread;
    int result;

    // Create a background thread and immediately detach it
    if (pthread_create(&thread, NULL, background_thread, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    if (pthread_detach(thread) != 0)
    {
        perror("pthread_detach");
        return 1;
    }

    // Continue with the main thread's work
    printf("Main Thread: Doing some other tasks...\n");

    // Wait for a while to allow the background thread to work
    sleep(10);

    printf("Main Thread: Finished.\n");

    return 0;
}
