#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8081

void handle_get_request(int client_socket) {
    // Serve a login page upon the first GET request
    char *login_page =
        "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
        "<html><body>"
        "<h1>Login</h1>"
        "<form method=\"post\" action=\"/login\">"
        "Username: <input type=\"text\" name=\"username\"><br>"
        "Password: <input type=\"password\" name=\"password\"><br>"
        "<input type=\"submit\" value=\"Login\">"
        "</form>"
        "</body></html>";
    write(client_socket, login_page, strlen(login_page));
}

void handle_post_request(int client_socket, char *post_data) {
    // Handle the login form submission
    char *response;
    if (strstr(post_data, "username=myuser&password=mypassword") != NULL) {
        response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Login Successful</h1>";
    } else {
        response = "HTTP/1.1 401 Unauthorized\nContent-Type: text/html\n\n<h1>Login Failed</h1>";
    }
    write(client_socket, response, strlen(response));
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    int first_request = 1;

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);

        if (first_request) {
            printf("Serving login page\n");
            handle_get_request(new_socket);
            first_request = 0;
        } else {
            printf("Received request:\n%s\n", buffer);

            if (strstr(buffer, "POST /login") != NULL) {
                // Find the POST data
                char *post_data = strstr(buffer, "\r\n\r\n") + 4;
                handle_post_request(new_socket, post_data);
            } else {
                // Handle other types of requests
                char *response = "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<h1>Not Found</h1>";
                write(new_socket, response, strlen(response));
            }
        }

        close(new_socket);
    }

    return 0;
}

