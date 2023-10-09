#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Structure to hold thread results
struct ThreadResult
{
    int all_even;
    int all_odd;
};

// Function that represents the thread
void *thread_function(void *arg)
{
    int *array = (int *)arg;
    int all_even = 1;
    int all_odd = 1;

    // Check if the array contains all even or all odd numbers
    for (int i = 0; i < 5; i++)
    {
        if (array[i] % 2 == 0)
        {
            all_odd = 0; // If any even number is found, set all_odd to 0
        }
        else
        {
            all_even = 0; // If any odd number is found, set all_even to 0
        }
    }

    // Create a ThreadResult structure to store the results
    struct ThreadResult *result = (struct ThreadResult *)malloc(sizeof(struct ThreadResult));
    result->all_even = all_even;
    result->all_odd = all_odd;

    // Return the result structure
    pthread_exit(result);
}

int main()
{
    pthread_t thread_id;
    int numbers[] = {2, 4, 6, 8, 10};

    // Create a thread and pass the numbers array as an argument
    if (pthread_create(&thread_id, NULL, thread_function, numbers) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish and receive the result
    struct ThreadResult *result;
    if (pthread_join(thread_id, (void **)&result) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    // Display the message based on the result received from the thread
    if (result->all_even)
    {
        printf("Main thread: All even numbers present.\n");
    }
    else if (result->all_odd)
    {
        printf("Main thread: All odd numbers present.\n");
    }
    else
    {
        printf("Main thread: Mix of even and odd numbers present.\n");
    }

    // Free the memory allocated for the result structure
    free(result);

    return 0;
}
