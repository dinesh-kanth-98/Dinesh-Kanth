#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

void handle_connection(int client_socket) {
    int file_fd;
    char response_header[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    char buffer[4096];

    file_fd = open("home.html", O_RDONLY);
    if (file_fd == -1) {
        char not_found_response[] = "HTTP/1.1 404 Not Found\r\n\r\n404 Not Found";
        send(client_socket, not_found_response, strlen(not_found_response), 0);
    } else {
        send(client_socket, response_header, strlen(response_header), 0);
        int bytes_read;
        while ((bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
            send(client_socket, buffer, bytes_read, 0);
        }
        close(file_fd);
    }

    close(client_socket);
}

int main() {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address and port
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(server_socket, 5);

    printf("Server listening on port 8080...\n");

    while (1) {
        client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);

        handle_connection(client_socket);
    }

    // Close the server socket (unreachable in this example)
    close(server_socket);

    return 0;
}

int executeCommand(const char *command) {
    int returnCode = system(command);

    if (returnCode == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }

    return returnCode;
}