**<div align="center" >pthread_create function</div>**

### Table of content

- [Intro To Thread attributes](#intro-to-thread-attributes)
  - [Detailed Explanations Of The Thread Attributes](#detailed-explanations-of-the-thread-attributes)
    - [1. Stack Size (`stacksize`)](#1-stack-size-stacksize)
    - [2. Scheduling Policy (`schedpolicy`)](#2-scheduling-policy-schedpolicy)
    - [3. Scheduling Priority (`schedparam`)](#3-scheduling-priority-schedparam)
    - [4. Detached State (`detachstate`)](#4-detached-state-detachstate)
    - [5. Inheritance (`inherit-sched`)](#5-inheritance-inherit-sched)
    - [6. Guard Size (`guardsize`)](#6-guard-size-guardsize)
    - [7. Scope (`scope`)](#7-scope-scope)
  - [pthread\_attr\_set\* Examples](#pthread_attr_set-examples)
- [pthread\_attr\_get\* functions](#pthread_attr_get-functions)
  - [pthread\_attr\_get\* Examples](#pthread_attr_get-examples)
  
# Intro To Thread attributes

Thread attributes, often represented by the `pthread_attr_t` structure in C programming using POSIX Threads (pthread), are settings and properties that can be applied to a thread during its creation. These attributes allow you to customize the behavior and characteristics of a thread according to the specific needs of your application. Thread attributes provide fine-grained control over various aspects of thread execution, and they include settings such as:

1. **Stack Size (`stacksize`)**: Specifies the amount of memory allocated for the thread's stack, which is used for function call frames, local variables, and other data.

2. **Scheduling Policy (`schedpolicy`)**: Determines how the thread is scheduled in relation to other threads. Common policies include FIFO, Round Robin, and the system's default scheduling policy.

3. **Scheduling Priority (`schedparam`)**: Specifies the scheduling parameters for the thread, such as its priority. Priority values are platform-specific.

4. **Detached State (`detachstate`)**: Determines whether a thread is created as detached or joinable. Detached threads release their resources automatically when they exit, while joinable threads can be waited for using `pthread_join`.

5. **Inheritance (`inherit-sched`)**: Specifies whether a new thread inherits its scheduling attributes from the parent thread or uses its own explicitly set attributes.

6. **Guard Size (`guardsize`)**: Defines the size of a guard area around the thread's stack, helping to prevent stack overflow by detecting stack access outside the allocated stack space.

7. **Scope (`scope`)**: Determines whether a thread is system-scoped (visible across multiple processes) or process-scoped (limited to the current process).

By configuring these attributes, you can optimize thread performance, resource utilization, and synchronization in multi-threaded applications. For example, you can allocate appropriate stack sizes, set scheduling priorities, choose the scheduling policy that best suits your workload, and control thread detachment and inheritance.

Thread attributes are typically used in conjunction with functions like `pthread_attr_init`, `pthread_attr_set*` (to set attribute values), and `pthread_create` (to create threads with specific attributes). Properly configuring thread attributes can lead to efficient and reliable multi-threaded applications tailored to your specific requirements.

## Detailed Explanations Of The Thread Attributes

detailed explanations of the thread attributes provided by `pthread_attr_t` along with a simple example:

### 1. Stack Size (`stacksize`)

- The `stacksize` attribute specifies the size of the thread's stack in bytes.
- It determines the amount of memory allocated for the thread's stack, used for function call frames, local variables, and data.
- You can set the stack size using the `pthread_attr_setstacksize` function.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set the stack size to 4 KB
    size_t stack_size = 4096;
    pthread_attr_setstacksize(&attr, stack_size);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example, we initialize a `pthread_attr_t` object, set a custom stack size of 4 KB using `pthread_attr_setstacksize`, and then create a new thread with this attribute.

### 2. Scheduling Policy (`schedpolicy`)

- The `schedpolicy` attribute specifies the scheduling policy for the thread.
- It determines how the thread is scheduled concerning other threads.
- Common policies include `SCHED_FIFO` (First-In, First-Out), `SCHED_RR` (Round Robin), and `SCHED_OTHER` (Default).

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set the scheduling policy to FIFO
    int policy = SCHED_FIFO;
    pthread_attr_setschedpolicy(&attr, policy);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

Here, we set the scheduling policy of the thread to FIFO using `pthread_attr_setschedpolicy` before creating the thread.

### 3. Scheduling Priority (`schedparam`)

- The `schedparam` attribute specifies scheduling parameters for the thread, including its priority.
- The meaning and range of priorities depend on the scheduling policy in use.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set the scheduling policy to FIFO
    int policy = SCHED_FIFO;
    pthread_attr_setschedpolicy(&attr, policy);

    // Set the thread's priority to 30 (custom value)
    struct sched_param param;
    param.sched_priority = 30;
    pthread_attr_setschedparam(&attr, &param);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example, we set both the scheduling policy and priority for the thread using `pthread_attr_setschedpolicy` and `pthread_attr_setschedparam`.

### 4. Detached State (`detachstate`)

- The `detachstate` attribute determines if a thread is created as detached or joinable.
- A detached thread's resources are automatically reclaimed when it exits, while a joinable thread can be waited for using `pthread_join`.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set the thread as detached
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // Create a detached thread
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // No need to clean up the attribute object for detached threads

    // The thread is automatically cleaned up when it exits

    return 0;
}
```

In this example, we set the thread as detached using `pthread_attr_setdetachstate`, and no explicit cleanup of the attribute object is needed for detached threads.

These examples demonstrate how to use some of the `pthread_attr_t` attributes when creating threads. Depending on your application's requirements, you can customize various attributes to control thread behavior effectively.

### 5. Inheritance (`inherit-sched`)

- The `inherit-sched` attribute specifies whether a new thread inherits its scheduling attributes from the parent thread.
- If set to `PTHREAD_INHERIT_SCHED`, the new thread inherits the scheduling policy and parameters from the parent thread.
- If set to `PTHREAD_EXPLICIT_SCHED`, the new thread uses its own explicitly set scheduling attributes.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set thread to inherit scheduling attributes from parent
    pthread_attr_setinheritsched(&attr, PTHREAD_INHERIT_SCHED);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example, we set the thread to inherit scheduling attributes from the parent using `pthread_attr_setinheritsched`.

### 6. Guard Size (`guardsize`)

- The `guardsize` attribute specifies the size of the guard area around the thread's stack.
- The guard area helps protect against stack overflow by detecting stack access outside the allocated stack space.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set the guard size to 4 KB
    size_t guard_size = 4096;
    pthread_attr_setguardsize(&attr, guard_size);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example, we set the guard size to 4 KB using `pthread_attr_setguardsize`.

### 7. Scope (`scope`)

- The `scope` attribute determines whether a thread is system-scoped or process-scoped.
- In system-scoped threads (`PTHREAD_SCOPE_SYSTEM`), threads are visible across multiple processes.
- In process-scoped threads (`PTHREAD_SCOPE_PROCESS`), threads are limited to the current process.

**Example**:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object
    pthread_attr_init(&attr);

    // Set thread scope to system
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example, we set the thread's scope to system using `pthread_attr_setscope`.

## pthread_attr_set* Examples

To initialize all thread attributes at one place, you can use the `pthread_attr_init` function to create an attribute object with default values and then use the attribute-setting functions to customize each attribute as needed. Here's an example of how to do this:

```c
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    // Your thread code here
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object with default values
    pthread_attr_init(&attr);

    // Set custom attribute values as needed
    size_t stack_size = 4096; // 4 KB
    pthread_attr_setstacksize(&attr, stack_size);

    int policy = SCHED_FIFO;
    pthread_attr_setschedpolicy(&attr, policy);

    int priority = 30; // Custom priority value
    struct sched_param param;
    param.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &param);

    int detach_state = PTHREAD_CREATE_DETACHED;
    pthread_attr_setdetachstate(&attr, detach_state);

    int inherit_sched = PTHREAD_INHERIT_SCHED;
    pthread_attr_setinheritsched(&attr, inherit_sched);

    size_t guard_size = 8192; // 8 KB
    pthread_attr_setguardsize(&attr, guard_size);

    int scope = PTHREAD_SCOPE_SYSTEM;
    pthread_attr_setscope(&attr, scope);

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example:

1. We first initialize the `pthread_attr_t` object `attr` using `pthread_attr_init`, which sets all attributes to their default values.

2. We then use various `pthread_attr_set*` functions to customize each attribute as needed. You can modify these lines to set the specific values you require for your application.

3. After configuring the attributes, we create a thread using `pthread_create` with the customized attribute object.

4. Finally, we clean up the attribute object using `pthread_attr_destroy` when it's no longer needed.

This approach allows you to set and customize all thread attributes in one place before creating threads with the desired attributes.

# pthread_attr_get* functions

Inside the thread function, you can access various details about the thread's attributes and state using appropriate pthread functions. Here are some common details you can retrieve from within the thread function:

1. **Thread ID**: You can obtain the ID of the current thread using `pthread_self()`.

   ```c
   pthread_t thread_id = pthread_self();
   ```

2. **Thread's Priority and Scheduling Policy**: You can query the scheduling parameters of the current thread using `pthread_getschedparam()`.

   ```c
   struct sched_param param;
   int policy;
   pthread_getschedparam(pthread_self(), &policy, &param);
   ```

   This allows you to retrieve the scheduling policy (e.g., `SCHED_FIFO`, `SCHED_RR`, `SCHED_OTHER`) and priority of the current thread.

3. **Thread's Detached State**: You can check whether the current thread is detached or joinable using `pthread_attr_getdetachstate()`.

   ```c
   int detach_state;
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_getdetachstate(&attr, &detach_state);
   ```

   This tells you whether the thread is created as detached or joinable.

4. **Thread's Stack Information**: You can access information about the thread's stack, such as its starting address and size, using `pthread_attr_getstackaddr()` and `pthread_attr_getstacksize()`.

   ```c
   void* stack_addr;
   size_t stack_size;
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_getstackaddr(&attr, &stack_addr);
   pthread_attr_getstacksize(&attr, &stack_size);
   ```

   This provides details about the thread's stack.

5. **Thread's Scope**: You can determine whether the current thread is system-scoped or process-scoped using `pthread_attr_getscope()`.

   ```c
   int scope;
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_getscope(&attr, &scope);
   ```

   This tells you whether the thread is system-scoped or process-scoped.

6. **Thread's Inheritance Attribute**: You can check whether the current thread inherits its scheduling attributes from the parent using `pthread_attr_getinheritsched()`.

   ```c
   int inherit_sched;
   pthread_attr_t attr;
   pthread_attr_init(&attr);
   pthread_attr_getinheritsched(&attr, &inherit_sched);
   ```

   This indicates whether the thread inherits scheduling attributes from its parent.

> Remember that these details are specific to the attributes and state of the current thread. You can use these functions to gather information about the thread and its configuration from within the thread function.

## pthread_attr_get* Examples

Here's an example that demonstrates how to use various `pthread_attr_get*` functions to retrieve details about the thread's attributes and state from within a single thread function:

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    // Get the thread ID
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)thread_id);

    // Get the scheduling parameters
    struct sched_param param;
    int policy;
    pthread_getschedparam(thread_id, &policy, &param);
    printf("Scheduling Policy: %s, Priority: %d\n",
           (policy == SCHED_FIFO) ? "SCHED_FIFO" :
           (policy == SCHED_RR) ? "SCHED_RR" :
           (policy == SCHED_OTHER) ? "SCHED_OTHER" : "Unknown",
           param.sched_priority);

    // Get the detached state
    int detach_state;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_getdetachstate(&attr, &detach_state);
    printf("Detached State: %s\n",
           (detach_state == PTHREAD_CREATE_DETACHED) ? "Detached" :
           (detach_state == PTHREAD_CREATE_JOINABLE) ? "Joinable" : "Unknown");

    // Get stack information
    void* stack_addr;
    size_t stack_size;
    pthread_attr_getstackaddr(&attr, &stack_addr);
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("Stack Address: %p, Stack Size: %zu bytes\n", stack_addr, stack_size);

    // Get thread scope
    int scope;
    pthread_attr_getscope(&attr, &scope);
    printf("Thread Scope: %s\n",
           (scope == PTHREAD_SCOPE_SYSTEM) ? "System" :
           (scope == PTHREAD_SCOPE_PROCESS) ? "Process" : "Unknown");

    // Get inheritance attribute
    int inherit_sched;
    pthread_attr_getinheritsched(&attr, &inherit_sched);
    printf("Inheritance Attribute: %s\n",
           (inherit_sched == PTHREAD_INHERIT_SCHED) ? "Inherit" :
           (inherit_sched == PTHREAD_EXPLICIT_SCHED) ? "Explicit" : "Unknown");

    // Sleep to keep the thread running for a while
    sleep(3);

    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object with default values
    pthread_attr_init(&attr);

    // Set custom attribute values as needed (if required)
    // ...

    // Create a thread with the specified attribute
    pthread_create(&thread_id, &attr, thread_function, NULL);

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    return 0;
}
```

In this example:

1. We create a thread using `pthread_create` with a customized attribute object `attr`, although default values are used for most attributes.

2. Inside the `thread_function`, we use various `pthread_attr_get*` functions to retrieve details about the thread's attributes and state. These details include the thread ID, scheduling parameters (policy and priority), detached state, stack information, thread scope, and inheritance attribute.

3. We also add a `sleep(3)` statement to keep the thread running for a few seconds to observe the output.

This example demonstrates how to retrieve thread attribute details within a thread function. Depending on the actual attribute values and system configuration, the output may vary.

---
