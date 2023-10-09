**<div align="center" >pthread_cond_signal function</div>**

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
int pthread_cond_signal(pthread_cond_t* cond);
```

### Parameters

- `cond`: A pointer to a `pthread_cond_t` object representing the condition variable on which to send a signal.

### Return Value

- If successful, `pthread_cond_signal` returns 0, indicating that the signal has been successfully sent to the condition variable.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

### Description

The `pthread_cond_signal` function is used to wake up one waiting thread that is blocked on the specified condition variable `cond`. If no threads are waiting, the signal has no effect. It's typically used to notify a waiting thread that a specific condition has been met and that the thread can proceed.

### Use Case

- Signaling a waiting thread when a specific condition has been met.

### Pitfalls

- Ensure that the signal is sent after the thread to be signaled has started waiting, or it may be missed. This is because if the signal is sent before the thread waits, it might be missed, and the thread may continue without noticing the signal.

- Be aware that `pthread_cond_signal` wakes up only one waiting thread. If multiple threads are waiting, only one of them will be awakened, and which one is awakened is not guaranteed. To wake up all waiting threads, you can use `pthread_cond_broadcast`.

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

    // Signal the condition to wake up waiting threads
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&condition);
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

- The main thread then signals the condition variable using `pthread_cond_signal`.

- This wakes up one of the waiting threads, and the process is repeated until all threads have been woken up.

`pthread_cond_signal` is a fundamental function for notifying waiting threads in a multi-threaded program when specific conditions have been met.
