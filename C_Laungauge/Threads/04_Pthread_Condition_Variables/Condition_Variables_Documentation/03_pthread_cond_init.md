**<div align="center" >pthread_cond_init function</div>**

### Table of content

- [`pthread_cond_init` - Initialize a Condition Variable](#pthread_cond_init---initialize-a-condition-variable)
  - [**Description:**](#description)
  - [**Function Signature:**](#function-signature)
  - [**Parameters:**](#parameters)
  - [**Return Value:**](#return-value)
  - [**Use Case:**](#use-case)
  - [**Pitfalls:**](#pitfalls)
  - [**Example:**](#example)

# `pthread_cond_init` - Initialize a Condition Variable

## **Description:**

The `pthread_cond_init` function initializes a condition variable. Condition variables are synchronization primitives used in multi-threaded programming to allow threads to wait for specific conditions to be met before proceeding. They are often used in conjunction with mutexes to coordinate threads and avoid busy-waiting.

## **Function Signature:**

```c
int pthread_cond_init(pthread_cond_t* cond, const pthread_condattr_t* attr);
```

## **Parameters:**

- `cond`: A pointer to a `pthread_cond_t` object representing the condition variable to be initialized.

- `attr`: A pointer to a `pthread_condattr_t` object representing the attributes to be associated with the condition variable. If `attr` is `NULL`, default attributes are used.

## **Return Value:**

- If successful, `pthread_cond_init` returns 0, indicating that the condition variable has been successfully initialized.

- If an error occurs, it returns a non-zero error code, indicating that the operation has failed.

## **Use Case:**

- Initialization of a condition variable before its first use.

## **Pitfalls:**

- Always ensure that you initialize the condition variable using `pthread_cond_init` before using it. Failing to initialize it can result in undefined behavior.

- Be mindful of potential resource leaks. Always call `pthread_cond_destroy` to clean up the condition variable when it's no longer needed to prevent resource leaks.

- If you don't need to set specific attributes for the condition variable, you can pass `NULL` as the `attr` parameter to use default attributes.

## **Example:**

```c
#include <stdio.h>
#include <pthread.h>

int main() {
    // Declare and initialize a condition variable
    pthread_cond_t my_condition = PTHREAD_COND_INITIALIZER;

    // Use the condition variable as needed

    // No need to explicitly call pthread_cond_init when using PTHREAD_COND_INITIALIZER

    return 0;
}
```

In this example:

- We declare and initialize a condition variable `my_condition` using `PTHREAD_COND_INITIALIZER`. This is a convenient way to initialize a condition variable with default attributes.

- We use the condition variable as needed within the program.

- We don't need to explicitly call `pthread_cond_init` when using `PTHREAD_COND_INITIALIZER`.

`pthread_cond_init` is a fundamental function for working with condition variables, and it's essential to ensure that the condition variable is properly initialized before use in multi-threaded programs.
