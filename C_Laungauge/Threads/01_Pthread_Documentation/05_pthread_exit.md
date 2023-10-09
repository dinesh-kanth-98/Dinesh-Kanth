**<div align="center" >pthread_exit function</div>**

### Table of content

- [Function Signature](#function-signature)
- [Description](#description)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Thread Termination](#thread-termination)
- [Example](#example)

## Function Signature

```c
#include <pthread.h>

void pthread_exit(void *retval);
```

## Description

The `pthread_exit` function is used to terminate the calling thread and return a value to the parent thread. It allows a thread to exit its execution while optionally providing a return value to the parent thread. When a thread exits using `pthread_exit`, its resources are automatically cleaned up by the system.

## Parameters

- `retval`: A pointer to the value that will be returned to the parent thread. This value can be of any data type since it is a `void*`. The value can be used by the parent thread to retrieve information about the terminated thread's execution.

## Return Value

The `pthread_exit` function does not return a value to the calling thread. Instead, it terminates the calling thread and passes the `retval` value to the parent thread.

## Thread Termination

When a thread calls `pthread_exit`, it terminates its execution, and the following actions occur:

1. The thread's resources, such as its stack and thread control block, are released by the system.
2. If the thread is detached (created with the `PTHREAD_CREATE_DETACHED` attribute), its resources are automatically reclaimed by the system.
3. If the thread is joinable (created with the `PTHREAD_CREATE_JOINABLE` attribute), the `retval` value is made available to any thread that joins it using `pthread_join`.

## Example

Here's an example that demonstrates the use of `pthread_exit`:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d is running.\n", thread_id);
    
    // Simulate some work
    sleep(2);
    
    printf("Thread %d is exiting.\n", thread_id);
    
    int* result = malloc(sizeof(int));
    *result = thread_id * 2;
    
    // Exit the thread and provide a return value
    pthread_exit(result);
}

int main() {
    pthread_t thread_id;
    int thread_arg = 42;

    if (pthread_create(&thread_id, NULL, thread_function, &thread_arg) != 0) {
        perror("pthread_create");
        return 1;
    }

    void* result;
    
    // Join the thread to retrieve the return value
    if (pthread_join(thread_id, &result) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread received a result: %d\n", *(int*)result);

    // Free the memory allocated for the result
    free(result);
    
    return 0;
}
```

In this example:

- The `thread_function` takes an integer argument and simulates some work before exiting.
- The thread provides a return value by allocating memory for an integer, setting it, and then exiting using `pthread_exit`.
- In the main thread, `pthread_join` is used to retrieve the return value from the terminated thread.

Keep in mind that `pthread_exit` should be used carefully to ensure that resources are properly managed, especially in multi-threaded programs. Failure to join or detach threads can lead to resource leaks.
