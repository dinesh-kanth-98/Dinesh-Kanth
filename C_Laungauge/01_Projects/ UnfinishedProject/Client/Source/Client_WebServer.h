#ifndef CLIENT_WEB_SERVER_H
#define CLIENT_WEB_SERVER_H
#include "common_include.h"
#include "Client_Includes.h"

void handle_get_request(int client_socket, const char *resource, INT32 fileType);
void handle_get_data_request(int client_socket);
void* Web_Server(void *args);
VOID ExtractFunctionName(CHARPTR url, CHARPTR functionName);

// Function prototypes for command functions with a void pointer, an integer, and a character pointer parameter
void SendMessage(int client_socket, const char *request_data, void *ptr);
void UnknownFunction(void *ptr, int num, const char *str);

#endif
