#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h> // For memory allocation and free

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

    // Create a message string
    char *message = NULL;
    if (all_even)
    {
        message = "Main thread: All even numbers present.\n";
    }
    else if (all_odd)
    {
        message = "Main thread: All odd numbers present.\n";
    }
    else
    {
        message = "Main thread: Mix of even and odd numbers present.\n";
    }

    // Convert the message string to a dynamically allocated copy
    char *message_copy = strdup(message);

    // Return the dynamically allocated message copy
    pthread_exit(message_copy);
}

int main()
{
    pthread_t thread_id;
    int numbers[] = {2, 4, 6, 9, 10};

    // Create a thread and pass the numbers array as an argument
    if (pthread_create(&thread_id, NULL, thread_function, numbers) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish and receive the message
    char *received_message;
    if (pthread_join(thread_id, (void **)&received_message) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    // Display the received message
    printf("%s", received_message);

    // Free the dynamically allocated message copy
    free(received_message);

    return 0;
}
