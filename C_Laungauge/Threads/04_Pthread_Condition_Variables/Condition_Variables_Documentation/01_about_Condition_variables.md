**<div align="center" >About Condition variables</div>**

### Table of content

- [Table of content](#table-of-content)
- [Overview](#overview)
- [Condition Variable Functions](#condition-variable-functions)
- [Use Cases](#use-cases)
- [Pitfalls and Considerations](#pitfalls-and-considerations)
- [Usage Example](#usage-example)

### Overview

Condition variables are synchronization primitives used in multi-threaded programming to allow threads to wait for specific conditions to be met before proceeding. They are often used in conjunction with mutexes to coordinate threads and avoid busy-waiting. Condition variables help in achieving efficient thread synchronization and inter-thread communication.

### Condition Variable Functions

1. **pthread_cond_init**:

   - Function Signature:

     ```c
     int pthread_cond_init(pthread_cond_t* cond, const pthread_condattr_t* attr);
     ```

   - Description:
     Initializes a condition variable. `cond` is a pointer to the condition variable object to be initialized, and `attr` is a pointer to the condition attribute object. If `attr` is `NULL`, default attributes are used.

   - Use Case:
     - Initialization of a condition variable before its first use.

   - Pitfalls:
     - Ensure that you initialize the condition variable before using it.
     - Be mindful of potential resource leaks; always call `pthread_cond_destroy` to clean up.

2. **pthread_cond_destroy**:

   - Function Signature:

     ```c
     int pthread_cond_destroy(pthread_cond_t* cond);
     ```

   - Description:
     Destroys a condition variable previously initialized with `pthread_cond_init`. It frees any resources associated with the condition variable.

   - Use Case:
     - Cleanup and deallocation of resources associated with a condition variable.

   - Pitfalls:
     - Make sure you destroy the condition variable when it's no longer needed to prevent resource leaks.

3. **pthread_cond_wait**:

   - Function Signature:

     ```c
     int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);
     ```

   - Description:
     Causes the calling thread to block until the specified condition variable `cond` is signaled. It also unlocks the associated mutex `mutex` while waiting and relocks it before returning. The thread must own the mutex before calling this function.

   - Use Case:
     - A thread waits for a condition to become true before proceeding. The mutex ensures that the wait and condition check are atomic.

   - Pitfalls:
     - Always ensure that the thread owns the mutex before calling `pthread_cond_wait`.
     - Be cautious of spurious wake-ups, where a thread can wake up without a signal.

4. **pthread_cond_signal**:

   - Function Signature:

     ```c
     int pthread_cond_signal(pthread_cond_t* cond);
     ```

   - Description:
     Wakes up one waiting thread that is blocked on the specified condition variable `cond`. If no threads are waiting, the signal has no effect.

   - Use Case:
     - Signaling a waiting thread when a specific condition has been met.

   - Pitfalls:
     - Ensure that the signal is sent after the thread to be signaled has started waiting, or it may be missed.

5. **pthread_cond_broadcast**:

   - Function Signature:

     ```c
     int pthread_cond_broadcast(pthread_cond_t* cond);
     ```

   - Description:
     Wakes up all waiting threads that are blocked on the specified condition variable `cond`.

   - Use Case:
     - Broadcasting a signal to wake up all waiting threads when a shared resource becomes available.

   - Pitfalls:
     - Broadcasting can be less efficient than signaling a specific thread, as all waiting threads will be woken up.

### Use Cases

- **Producer-Consumer Problem**: Condition variables can be used to coordinate producer and consumer threads to ensure that the producer only adds data when there's space available and the consumer only retrieves data when it's available.

- **Thread Pool**: In a thread pool, condition variables can be used to signal available worker threads when there are tasks to be processed.

- **Readers-Writers Problem**: Condition variables can be used to solve the readers-writers problem, where multiple readers can access shared data simultaneously, but exclusive access is required for writers.

- **Resource Pooling**: Condition variables can be used to manage a pool of resources, allowing threads to request and release resources when needed.

### Pitfalls and Considerations

- **Spurious Wake-ups**: Threads waiting on condition variables may wake up even without a signal. Always recheck the condition when the thread wakes up.

- **Deadlocks**: Incorrect usage of mutexes and condition variables can lead to deadlocks. Ensure proper locking and unlocking to avoid deadlocks.

- **Broadcasting vs. Signaling**: Broadcasting can be less efficient as it wakes up all waiting threads, even if only one can proceed. Signaling a specific thread is often more efficient.

- **Shared Variables**: Use mutexes and condition variables consistently to protect shared variables. Failing to do so can lead to data races and bugs.

- **Resource Management**: Always destroy condition variables and associated resources when they are no longer needed to prevent resource leaks.

> Condition variables are powerful synchronization tools that enable threads to efficiently coordinate their activities based on specific conditions. When used correctly, they can help you design efficient and thread-safe multi-threaded programs.

### Usage Example

Here's a simple example demonstrating the use of condition variables to synchronize threads:

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
