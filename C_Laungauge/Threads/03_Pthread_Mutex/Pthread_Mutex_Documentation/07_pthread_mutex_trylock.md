**<div align="center" >pthread_mutex_trylock Function</div>**

#### Table of content

- [Function Signature](#function-signature)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Description](#description)
- [Locking the Mutex](#locking-the-mutex)
- [Error Handling](#error-handling)
- [Usage Example](#usage-example)

The `pthread_mutex_trylock` function in the POSIX threads (pthread) library is used to attempt to acquire a lock on a mutex without blocking. It allows a thread to check if the mutex is currently available and acquire it if no other thread is holding the lock. Here's a detailed documentation of `pthread_mutex_trylock`:

### Function Signature

```c
int pthread_mutex_trylock(pthread_mutex_t* mutex);
```

### Parameters

- `mutex`: A pointer to the mutex object that you want to try to lock.

### Return Value

- If the attempt to lock the mutex is successful, `pthread_mutex_trylock` returns 0, indicating that the calling thread has acquired the lock.

- If the mutex is already locked by another thread or if an error occurs, it returns a non-zero error code. In this case, the mutex remains in its previous locked or unlocked state.

### Description

The `pthread_mutex_trylock` function is used for non-blocking attempts to acquire a mutex lock. It's useful when you want a thread to check if a mutex is available without waiting if it's currently locked by another thread. This function provides a way to avoid potential blocking, allowing threads to perform other tasks or take alternative actions if the lock is not immediately available.

### Locking the Mutex

- When a thread calls `pthread_mutex_trylock` on a mutex, the following happens:
  - If the mutex is currently unlocked (unowned), the calling thread successfully acquires the lock, and it can proceed to access the critical section.
  - If the mutex is currently locked by another thread, `pthread_mutex_trylock` returns immediately with a failure status, and the mutex remains locked.
  
### Error Handling

- `pthread_mutex_trylock` returns a non-zero error code if it fails to acquire the lock. Common error codes include `EBUSY` (mutex is already locked) and `EINVAL` (invalid mutex).

- It's essential to check the return value of `pthread_mutex_trylock` and handle the result appropriately in your code.

### Usage Example

```c
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void* arg) {
    // Attempt to acquire the lock without blocking
    int result = pthread_mutex_trylock(&my_mutex);
    
    if (result == 0) {
        // Successfully acquired the lock
        // Critical section: Access shared resources
        
        // Release the lock
        pthread_mutex_unlock(&my_mutex);
    } else if (result == EBUSY) {
        // Mutex is already locked by another thread, take alternative action
        printf("Mutex is busy, taking alternative action.\n");
    } else {
        // Handle other error conditions
        perror("pthread_mutex_trylock");
    }
    
    return NULL;
}

int main() {
    pthread_t thread_id;
    
    // Create a thread that calls thread_function
    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    return 0;
}
```

In this example:

- We declare and initialize a mutex `my_mutex` using the `PTHREAD_MUTEX_INITIALIZER` macro.

- Inside the `thread_function`, we use `pthread_mutex_trylock` to attempt to acquire the lock without blocking.

- If `pthread_mutex_trylock` returns 0, we have successfully acquired the lock and can proceed with the critical section. Afterward, we release the lock using `pthread_mutex_unlock`.

- If `pthread_mutex_trylock` returns `EBUSY`, it means the mutex is already locked by another thread, so we take an alternative action.

- We handle other error conditions using `perror` to print an error message.

- In the `main` function, we create a thread that calls `thread_function`, and we use `pthread_join` to wait for the thread to finish.

`pthread_mutex_trylock` is a valuable tool when you want to avoid blocking and need to make non-blocking attempts to acquire a mutex lock. It's commonly used in situations where you want to check if a resource is available without waiting indefinitely.
