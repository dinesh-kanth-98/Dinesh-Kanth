#include "Message_Linked_List.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// typedef struct {
//     CHAR MsgID[10];
//     CHAR MsgFrom[30];
//     CHAR Message[200];
//     CHAR MsgTo[30];
// } ClientMessageInfo_t;

// typedef struct {
//     INT8 MsgStatus;
//     CHAR MsgID[10];
//     CHAR MsgFrom[30];
//     CHAR Message[200];
//     CHAR MsgTo[30];
// } ServerResponce_t;


typedef struct {
    Node* front;
    Node* rear;
    pthread_mutex_t mutex;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Queue creation failed");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    pthread_mutex_init(&queue->mutex, NULL);
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    pthread_mutex_lock(&queue->mutex);

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    pthread_mutex_unlock(&queue->mutex);
}

int dequeue(Queue* queue) {
    pthread_mutex_lock(&queue->mutex);

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        pthread_mutex_unlock(&queue->mutex);
        return -1; // Or handle the error in your own way
    }

    Node* frontNode = queue->front;
    int data = frontNode->data;
    queue->front = frontNode->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontNode);

    pthread_mutex_unlock(&queue->mutex);

    return data;
}

void destroyQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    pthread_mutex_destroy(&queue->mutex);
    free(queue);
}

//int main() {
//    Queue* queue = createQueue();

//    // Create multiple threads to enqueue and dequeue
////    pthread_t threads[4];

////    for (int i = 0; i < 2; i++) {
////        pthread_create(&threads[i], NULL, (void*)enqueue, (void*)queue);
////        pthread_create(&threads[i + 2], NULL, (void*)dequeue, (void*)queue);
////    }

////    for (int i = 0; i < 4; i++) {
////        pthread_join(threads[i], NULL);
////    }

//    destroyQueue(queue);

//    return 0;
//}
