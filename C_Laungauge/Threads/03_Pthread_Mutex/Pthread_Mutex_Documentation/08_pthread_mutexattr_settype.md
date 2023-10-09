**<div align="center" >pthread_mutexattr_settype Function</div>**

#### Table of content

- [Function Signature](#function-signature)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Description](#description)
- [Mutex Types](#mutex-types)
- [Usage Example](#usage-example)

### Function Signature

```c
int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);
```

### Parameters

- `attr`: A pointer to the mutex attribute object to which you want to set the mutex type.

- `type`: An integer that specifies the mutex type. It can take one of the following values:
  - `PTHREAD_MUTEX_NORMAL`: This type of mutex allows multiple threads to lock and unlock it without any restrictions. There's no checking for deadlock avoidance or error checking.

  - `PTHREAD_MUTEX_ERRORCHECK`: This type of mutex provides error checking. If a thread attempts to relock a mutex it already holds, an error will be returned (EDEADLK). This type is useful for debugging and detecting potential deadlocks.

  - `PTHREAD_MUTEX_RECURSIVE`: This type of mutex allows a thread to relock the mutex it already holds, and it maintains a count of the number of times the mutex has been locked by the same thread. Each unlock decrements the count, and the mutex is not considered unlocked until the count reaches zero. Recursive mutexes are useful when a thread needs to lock a mutex multiple times in a nested manner.

### Return Value

- If successful, `pthread_mutexattr_settype` returns 0.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

### Description

The `pthread_mutexattr_settype` function is used to set the type of a mutex attribute object. Mutex attributes are used when initializing mutexes to configure their behavior. The type of mutex you choose determines how threads can interact with it, whether error checking is performed, and whether recursive locking is allowed.

### Mutex Types

- **PTHREAD_MUTEX_NORMAL**:
  - This is the default type if you do not explicitly set the type.
  - Multiple threads can lock and unlock this mutex without any special restrictions.
  - There's no error checking for relocking by the same thread, and it may lead to undefined behavior.

- **PTHREAD_MUTEX_ERRORCHECK**:
  - This type provides error checking.
  - If a thread attempts to relock the mutex it already holds, an error (EDEADLK) is returned.
  - Useful for debugging and detecting potential deadlocks.

- **PTHREAD_MUTEX_RECURSIVE**:
  - This type allows a thread to relock the mutex it already holds, keeping a count of the number of locks by the same thread.
  - The mutex is not considered unlocked until the count reaches zero.
  - Useful when a thread needs to lock a mutex multiple times in a nested manner.

### Usage Example

```c
#include <stdio.h>
#include <pthread.h>

int main() {
    // Declare a mutex attribute object
    pthread_mutexattr_t mutex_attr;

    // Initialize the mutex attribute object
    if (pthread_mutexattr_init(&mutex_attr) != 0) {
        perror("pthread_mutexattr_init");
        return 1;
    }

    // Set the mutex type to PTHREAD_MUTEX_ERRORCHECK
    if (pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_ERRORCHECK) != 0) {
        perror("pthread_mutexattr_settype");
        return 1;
    }

    // Declare and initialize a mutex with the configured attribute
    pthread_mutex_t my_mutex;
    if (pthread_mutex_init(&my_mutex, &mutex_attr) != 0) {
        perror("pthread_mutex_init");
        return 1;
    }

    // Use the mutex and attribute as needed

    // Destroy the mutex attribute object
    if (pthread_mutexattr_destroy(&mutex_attr) != 0) {
        perror("pthread_mutexattr_destroy");
        return 1;
    }

    return 0;
}
```

In this example:

- We declare a mutex attribute object `mutex_attr` using `pthread_mutexattr_t`.

- We initialize the mutex attribute object using `pthread_mutexattr_init`.

- We set the mutex type to `PTHREAD_MUTEX_ERRORCHECK` using `pthread_mutexattr_settype`. This enables error checking when a thread attempts to relock the mutex it already holds.

- We declare and initialize a mutex `my_mutex` using the configured attribute.

- After using the mutex and attribute as needed, we destroy the mutex attribute object using `pthread_mutexattr_destroy`.

`pthread_mutexattr_settype` is useful when you want to customize the behavior of mutexes and choose the appropriate type based on your synchronization requirements, error checking needs, and whether recursive locking is necessary.
