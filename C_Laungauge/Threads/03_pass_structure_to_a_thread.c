#include <stdio.h>
#include <pthread.h>

typedef struct my_struct
{
    int num;
    char name[10];
} MINE_st;

void *thread_function(void *arg)
{
    MINE_st *data = (MINE_st *)arg;
    printf("Thread argument: %d \t name : %s\n", data->num, data->name);
    sleep(5);
    printf("thread is exiting\n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    int argument_value = 42;
    MINE_st empID;

    empID.num = 223;
    snprintf(empID.name, sizeof(empID.name), "%s", "dinesh");
    if (pthread_create(&thread_id, NULL, thread_function, &empID) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread_id, NULL) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    printf("Main thread finished.\n");
    return 0;
}
