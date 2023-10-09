**<div align="center" >pthread_cond_destroy function</div>**

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
int pthread_cond_destroy(pthread_cond_t* cond);
```

### Parameters

- `cond`: A pointer to a `pthread_cond_t` object representing the condition variable to be destroyed.

### Return Value

- If successful, `pthread_cond_destroy` returns 0, indicating that the condition variable has been successfully destroyed.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

### Description

The `pthread_cond_destroy` function is used to destroy a condition variable previously initialized with `pthread_cond_init`. It frees any resources associated with the condition variable. It should be called when the condition variable is no longer needed to prevent resource leaks.

### Use Case

- Cleanup and deallocation of resources associated with a condition variable.

### Pitfalls

- Ensure that you call `pthread_cond_destroy` on a condition variable when it's no longer needed to prevent resource leaks.

- Do not use a condition variable after it has been destroyed. Doing so can lead to undefined behavior.

- Make sure that no threads are waiting on the condition variable when it is destroyed. If threads are still waiting, it may result in undefined behavior.

### Example

```c
#include <stdio.h>
#include <pthread.h>

int main() {
    // Declare and initialize a condition variable
    pthread_cond_t my_condition = PTHREAD_COND_INITIALIZER;

    // ... Use the condition variable as needed ...

    // Destroy the condition variable when it's no longer needed
    if (pthread_cond_destroy(&my_condition) != 0) {
        perror("pthread_cond_destroy");
        return 1;
    }

    return 0;
}
```

In this example:

- We declare and initialize a condition variable `my_condition` using `PTHREAD_COND_INITIALIZER`.

- We use the condition variable as needed within the program.

- When the condition variable is no longer needed, we call `pthread_cond_destroy` to clean up and deallocate associated resources.

`pthread_cond_destroy` is an important function for managing resources when you're finished using a condition variable in multi-threaded programs.
