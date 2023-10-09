
**<div align="center" >pthread_self function</div>**

### Table of content

- [Function Signature](#function-signature)
- [Description](#description)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Usage](#usage)
- [Example](#example)

## Function Signature

```c
#include <pthread.h>

pthread_t pthread_self(void);
```

## Description

The `pthread_self` function is used to obtain the thread ID (also known as the thread handle) of the calling thread. The thread ID is a unique identifier assigned to each thread when it is created, and it can be used to manipulate or identify the thread within a multi-threaded program.

## Parameters

The `pthread_self` function does not take any parameters.

## Return Value

The `pthread_self` function returns the thread ID (pthread_t) of the calling thread. The thread ID is an opaque data type that represents a unique identifier for the thread.

## Usage

The primary use of `pthread_self` is to obtain the thread ID of the currently executing thread. This can be useful for various purposes, such as:

1. **Thread Management**: You can use `pthread_self` to obtain the ID of the current thread and perform operations like thread cancellation, thread-specific data management, or thread manipulation.

2. **Logging and Debugging**: Thread IDs can be included in log messages or debugging information to identify which thread generated a particular message or encountered an issue.

3. **Thread-Specific Data**: Thread-specific data (using functions like `pthread_key_create` and `pthread_setspecific`) often requires the thread ID to associate data with specific threads.

## Example

Here's a simple example that demonstrates the use of `pthread_self` to obtain and print the thread ID of the currently executing thread:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
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

In this example:

- The `thread_function` obtains the thread ID of the current thread using `pthread_self` and prints it.
- In the main thread, `pthread_create` is used to create a new thread, and `pthread_join` is used to wait for it to finish.
- Both the main thread and the new thread obtain and print their respective thread IDs.

This demonstrates how `pthread_self` can be used to identify and work with thread IDs within a multi-threaded program.
