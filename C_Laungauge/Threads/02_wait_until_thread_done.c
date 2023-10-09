#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int *value = (int *)arg;
    printf("Thread argument: %d\n", *value);
    sleep(5);
    printf("thread is exiting\n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    int argument_value = 42;

    if (pthread_create(&thread_id, NULL, thread_function, &argument_value) != 0)
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

    printf("Main thread finished.\n");
    return 0;
}
