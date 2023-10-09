
**<div align="center" >intro to pthread_mutex</div>**

#### Table of content

- [Data Type](#data-type)
- [Functions](#functions)
  - [1. `int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);`](#1-int-pthread_mutex_initpthread_mutex_t-mutex-const-pthread_mutexattr_t-attr)
  - [2. `int pthread_mutex_destroy(pthread_mutex_t* mutex);`](#2-int-pthread_mutex_destroypthread_mutex_t-mutex)
  - [3. `int pthread_mutex_lock(pthread_mutex_t* mutex);`](#3-int-pthread_mutex_lockpthread_mutex_t-mutex)
  - [4. `int pthread_mutex_trylock(pthread_mutex_t* mutex);`](#4-int-pthread_mutex_trylockpthread_mutex_t-mutex)
  - [5. `int pthread_mutex_unlock(pthread_mutex_t* mutex);`](#5-int-pthread_mutex_unlockpthread_mutex_t-mutex)
- [Mutex Attributes](#mutex-attributes)
- [Mutex Types](#mutex-types)
- [Error Handling](#error-handling)
- [Usage Notes](#usage-notes)

The `pthread_mutex` is part of the POSIX threads (pthread) library and is used for controlling access to shared resources among multiple threads to prevent data races and ensure proper synchronization.

### Data Type

```c
typedef struct pthread_mutex_t pthread_mutex_t;
```

### Functions

#### 1. `int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);`

- **Description**: Initializes a mutex object with the attributes specified by `attr`.

- **Parameters**:
  - `mutex`: A pointer to the mutex object to be initialized.
  - `attr`: An optional pointer to the mutex attribute object. You can pass `NULL` for default attributes.

- **Return Value**:
  - Returns 0 on success.
  - Returns an error code if initialization fails.

#### 2. `int pthread_mutex_destroy(pthread_mutex_t* mutex);`

- **Description**: Destroys a mutex object, releasing any associated resources.

- **Parameters**:
  - `mutex`: A pointer to the mutex object to be destroyed.

- **Return Value**:
  - Returns 0 on success.
  - Returns an error code if destruction fails.

#### 3. `int pthread_mutex_lock(pthread_mutex_t* mutex);`

- **Description**: Locks the mutex. If the mutex is already locked by another thread, the calling thread will block until it can acquire the lock.

- **Parameters**:
  - `mutex`: A pointer to the mutex object to be locked.

- **Return Value**:
  - Returns 0 on success.
  - Returns an error code if locking fails.

#### 4. `int pthread_mutex_trylock(pthread_mutex_t* mutex);`

- **Description**: Attempts to lock the mutex. If the mutex is already locked by another thread, this function returns immediately with an error code.

- **Parameters**:
  - `mutex`: A pointer to the mutex object to be locked.

- **Return Value**:pthread_mutexattr_gettype
  - Returns 0 if the lock was acquired successfully.
  - Returns `EBUSY` if the mutex is already locked by another thread.
  - Returns an error code for other failures.

#### 5. `int pthread_mutex_unlock(pthread_mutex_t* mutex);`

- **Description**: Unlocks the mutex, allowing other threads to acquire the lock.

- **Parameters**:
  - `mutex`: A pointer to the mutex object to be unlocked.

- **Return Value**:
  - Returns 0 on success.
  - Returns an error code if unlocking fails.

### Mutex Attributes

Mutexes can have attributes that control their behavior. You can use the `pthread_mutexattr_t` type and related functions to set attributes before initializing a mutex.

- `int pthread_mutexattr_init(pthread_mutexattr_t* attr);`: Initializes a mutex attribute object.
- `int pthread_mutexattr_destroy(pthread_mutexattr_t* attr);`: Destroys a mutex attribute object.
- `int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);`: Sets the mutex type (normal, error-checking, or recursive).
- `int pthread_mutexattr_gettype(const pthread_mutexattr_t* attr, int* type);`: Retrieves the mutex type.

### Mutex Types

- **Normal Mutex (`PTHREAD_MUTEX_NORMAL`)**: This is the default type. It doesn't check for deadlock or ownership violations.

- **Error-Checking Mutex (`PTHREAD_MUTEX_ERRORCHECK`)**: It checks for deadlock and ownership violations and returns an error if detected.

- **Recursive Mutex (`PTHREAD_MUTEX_RECURSIVE`)**: Allows the same thread to lock the mutex multiple times without causing a deadlock.

### Error Handling

- Most `pthread_mutex` functions return 0 on success and an error code on failure.
- Common error codes include `EAGAIN`, `EBUSY`, `EINVAL`, and `EPERM`.
- Always check return values and handle errors appropriately in your code.

### Usage Notes

- Mutexes are often used to protect critical sections of code that must be executed by only one thread at a time.
- Deadlock can occur if threads wait for each other to release mutexes. Avoid circular dependencies.
- Recursive mutexes allow a thread to lock the same mutex multiple times, but each lock must be matched with an unlock.
- Properly destroy mutexes to release resources when they are no longer needed.

> Mutexes are essential for multi-threaded programs to ensure proper synchronization and protect shared resources from concurrent access. They play a crucial role in preventing data races and ensuring the correctness of threaded applications.
