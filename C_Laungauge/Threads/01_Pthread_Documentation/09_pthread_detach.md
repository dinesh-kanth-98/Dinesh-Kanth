**<div align="center" >pthread_detach function</div>**

### Table of content

- [pthread\_detach](#pthread_detach)
  - [Function Signature](#function-signature)
  - [Parameters](#parameters)
  - [Return Value](#return-value)
  - [Description](#description)
  - [Errors](#errors)
  - [Example](#example)
  - [Important Notes](#important-notes)

## pthread_detach

The `pthread_detach` function in the POSIX threads (pthread) library is used to mark a thread as detached. A detached thread is one that will automatically release its resources (e.g., memory) when it exits, without requiring another thread to call `pthread_join` to clean up after it. Here's a detailed documentation of `pthread_detach`

### Function Signature

```c
int pthread_detach(pthread_t thread);
```

### Parameters

- `thread`: The thread ID of the thread you want to detach. This parameter specifies the thread you want to mark as detached.

### Return Value

- If successful, `pthread_detach` returns 0.
- If an error occurs, it returns a non-zero error code.

### Description

The `pthread_detach` function is used to indicate that the thread specified by `thread` is to be detached. A detached thread is one that will release its resources automatically when it exits, without requiring another thread to call `pthread_join` to collect its exit status.

Detached threads are typically used when you don't need to obtain the exit status of the thread and want the system to automatically reclaim the thread's resources upon termination. This is particularly useful for short-lived or fire-and-forget threads.

### Errors

- `EINVAL`: The specified thread is not a joinable thread, or it's the calling thread itself.
- `ESRCH`: No thread with the ID `thread` could be found.
- Other error codes may be returned depending on the system and implementation.

### Example

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // This thread does some work
    printf("Thread doing work...\n");
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Create a thread and immediately detach it
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Detach the thread
    if (pthread_detach(thread_id) != 0) {
        perror("pthread_detach");
        return 1;
    }

    // Continue with the main thread's work
    printf("Main thread continuing...\n");

    // The detached thread's resources will be automatically cleaned up upon exit

    return 0;
}
```

In this example, we create a thread and immediately detach it using `pthread_detach`. The detached thread continues its work independently, and its resources will be automatically cleaned up when it exits. The main thread can continue its work without waiting for the detached thread to finish.

### Important Notes

- Attempting to call `pthread_join` on a detached thread or trying to detach the same thread multiple times is undefined behavior.
- Detaching a thread is irreversible; once detached, you cannot join it later.
- Always ensure proper synchronization and resource management in your threads to prevent resource leaks, even when using detached threads.
