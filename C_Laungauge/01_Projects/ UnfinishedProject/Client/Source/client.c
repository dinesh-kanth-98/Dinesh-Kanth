#define PORT 8080
#include "common_include.h"
#include "client.h"
#include "Client_Includes.h"
extern int sock;
int sock;

int main()
{

    sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    pthread_t clientWebServer;

    // Create a background thread and immediately detach it
    if (pthread_create(&clientWebServer, NULL, Web_Server, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    if (pthread_detach(clientWebServer) != 0)
    {
        perror("pthread_detach");
        return 1;
    }

    //    pthread_join(clientWebServer, 0);

    //     creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        return -1;
    }

    // Set socket options
    int option = 1;

    // Reuse the address (SO_REUSEADDR)
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR) failed");
        return -1;
    }

    //    Enable TCP_NODELAY for better performance in some cases
    if (setsockopt(sock, IPPROTO_TCP, IPPROTO_TCP, &option, sizeof(option)) < 0)
    {
        perror("setsockopt(TCP_NODELAY) failed");
        return -1;
    }

    // Forcefully attaching socket to the port 8080
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //    if(inet_pton(AF_INET,"192.168.101.106",&serv_addr.sin_addr)<=0)
    //    {
    //        printf("\nInvalid address/ address not supported \n");
    //        return -1;
    //    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        return -1;
    }
    int datalen;
    (void)datalen;
    ClientMessageInfo_t message;

    while (1)
    {
        memset(&buffer, 0, sizeof(buffer));

        // Assign some data to the structure
        strcpy(message.MsgID, "12345");
        strcpy(message.MsgFrom, "SenderName");
        strcpy(message.Message, "Hello, this is a client message.");
        strcpy(message.MsgTo, "Server Name");

        // Print the data
        printf("Writing Data\n\n Message ID: %s\n", message.MsgID);
        printf("Message From: %s\n", message.MsgFrom);
        printf("Message: %s\n", message.Message);
        printf("Message To: %s\n", message.MsgTo);


                 datalen=send(sock, &message, sizeof(message), 0);
                 printf("SEND datalen:%d\n", datalen);
                 sleep(1);

                 datalen = read(sock, &message, sizeof(message));
                 printf("Data From server\n\n Message ID: %s\n", message.MsgID);
                 printf("Message From: %s\n", message.MsgFrom);
                 printf("Message: %s\n", message.Message);
                 printf("Message To: %s\n", message.MsgTo);

        sleep(100);
    }
}
