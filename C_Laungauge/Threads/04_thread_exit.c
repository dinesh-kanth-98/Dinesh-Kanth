#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_function(void *arg)
{
    int thread_Argument = *(int *)arg;
    printf("Thread is running.\n");

    sleep(2);

    printf("Thread is exiting.\n");

    int *result = malloc(sizeof(int));
    *result = thread_Argument * 2;

    // Exit the thread and provide a return value
    pthread_exit(result);
}

int main()
{
    pthread_t thread_id;
    int thread_arg = 42;

    if (pthread_create(&thread_id, NULL, thread_function, &thread_arg) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    void *result;

    // Join the thread to retrieve the return value
    if (pthread_join(thread_id, &result) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread received a result: %d\n", *(int *)result);

    // Free the memory allocated for the result
    free(result);

    return 0;
}