**<div align="center" >pthread_mutex_init Function</div>**

#### Table of content

- [Function Signature](#function-signature)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Description](#description)
- [Mutex Attributes](#mutex-attributes)
- [Usage Example](#usage-example)
- [Error Handling](#error-handling)
- [Important Notes](#important-notes)

### Function Signature

```c
int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
```

### Parameters

- `mutex`: A pointer to the mutex object to be initialized.

- `attr`: An optional pointer to a mutex attribute object. You can pass `NULL` to use the default attributes.

### Return Value

- If successful, `pthread_mutex_init` returns 0.

- If an error occurs during initialization, it returns a non-zero error code.

### Description

The `pthread_mutex_init` function is used to initialize a mutex object with the specified attributes. A mutex is a synchronization primitive that provides mutual exclusion, allowing only one thread at a time to access the protected resource.

Mutexes can have different attributes that control their behavior. The `attr` parameter allows you to specify these attributes when initializing the mutex. If you pass `NULL` as the `attr` parameter, default attributes are used.

### Mutex Attributes

Mutex attributes define various properties of a mutex, such as its type, robustness, and process sharing. You can use the `pthread_mutexattr_t` type to create and manipulate mutex attribute objects. Here are some commonly used attributes:

- **Mutex Type**:
  - `PTHREAD_MUTEX_NORMAL`: Default type. No deadlock detection or error checking.
  - `PTHREAD_MUTEX_ERRORCHECK`: Checks for deadlock and errors.
  - `PTHREAD_MUTEX_RECURSIVE`: Allows the same thread to lock the mutex multiple times.

- **Process Sharing**:
  - `PTHREAD_PROCESS_PRIVATE`: Mutex is not shared between processes.
  - `PTHREAD_PROCESS_SHARED`: Mutex can be shared between processes.

- **Robustness**:
  - `PTHREAD_MUTEX_ROBUST`: Allows recovery from certain deadlock scenarios.

### Usage Example

```c
#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_mutex_t my_mutex;
    
    // Initialize a mutex with default attributes
    if (pthread_mutex_init(&my_mutex, NULL) != 0) {
        perror("pthread_mutex_init");
        return 1;
    }

    // Use the mutex for synchronization in your program

    // When no longer needed, destroy the mutex to release resources
    if (pthread_mutex_destroy(&my_mutex) != 0) {
        perror("pthread_mutex_destroy");
        return 1;
    }

    return 0;
}
```

In this example:

- We declare a `pthread_mutex_t` variable `my_mutex`.

- We initialize `my_mutex` using `pthread_mutex_init` with default attributes. This creates a mutex with the default type and behavior.

- We use the mutex for synchronization in the program (not shown in the example).

- When the mutex is no longer needed, we destroy it using `pthread_mutex_destroy` to release associated resources.

### Error Handling

- If `pthread_mutex_init` fails, it returns an error code that you can check to handle initialization errors.

- Common error codes include `EINVAL` (invalid attributes), `ENOMEM` (insufficient memory), and others, depending on the implementation.

- Always check the return value of `pthread_mutex_init` and handle errors appropriately in your code.

### Important Notes

- Mutexes must be initialized before use.

- You can use mutex attributes to customize the behavior of the mutex, but it's important to understand their implications.

- Proper resource management is crucial. Always destroy mutexes when they are no longer needed to prevent resource leaks.

- Mutexes should be used to protect shared resources and establish critical sections in multi-threaded programs.

- Incorrect usage of mutexes can lead to race conditions, deadlocks, and other synchronization issues, so careful design is necessary.
