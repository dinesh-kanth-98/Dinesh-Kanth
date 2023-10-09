**<div align="center" >pthread_mutexattr_gettype Function</div>**

#### Table of content

- [Function Signature](#function-signature)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Description](#description)
- [Mutex Types](#mutex-types)
- [Usage Example](#usage-example)

### Function Signature

```c
int pthread_mutexattr_gettype(const pthread_mutexattr_t* attr, int* type);
```

### Parameters

- `attr`: A pointer to the mutex attribute object from which you want to get the mutex type.

- `type`: A pointer to an integer where the function will store the retrieved mutex type.

### Return Value

- If successful, `pthread_mutexattr_gettype` returns 0, indicating that the mutex type has been successfully retrieved.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

### Description

The `pthread_mutexattr_gettype` function is used to retrieve the type of a mutex attribute object. Mutex attributes are used when initializing mutexes to configure their behavior. This function allows you to query the type of mutex that was previously set using `pthread_mutexattr_settype`.

### Mutex Types

- The `pthread_mutexattr_gettype` function retrieves the mutex type as an integer, which can be one of the following values:
  - `PTHREAD_MUTEX_NORMAL`: This type of mutex allows multiple threads to lock and unlock it without any restrictions. There's no checking for deadlock avoidance or error checking.

  - `PTHREAD_MUTEX_ERRORCHECK`: This type of mutex provides error checking. If a thread attempts to relock a mutex it already holds, an error (EDEADLK) will be returned.

  - `PTHREAD_MUTEX_RECURSIVE`: This type of mutex allows a thread to relock the mutex it already holds, and it maintains a count of the number of times the mutex has been locked by the same thread. Each unlock decrements the count, and the mutex is not considered unlocked until the count reaches zero.

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

    // Get the mutex type from the attribute object
    int retrieved_type;
    if (pthread_mutexattr_gettype(&mutex_attr, &retrieved_type) != 0) {
        perror("pthread_mutexattr_gettype");
        return 1;
    }

    // Print the retrieved mutex type
    printf("Retrieved Mutex Type: %d\n", retrieved_type);

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

- We set the mutex type to `PTHREAD_MUTEX_ERRORCHECK` using `pthread_mutexattr_settype`.

- We declare and initialize a mutex `my_mutex` using the configured attribute.

- We use `pthread_mutexattr_gettype` to retrieve the mutex type from the attribute object and store it in the `retrieved_type` variable.

- We print the retrieved mutex type to demonstrate how to obtain the mutex type.

- Finally, we destroy the mutex attribute object using `pthread_mutexattr_destroy`.

`pthread_mutexattr_gettype` is useful when you need to determine the type of a mutex attribute object that has been previously set, allowing you to inspect the configuration of mutexes used in your program.
