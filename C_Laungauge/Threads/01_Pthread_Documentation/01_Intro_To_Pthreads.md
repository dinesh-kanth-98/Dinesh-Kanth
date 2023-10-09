**<div align="center" >pthread library in C</div>**

### Table of content

- [pthread library in C](#pthread-library-in-c)
  - [**Overview**](#overview)
  - [**Header**](#header)
  - [**Data Types**](#data-types)
  - [**Functions**](#functions)
  - [**Compile with `-lpthread`**](#compile-with--lpthread)
  - [**Man Pages**](#man-pages)
  - [**Official Documentation**](#official-documentation)

# pthread library in C

The `pthread` library provides a set of functions and types for creating and managing threads in a POSIX-compliant manner. Below, I'll provide a brief overview and some commonly used functions and types. For more detailed information, you should consult the official documentation and man pages on your system.

## **Overview**

- `pthread` stands for "POSIX Threads."
- It is a standard API for creating and managing threads in a multi-threaded environment.
- The library provides functions for thread creation, synchronization, and management.

## **Header**

   To use `pthread` in your C program, include the following header:

   ```c
   #include <pthread.h>
   ```

## **Data Types**

- `pthread_t`: Represents a thread identifier.
- `pthread_attr_t`: Represents thread attributes.
- `pthread_mutex_t`: Represents a mutex (used for synchronization).
- `pthread_cond_t`: Represents a condition variable (used for synchronization).

## **Functions**

1. **pthread_create**:
   - Function: `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`
   - Description: Creates a new thread with the specified attributes, starting routine, and argument. The new thread begins execution in the `start_routine` function.

2. **pthread_join**:
   - Function: `int pthread_join(pthread_t thread, void **retval);`
   - Description: Waits for a specified thread to finish execution. It blocks the calling thread until the target thread has completed, optionally storing the target thread's exit status in `retval`.

3. **pthread_exit**:
   - Function: `void pthread_exit(void *retval);`
   - Description: Terminates the calling thread and returns a value to any thread that calls `pthread_join` on it. The thread's resources are automatically released.

4. **pthread_self**:
   - Function: `pthread_t pthread_self(void);`
   - Description: Returns the thread ID of the calling thread. It allows a thread to identify itself.

5. **pthread_cancel**:
   - Function: `int pthread_cancel(pthread_t thread);`
   - Description: Sends a cancellation request to the specified thread. The target thread may be canceled, depending on its cancellation state and type.

6. **pthread_setcancelstate**:
   - Function: `int pthread_setcancelstate(int state, int *oldstate);`
   - Description: Sets the calling thread's cancellation state to enabled or disabled. If `oldstate` is provided, the previous state is stored in `oldstate`.

7. **pthread_setcanceltype**:
   - Function: `int pthread_setcanceltype(int type, int *oldtype);`
   - Description: Sets the calling thread's cancellation type to asynchronous or deferred. If `oldtype` is provided, the previous type is stored in `oldtype`.

8. **pthread_detach**:
   - Function: `int pthread_detach(pthread_t thread);`
   - Description: Marks a thread as detached, allowing the system to automatically release its resources when it exits without the need for `pthread_join`.

9. **pthread_mutex_init**:
   - Function: `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
   - Description: Initializes a mutex with the specified attributes. Mutexes are used for thread synchronization and mutual exclusion.

10. **pthread_mutex_lock**:
    - Function: `int pthread_mutex_lock(pthread_mutex_t *mutex);`
    - Description: Locks a mutex, blocking the calling thread until the mutex becomes available. It provides mutual exclusion between threads.

11. **pthread_mutex_unlock**:
    - Function: `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
    - Description: Unlocks a previously locked mutex, allowing other threads to acquire it.

12. **pthread_cond_init**:
    - Function: `int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);`
    - Description: Initializes a condition variable with the specified attributes. Condition variables are used for thread synchronization.

13. **pthread_cond_wait**:
    - Function: `int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);`
    - Description: Releases a mutex and waits on a condition variable until signaled. It atomically unlocks the mutex and blocks the calling thread.

14. **pthread_cond_signal**:
    - Function: `int pthread_cond_signal(pthread_cond_t *cond);`
    - Description: Signals one waiting thread that is blocked on a condition variable. It wakes up a single waiting thread.

15. **pthread_cond_broadcast**:
    - Function: `int pthread_cond_broadcast(pthread_cond_t *cond);`
    - Description: Signals all waiting threads that are blocked on a condition variable. It wakes up all waiting threads.

  These pthread functions provide the foundation for creating and managing threads, as well as for synchronizing and coordinating their execution in multi-threaded applications. They are essential for concurrent programming and parallelism in C and C++ programs.

## **Compile with `-lpthread`**

   When you compile a program that uses `pthread`, you should link it with the `pthread` library using the `-lpthread` flag. For example:

   ```shell
   gcc my_program.c -o my_program -lpthread
   ```

## **Man Pages**

   You can access detailed information about each `pthread` function and data type by using the `man` command on Unix-like systems. For example, to see the manual page for `pthread_create`, you can run:

   ```shell
   man 3 pthread_create
   ```

## **Official Documentation**

- The POSIX Threads documentation is available online:
     [POSIX Threads (pthreads) - IEEE The Open Group Base Specifications Issue 7, 2018 Edition](https://pubs.opengroup.org/onlinepubs/9699919799/).

- Additionally, you may find documentation specific to your operating system (Linux, macOS, etc.) that provides further details and usage examples.

> Keep in mind that multi-threaded programming can be complex, and proper synchronization is crucial to avoid race conditions and other concurrency-related issues. Careful study of the documentation and best practices is essential when working with threads in C.
