#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int *value = (int *)arg;
    printf("Thread argument: %d\n", *value);
    sleep(5);
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

    printf("Main thread finished.\n");
    return 0;
}

/*
The potential issue is that there's no synchronization mechanism (e.g., pthread_join)
to ensure that the new thread completes its work before the main thread exits. Depending
on how the system schedules the threads, it's possible that the main thread may exit
before the newly created thread finishes executing its thread_function.
This could result in the premature termination of the new thread.
*/

/*
In This code, you have two parts: the main part (main thread) and a small task (new thread).
The main part starts the small task and then says, "I'm done!" and exits.

Now, here's the potential issue: Sometimes, the small task might take longer to complete,
and the main part might exit before the small task is finished. This means the small task
will be left incomplete.

In programming, this is similar to giving someone a job and not waiting to see if they
finish it before you leave. To avoid this issue, you can use `pthread_join` to make the
main part wait until the small task is done before it says, "I'm done!" and exits the program.
This ensures that the small task gets completed properly.
*/