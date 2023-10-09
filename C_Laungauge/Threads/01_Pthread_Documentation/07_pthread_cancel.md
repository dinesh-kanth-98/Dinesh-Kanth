**<div align="center" >pthread_cancel function</div>**

### Table of content

- [Function Signature](#function-signature)
- [Description](#description)
- [Parameters](#parameters)
- [Return Value](#return-value)
- [Thread Cancellation State](#thread-cancellation-state)
- [Thread Termination](#thread-termination)
- [Example](#example)
- [thread cancellation states](#thread-cancellation-states)
  - [1. Enabled Cancellation State](#1-enabled-cancellation-state)
  - [2. Disabled Cancellation State](#2-disabled-cancellation-state)
  - [3. Deferred Cancellation State](#3-deferred-cancellation-state)

## Function Signature

```c
#include <pthread.h>

int pthread_cancel(pthread_t thread);
```

## Description

The `pthread_cancel` function is used to request the cancellation of a specified thread. Thread cancellation is a mechanism by which one thread (the "cancelling thread") requests the termination of another thread (the "target thread"). The target thread can be terminated either immediately or at a specific cancellation point, depending on its cancellation state.

## Parameters

- `thread`: The thread ID (pthread_t) of the target thread that you want to cancel.

## Return Value

The `pthread_cancel` function returns one of the following values:

- `0` (zero) if the cancellation request was successfully sent to the target thread.
- An error code (a positive integer) if an error occurred while sending the cancellation request.

## Thread Cancellation State

A thread's cancellation state determines how it responds to cancellation requests. Threads can have one of the following cancellation states:

- **Enabled**: The thread will respond to cancellation requests by terminating.
- **Disabled**: The thread will not respond to cancellation requests until cancellation is re-enabled.
- **Deferred**: The thread will respond to cancellation requests only at specific cancellation points (e.g., when it calls certain functions like `pthread_join`).

The cancellation state of a thread can be set using `pthread_setcancelstate` and retrieved using `pthread_setcancelstate`.

## Thread Termination

When a thread is canceled, it typically terminates. The exact behavior depends on the thread's cancellation state:

- If the cancellation state is **Enabled**, the thread will terminate immediately upon receiving the cancellation request.
- If the cancellation state is **Deferred**, the thread will continue executing until it reaches a cancellation point. At the cancellation point, it will check for a pending cancellation request and terminate if one exists.
- If the cancellation state is **Disabled**, the thread will not terminate in response to a cancellation request until the cancellation state is re-enabled.

## Example

Here's a simple example that demonstrates the use of `pthread_cancel` to request the cancellation of a thread:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    while (1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Sleep for a while to allow the thread to run
    sleep(3);

    // Request cancellation of the thread
    if (pthread_cancel(thread_id) != 0) {
        perror("pthread_cancel");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread finished.\n");
    return 0;
}
```

In this example:

- The `thread_function` runs in a loop, printing a message every second.
- The main thread creates the new thread and waits for a few seconds to allow the new thread to run.
- The main thread then requests the cancellation of the new thread using `pthread_cancel`.
- The new thread checks for a cancellation request at the next cancellation point (which includes the `sleep` function), terminates, and the main thread waits for it to finish using `pthread_join`.

This demonstrates how `pthread_cancel` can be used to request the cancellation of a thread, but it's important to consider the thread's cancellation state and use it cautiously to avoid resource leaks or unexpected behavior.

## thread cancellation states

The thread cancellation state determines how a thread responds to cancellation requests made by other threads. Threads can be in one of three cancellation states: **Enabled**, **Disabled**, or **Deferred**. Let's explore each state in detail with proper examples.

### 1. Enabled Cancellation State

In this state, a thread is immediately terminated when it receives a cancellation request. This means that the thread can be canceled at any point in its execution, and it will not complete its current tasks.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    while (1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Sleep for a while to allow the thread to run
    sleep(3);

    // Request cancellation of the thread
    if (pthread_cancel(thread_id) != 0) {
        perror("pthread_cancel");
        return 1;
    }

    // The thread will be terminated immediately
    printf("Main thread finished.\n");
    return 0;
}
```

In this example, the `thread_function` runs in a loop, printing a message every second. The main thread creates the new thread and requests its immediate cancellation using `pthread_cancel`. As a result, the new thread is terminated immediately, and the main thread proceeds.

### 2. Disabled Cancellation State

In this state, a thread ignores any cancellation requests until its cancellation state is re-enabled. The thread will not terminate in response to cancellation requests.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    // Set cancellation state to Disabled
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

    while (1) {
        printf("Thread is running...\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Sleep for a while to allow the thread to run
    sleep(5);

    print("awake from sleep\n");

    // Request cancellation of the thread (ignored in Disabled state)
    if (pthread_cancel(thread_id) != 0) {
        perror("pthread_cancel");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread finished.\n");
    return 0;
}
```

In this example, the `thread_function` initially sets its cancellation state to Disabled using `pthread_setcancelstate`. This means that cancellation requests are ignored. Later, in the main thread, the cancellation state for the new thread is re-enabled using `pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL)`. The new thread terminates only after its cancellation state is re-enabled.

### 3. Deferred Cancellation State

In this state, a thread will only respond to cancellation requests at specific cancellation points, such as when it calls certain functions like `pthread_join` or `sleep`. It continues executing until it reaches a cancellation point, where it checks for pending cancellation requests and terminates if one exists.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    // Set cancellation state to Deferred
    pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL);

    while (1) {
        printf("Thread is running...\n");
        sleep(1);  // A cancellation point
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Sleep for a while to allow the thread to run
    sleep(3);

    // Request cancellation of the thread (deferred until the next cancellation point)
    if (pthread_cancel(thread_id) != 0) {
        perror("pthread_cancel");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread finished.\n");
    return 0;
}
```

In this example, the `thread_function` initially sets its cancellation state to Deferred using `pthread_setcancelstate`. It continues running until it reaches a cancellation point (in this case, the `sleep` function), where it checks for pending cancellation requests and terminates if one exists. The cancellation request is processed at the next cancellation point.

>These examples demonstrate the three cancellation states and how they affect a thread's response to cancellation requests. The choice of cancellation state depends on the specific requirements of your multi-threaded program and how you want threads to handle cancellations.
