**<div align="center" >pthread_create function</div>**

### Table of content

- [pthread\_create](#pthread_create)
  - [Parameters](#parameters)
  - [Return Value](#return-value)
  - [Thread Creation](#thread-creation)
  - [Thread Termination](#thread-termination)

# pthread_create

The `pthread_create` function in C is used to create a new thread within a multi-threaded program. It takes several parameters to specify the attributes and behavior of the new thread. Here is the documentation for the `pthread_create` function:

```c
#include <pthread.h>

int pthread_create(
    pthread_t *thread,                // Pointer to a pthread_t variable to store the thread ID of the newly created thread.
    const pthread_attr_t *attr,       // Pointer to a pthread_attr_t structure that specifies thread attributes (can be NULL for default attributes).
    void *(*start_routine)(void *),   // Pointer to the function that the new thread will execute. It takes a single argument of type void* and returns a void*.
    void *arg                         // Argument to pass to the start_routine function.
);
```

## Parameters

- `thread`: A pointer to a `pthread_t` variable where the thread ID of the newly created thread will be stored. This ID can be used to manipulate or join the thread later.

- `attr`: A pointer to a `pthread_attr_t` structure that specifies various attributes for the new thread. This can include settings related to thread stack size, scheduling policy, and more. You can pass `NULL` to use the default attributes.
  
  [thread_attributes in Detail](./03_thread_attributes.md)

- `start_routine`: A pointer to the function that the new thread will execute. This function should have the following signature:

   ```c
   void* start_routine(void* arg);
   ```

   It takes a single argument (`arg`) of type `void*` and returns a `void*`. This function is the entry point for the new thread's execution.

- `arg`: The argument to pass to the `start_routine` function. This argument can be of any data type, but it's typically a pointer to a data structure that holds the thread's input parameters.

## Return Value

- If the `pthread_create` function succeeds in creating the new thread, it returns `0` (zero).

- If an error occurs, it returns an error code indicating the type of error. You can use functions like `strerror` to convert the error code into a human-readable error message.

## Thread Creation

When `pthread_create` is called, a new thread is created and begins executing the `start_routine` function with the provided argument. The thread runs independently alongside the main thread and other threads in the program.

## Thread Termination

To ensure proper resource cleanup, it is essential to use `pthread_join` to wait for the newly created thread to finish execution and clean up its resources when it's no longer needed. Failure to do so may result in resource leaks.

Here's an example of how `pthread_create` can be used to create and run a new thread:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int* value = (int*)arg;
    printf("Thread argument: %d\n", *value);
    return NULL;
}

int main() {
    pthread_t thread_id;
    int argument_value = 42;

    if (pthread_create(&thread_id, NULL, thread_function, &argument_value) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread finished.\n");
    return 0;
}
```

In this example, `pthread_create` is used to create a new thread that executes the `thread_function` with the provided argument. The main thread waits for the new thread to finish using `pthread_join`.
