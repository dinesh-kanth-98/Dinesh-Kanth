#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void *arg)
{
    // Get the thread ID
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)thread_id);

    // Get the scheduling parameters
    struct sched_param param;
    int policy;
    pthread_getschedparam(thread_id, &policy, &param);
    printf("Scheduling Policy: %s, Priority: %d\n",
           (policy == SCHED_FIFO) ? "SCHED_FIFO" : (policy == SCHED_RR)  ? "SCHED_RR"
                                               : (policy == SCHED_OTHER) ? "SCHED_OTHER"
                                                                         : "Unknown",
           param.sched_priority);

    // Get the detached state
    int detach_state;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_getdetachstate(&attr, &detach_state);
    printf("Detached State: %s\n",
           (detach_state == PTHREAD_CREATE_DETACHED) ? "Detached" : (detach_state == PTHREAD_CREATE_JOINABLE) ? "Joinable"
                                                                                                              : "Unknown");

    // Get stack information
    void *stack_addr;
    size_t stack_size;
    pthread_attr_getstack(&attr, &stack_addr, &stack_size);
    pthread_attr_getstacksize(&attr, &stack_size);
    printf("Stack Address: %p, Stack Size: %zu bytes\n", stack_addr, stack_size);

    // Get thread scope
    int scope;
    pthread_attr_getscope(&attr, &scope);
    printf("Thread Scope: %s\n",
           (scope == PTHREAD_SCOPE_SYSTEM) ? "System" : (scope == PTHREAD_SCOPE_PROCESS) ? "Process"
                                                                                         : "Unknown");

    // Get inheritance attribute
    int inherit_sched;
    pthread_attr_getinheritsched(&attr, &inherit_sched);
    printf("Inheritance Attribute: %s\n",
           (inherit_sched == PTHREAD_INHERIT_SCHED) ? "Inherit" : (inherit_sched == PTHREAD_EXPLICIT_SCHED) ? "Explicit"
                                                                                                            : "Unknown");

    // Sleep to keep the thread running for a while
    sleep(3);

    return NULL;
}

int main()
{
    pthread_t thread_id;
    pthread_attr_t attr;

    // Initialize the attribute object with default values
    pthread_attr_init(&attr);

    printf("main called\n");

    // Set custom attribute values as needed
    size_t stack_size = 8000; // 4 KB
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
    // pthread_attr_setinheritsched(&attr, inherit_sched);

    size_t guard_size = 8192; // 8 KB
    // pthread_attr_setguardsize(&attr, guard_size);

    int scope = PTHREAD_SCOPE_SYSTEM;
    pthread_attr_setscope(&attr, scope);

    printf("thread going to called\n");

    // Create a thread with the specified attribute
    if (pthread_create(&thread_id, &attr, thread_function, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Clean up the attribute object
    pthread_attr_destroy(&attr);

    // Wait for the thread to finish (optional)
    pthread_join(thread_id, NULL);

    printf("main ended\n");
    sleep(5);

    return 0;
}