**<div align="center" >pthread_join function</div>**

### Table of content

- [pthread\_join](#pthread_join)
  - [Function Signature](#function-signature)
  - [Parameters](#parameters)
  - [Return Value](#return-value)
  - [Example Usage](#example-usage)

# pthread_join

The `pthread_join` function in C is used to make a calling thread wait for the termination of a specified thread. It's commonly used for thread synchronization. Here's a brief overview of `pthread_join`, along with a simple example:

## Function Signature

```c
#include <pthread.h>

int pthread_join(pthread_t thread, void **retval);
```

## Parameters

- `thread`: The thread ID of the thread to be joined.
- `retval`: A pointer to a location where the exit status of the joined thread will be stored. This exit status is typically set using `pthread_exit`.

## Return Value

- On success, `pthread_join` returns 0.
- On error, it returns an error code, which can be used to identify the error condition.

## Example Usage

```c
#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    int *input = (int *)arg;
    printf("Thread received argument: %d\n", *input);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    int arg = 42;

    // Create a new thread
    if (pthread_create(&tid, NULL, threadFunction, &arg) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to complete
    void *status;
    if (pthread_join(tid, &status) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Thread completed with status: %p\n", status);

    return 0;
}
```

In this example:

1. We create a new thread using `pthread_create`, passing a pointer to the `threadFunction` and an argument (`arg`) to the thread.

2. We use `pthread_join` to wait for the thread to complete. The exit status of the thread is stored in the `status` variable.

3. Finally, we print the exit status of the thread.

> `pthread_join` is a crucial function for ensuring proper synchronization between threads, allowing one thread to wait for another to complete its work.
