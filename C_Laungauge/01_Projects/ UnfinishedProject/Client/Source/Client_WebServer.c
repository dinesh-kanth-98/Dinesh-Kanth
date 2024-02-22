#include "common_include.h"
#include "Client_WebServer.h"

#define PORT 8083
#define DOC_ROOT "/home/dinesh/Shared_Folder/Project/Common/src" // Set the root directory for your web files
#define MAX_FUNCTION_NAME 20

extern fileMimeTypeInfo fileMimeTypeInfos[MAX_FILE_MIME_TYPES];

struct FunctionMapping
{
    const char *commandString;
    void (*functionPointer)(int, const char *, void *);
    void *voidPtr; // New void pointer parameter
    int intValue;
    const char *stringValue;
};

// Define an array of command mappings
struct FunctionMapping functionMap[] = {
    {"sendMessge", SendMessage, (void *)0x12345678, 42, "HelloString"},
    {"Login", VeriftLogin, (void *)0x87654321, 77, "GoodbyeString"},
    {"userMessage", ParseAndSendMessage, (void *)0x87654321, 77, "GoodbyeString"},
};



void SendMessage(int client_socket, const char *request_data, void *ptr)
{
    DEBUG_PRINT(2, "send message got called");

    json_error_t error;
    json_t *stored_json = json_loads(request_data, 0, &error);

    if (stored_json == NULL)
    {
        const char *response = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\n\nInvalid JSON data";
        send(client_socket, response, strlen(response), 0);
        DEBUG_PRINT(2, "Failed to parse JSON: %s\n", error.text);
        return;
    }

        // Get the value associated with "key1"
        json_t *key1 = json_object_get(stored_json, "message");

        if ( key1 && json_is_string(key1))
        
        {
            // Print the value
            DEBUG_PRINT(2, "Value of 'key1': %s\n", json_string_value(key1));
        }
        else
        {
            DEBUG_PRINT(2, "'key1' is not a string or not found in JSON\n");
        }

        // Free the parsed JSON
        json_decref(stored_json);

    json_t *response_json = json_object();
        json_object_set(response_json, "status", json_integer(SUCCESS_RESPONCE_CODE));

    // json_object_set(response_json, "message", json_string("Data received and processed successfully"));
    char *response_data = json_dumps(response_json, JSON_COMPACT);
    DEBUG_PRINT(2, "response_data = %s\n", response_data);
    const char *response = "HTTP/1.1 200 OK\nContent-Type: application/json\n\n";
    send(client_socket, response, strlen(response), 0);
    send(client_socket, response_data, strlen(response_data), 0);
    free(response_data);
    json_decref(response_json);
    json_decref(stored_json);
}


void UnknownFunction(void *ptr, int num, const char *str)
{
    printf("Unknown command. Void Pointer: %p, Integer: %d, String: %s\n", ptr, num, str);
}

void handle_get_request(int client_socket, const char *resource, INT32 fileType)
{

    char content_type[25] = "text/plain"; // Default content type

    snprintf(content_type, sizeof(content_type), "%s", fileMimeTypeInfos[fileType].content_type);
    DEBUG_PRINT(2, "content_type: %s", content_type);

    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s%s", DOC_ROOT, resource);

    FILE *file = fopen(file_path, "r");
    DEBUG_PRINT(2, "file_path:%s", file_path);
    if (file != NULL)
    {
        // Serve the requested file
        char response[1024];
        snprintf(response, sizeof(response), "HTTP/1.1 200 OK\nContent-Type: %s\n\n", content_type);
        write(client_socket, response, strlen(response));

        char buffer[1024 * 1024];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0)
        {
            DEBUG_PRINT(2, "bytes_read = %ld", bytes_read);
            write(client_socket, buffer, bytes_read);
        }

        fclose(file);
    }
    else
    {
        // File not found
        char *response = "HTTP/1.1 404 \
                            Not Found\nContent-Type: text/html\n\n\
                            <h1>Not Found</h1>";
        write(client_socket, response, strlen(response));
    }
}

// Global variable to store the JSON object received from the POST request
json_t *stored_json = NULL;

void handle_get_data_request(int client_socket)
{
    if (stored_json != NULL)
    {
        // Retrieve data from the stored JSON object
        json_t *key1 = json_object_get(stored_json, "key1");
        json_t *key2 = json_object_get(stored_json, "key2");
        json_t *key3 = json_object_get(stored_json, "key3");

        if (key1 != NULL && key2 != NULL && key3 != NULL)
        {
            json_t *response_json = json_object();
            json_object_set(response_json, "key1", json_string(json_string_value(key1)));
            json_object_set(response_json, "key2", json_string(json_string_value(key2)));
            json_object_set(response_json, "key3", json_integer(json_integer_value(key3)));

            char *response_data = json_dumps(response_json, JSON_COMPACT);

            const char *response = "HTTP/1.1 200 OK\nContent-Type: application/json\n\n";
            send(client_socket, response, strlen(response), 0);
            send(client_socket, response_data, strlen(response_data), 0);
            free(response_data);
            json_decref(response_json);
        }
        else
        {
            const char *response = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\n\nInvalid JSON data format";
            send(client_socket, response, strlen(response), 0);
        }
    }
    else
    {
        const char *response = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\n\nNo data available";
        send(client_socket, response, strlen(response), 0);
    }
}

INT8 CheckRequestHasFileName(CHARPTR url)
{
    BOOL retVal = NOT_PRESENT;
    // Use basename to extract the filename
    const char *filename = basename((char *)url);
    if (strstr(filename, ".") != NULL)
    {
        // A valid filename is present
        DEBUG_PRINT(2, "Filename: %s", filename);
        char *extension = strrchr(url, '.'); // Find the file extension

        DEBUG_PRINT(2, "extention: %s", extension);
        if (extension != NULL)
        {
            extension++;
            for (int i = 0; i < MAX_FILE_MIME_TYPES; i++)
            {

                if (strcmp(fileMimeTypeInfos[i].ext_type, extension) == 0)
                {
                    DEBUG_PRINT(2, "i: %d  fileMimeTypeInfos[i].content_type:%s\n", i, fileMimeTypeInfos[i].content_type);
                    retVal = i;
                    break;
                }
            }
        }
        else if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0 || *filename == '\0')
        {
            // No valid filename found
            DEBUG_PRINT(2, "No filename in the URL");
            retVal = NOT_PRESENT;
        }
        else
        {
            retVal = NOT_PRESENT;
        }
    }
    return retVal;
}

void *Web_Server(void *args)
{
    (void)args; // Using the variable as void to suppress the warning
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    PBGRN("Web Server Started\n");
    DEBUG_PRINT(2, "Web Server listening on port %d", PORT);

    while (1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char request[1024];
        ssize_t bytes_received = recv(new_socket, request, sizeof(request), 0);
        if (bytes_received > 0)
        {
            request[bytes_received] = '\0';
        }
        DEBUG_PRINT(2, "request:%s  \nbytes_received:%zd\n\n", request, bytes_received);

        if (strstr(request, "GET") != NULL)
        {
            char *method = strtok(request, " ");
            (void)method; // Using the variable as void to suppress the warning
            char *resource = strtok(NULL, " ");

            INT8 fileType;
            if ((fileType = CheckRequestHasFileName(resource)) != NOT_PRESENT)
            {
                handle_get_request(new_socket, resource, fileType);
            }

            // DEBUG_PRINT(2, "GET resource: %s", resource);
        }
        else if (strstr(request, "POST") != NULL)
        {
            char functionName[MAX_FUNCTION_NAME];

            // snprintf(functionName, MAX_FUNCTION_NAME, "%s" ExtractFunctionName(request))
            ExtractFunctionName(request, functionName);
            DEBUG_PRINT(2, "POST functionName: %s", functionName);

            char *request_data = strstr(request, "\r\n\r\n");
            DEBUG_PRINT(2, "POST request_data: %s", request_data);

            for (int i = 0; i < sizeof(functionMap) / sizeof(functionMap[0]); i++)
            {
                DEBUG_PRINT(2, "i: %d  functionMap[i].commandString:%s", i ,functionMap[i].commandString);

                if (strcmp(functionName, functionMap[i].commandString) == 0)
                {
                    void (*selectedFunction)(int, const char *, void *) = functionMap[i].functionPointer;
                    // voidPtr = commandMap[i].voidPtr;
                    // intValue = commandMap[i].intValue;
                    // stringValue = commandMap[i].stringValue;
                    selectedFunction(new_socket, request_data + 4, NULL); // Call the selected function with parameters
                    break;
                }
            }
            // if (request_data != NULL)
            // {
            //     handle_post_request(new_socket, request_data + 4);
            // }
        }
        else
        {
            // Invalid request
            char *response = "HTTP/1.1 400 Bad Request\nContent-Type: text/html\n\n<h1>Bad Request</h1>";
            write(new_socket, response, strlen(response));
        }
        close(new_socket);
    }

    close(server_fd);
    return 0;
    //    }
}

VOID ExtractFunctionName(CHARPTR url, CHARPTR functionName)
{
    char *start = (strchr(url, '/') + 1);

    if (start != NULL)
    {
        char *end = strchr(start, '&');
        if (end != NULL)
        {
            size_t length = end - start;

            strncpy(functionName, start, length);
            functionName[length] = '\0'; // Null-terminate the string

            DEBUG_PRINT(2, "Function name: %s\n", functionName);
        }
    }
    return;
}
