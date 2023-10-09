**<div align="center" >pthread_cond_broadcast function</div>**

#### Table of content

- [Function Signature](#function-signature)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Description](#description)
- [Use Case](#use-case)
- [Pitfalls](#pitfalls)
- [Example](#example)

### Function Signature

```c
int pthread_cond_broadcast(pthread_cond_t* cond);
```

### Parameters

- `cond`: A pointer to a `pthread_cond_t` object representing the condition variable on which to broadcast a signal.

### Return Value

- If successful, `pthread_cond_broadcast` returns 0, indicating that the broadcast signal has been successfully sent to the condition variable.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

### Description

The `pthread_cond_broadcast` function is used to wake up all waiting threads that are blocked on the specified condition variable `cond`. It sends a signal to all waiting threads, allowing them to proceed. This is typically used when multiple threads are waiting for a shared resource to become available.

### Use Case

- Broadcasting a signal to wake up all waiting threads when a shared resource becomes available or a general condition is met.

### Pitfalls

- Broadcasting can be less efficient than signaling a specific thread using `pthread_cond_signal`, as it wakes up all waiting threads, even if only one can proceed. Carefully consider your use case and whether broadcasting is appropriate.

- Ensure that the broadcast signal is sent after threads have started waiting. Sending a broadcast signal before threads wait may result in missed signals.

- Be aware that `pthread_cond_broadcast` may wake up all waiting threads, but the order in which they wake up is not guaranteed. Threads may still need to compete for the shared resource.

### Example

```c
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

void* thread_function(void* arg) {
    int* thread_id = (int*)arg;
    
    // Acquire the mutex
    pthread_mutex_lock(&mutex);
    
    printf("Thread %d: Waiting...\n", *thread_id);

    // Wait for the condition to be signaled
    pthread_cond_wait(&condition, &mutex);

    printf("Thread %d: Woken up!\n", *thread_id);

    // Release the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    // Sleep for a while to allow threads to block on condition
    sleep(2);

    // Broadcast the condition to wake up all waiting threads
    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&condition);
    pthread_mutex_unlock(&mutex);

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
```

In this example:

- Three threads are created, each of which enters a waiting state using `pthread_cond_wait` after acquiring the mutex.

- The main thread sleeps briefly to allow the other threads to enter the waiting state.

- The main thread then broadcasts the condition variable using `pthread_cond_broadcast`.

- This wakes up all waiting threads, and they can proceed in parallel.

`pthread_cond_broadcast` is a useful function for waking up multiple waiting threads in a multi-threaded program when a shared resource becomes available or when a general condition is met.
