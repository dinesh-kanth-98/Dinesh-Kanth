**<div align="center" >pthread_cond_wait function</div>**

#### Table of content

- [Function Signature:](#function-signature)
- [Parameters:](#parameters)
- [Return Value:](#return-value)
- [Description:](#description)
- [Use Case:](#use-case)
- [Pitfalls:](#pitfalls)
- [Example:](#example)

### Function Signature:

```c
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);
```

### Parameters:

- `cond`: A pointer to a `pthread_cond_t` object representing the condition variable on which the calling thread should wait.

- `mutex`: A pointer to a `pthread_mutex_t` object representing the mutex that will be released before waiting and reacquired upon waking up.

### Return Value:

- If successful, `pthread_cond_wait` returns 0, indicating that the calling thread has successfully waited on the condition variable.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

### Description:

The `pthread_cond_wait` function causes the calling thread to block until the specified condition variable `cond` is signaled. It also unlocks the associated mutex `mutex` while waiting and relocks it before returning. The thread must own the mutex before calling this function. The function is typically used to implement the "wait" part of a condition synchronization scheme.

### Use Case:

- A thread waits for a condition to become true before proceeding. The mutex ensures that the wait and condition check are atomic, preventing race conditions.

### Pitfalls:

- Always ensure that the thread owns the mutex `mutex` before calling `pthread_cond_wait`. Calling this function without owning the mutex can lead to undefined behavior.

- Be cautious of spurious wake-ups, where a thread can wake up without a signal. Always recheck the condition upon waking up to ensure it's truly satisfied.

- Ensure that a signaling thread sends the signal after the waiting thread has started waiting, or the signal may be missed.

- Be aware that `pthread_cond_wait` can return due to signals other than explicit signals. Spurious wake-ups can happen, so always recheck the condition.

### Example:

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

- Finally, the main thread waits for all child threads to finish using `pthread_join`.

`pthread_cond_wait` is a fundamental function for implementing condition synchronization in multi-threaded programs. It allows threads to efficiently wait for specific conditions to be met while avoiding busy-waiting.