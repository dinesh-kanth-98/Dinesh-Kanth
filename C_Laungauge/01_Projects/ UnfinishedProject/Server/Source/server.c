#include "common_include.h"
#include "intit_Config.h"

#define MAX_CLIENTS 5
#define PORT 8080

// Global variables
int serverSocket;
pthread_t clientThreads[MAX_CLIENTS];
pthread_mutex_t mutex;
int clientCount = 0;

void *handleClient(void *clientSocketPtr) {
    int clientSocket = *((int *)clientSocketPtr);
    char buffer[1024]="fuck you client";
    printf("thread startted\n");
    
    while (1) {
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead <= 0) {
            close(clientSocket);
            pthread_mutex_lock(&mutex);
            clientCount--;
            printf("closing client\n");
            pthread_mutex_unlock(&mutex);
            break;
        }
        printf("buf: %s\n",buffer);
        snprintf(buffer,sizeof(buffer),"%s","fuck you client");


        // Process and respond to client requests

        send(clientSocket, buffer, bytesRead, 0);
    }

    return NULL;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        printf("%c\n",c);
        // Read and discard characters until a newline or EOF is encountered
    }

}

int main() {

    InitConfig();


    int server_fd,new_socket;
    struct sockaddr_in address,clint;

    int addrlen=sizeof(clint);
    char buffer[1024];

    // creating socket file descriptor
    if((server_fd = socket(AF_INET,SOCK_STREAM,0))==0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("sock=%d\n",server_fd);

    //Forcefully attaching socket to the port 8080
    address.sin_family=AF_INET;
    address.sin_port= htons( PORT );
    address.sin_addr.s_addr=INADDR_ANY;

    int reuse = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        // Handle the error
    }


    if(bind(server_fd,(struct sockaddr *)&address,sizeof(address))<0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd,0)<0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    if ((new_socket=accept(server_fd,(struct sockaddr *)&clint,(socklen_t *)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);

    }
    int valread;
    
    int datalen = 0;
    ClientMessageInfo_t message;

    while(1)
    {
        memset(&buffer,0,sizeof(buffer));
//        fflush(stdin);
//        fflush(stdout);
        valread = read(new_socket, &message, sizeof(message));
        printf("READ  valread:%d\n",valread);
        printf("Readind Data\n\n Message ID: %s\n", message.MsgID);
        printf("Message From: %s\n", message.MsgFrom);
        printf("Message: %s\n", message.Message);
        printf("Message To: %s\n", message.MsgTo);
        sleep(1);

        memset(&buffer,0,sizeof(buffer));

        // Assign some data to the structure
        strcpy(message.MsgID, "55556");
        strcpy(message.MsgFrom, "ServerName");
        strcpy(message.Message, "Hello, this is a Server message.");
        strcpy(message.MsgTo, "Recipient Name");

        // Print the data
        printf("Writing Data\n\n Message ID: %s\n", message.MsgID);
        printf("Message From: %s\n", message.MsgFrom);
        printf("Message: %s\n", message.Message);
        printf("Message To: %s\n", message.MsgTo);


        datalen=send(new_socket, &message, sizeof(message), 0);

        sleep(1);
    }

    return 0;
}
