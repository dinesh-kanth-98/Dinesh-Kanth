#include "CommonInclude.h"
#include "WebServer.h"
#include "Settings.h"

// Function pointer type
typedef void (*RequestHandler)(int, char *);
HttpRequest httpRequest;

// Array of action strings
static char *actionStrings[MAX_API_ACTIONS] = {
#define ARRAY_ACTION_STRING(ACTION_ENUM, ACTION_STRING) ACTION_STRING,
    API_ACTIONS(ARRAY_ACTION_STRING)};

// Array of API strings
static char *apiStrings[MAX_API_REQUESTS] = {
#define ARRAY_API_STRING(API_ENUM, API_STRING) API_STRING,
    API_REQUESTS(ARRAY_API_STRING)};

/**
 * @brief Matches an action string with its corresponding API_ACTIONS_e enumeration value.
 *
 * This function searches for a match between the input action string and the predefined
 * actionStrings array, returning the corresponding API_ACTIONS_e value. The function
 * is used to identify and handle specific actions in the handle_request function.
 *
 * @param input The action string to be matched.
 * @return The API_ACTIONS_e enumeration value corresponding to the input action string.
 * If no match is found, it returns MAX_API_ACTIONS, indicating that the action is not recognized.
 *
 * @sa API_ACTIONS_e, actionStrings
 */
API_ACTIONS_e matchAction(const char *input)
{
    for (int i = 0; i < MAX_API_ACTIONS; ++i)
    {
        if (strcmp(input, actionStrings[i]) == 0)
        {
            return i;
        }
    }
    return MAX_API_ACTIONS; // Not found
}

/**
 * @brief Converts an API string to its corresponding API_REQUESTS_e enumeration value.
 *
 * This function searches for a match between the input API string and the predefined
 * apiStrings array, returning the corresponding API_REQUESTS_e value. The function
 * is used to identify the requested API in the handle_request function.
 *
 * @param apiString The API string to be converted.
 * @return The API_REQUESTS_e enumeration value corresponding to the input API string.
 * If no match is found, it returns MAX_API_REQUESTS, indicating that the API is not recognized.
 *
 * @sa API_REQUESTS_e, apiStrings
 */
API_REQUESTS_e convert_string_to_api(char *apiString)
{
    for (int i = 0; i < MAX_API_REQUESTS; ++i)
    {
        if (strcmp(apiString, apiStrings[i]) == 0)
        {
            return i;
        }
    }
    return MAX_API_REQUESTS; // Not found
}

/**
 * @brief Parses the URL to extract the resource, action, and data.
 *
 * This function extracts the resource, action, and data from the URL and populates
 * the provided ParsedUrl structure. The URL is typically received in an HTTP request.
 *
 * @param url The URL to be parsed.
 * @param parsedUrl Pointer to the ParsedUrl structure to store the parsed data.
 */
void parseApiUrl(char *url, ParsedUrl *parsedUrl)
{
    // Find the position of '/' and '?'
    char *slash = strchr(url, '/');
    char *questionMark = strchr(url, '?');

    // If '/' and '?' are found, extract the resource
    if (slash != NULL && questionMark != NULL)
    {
        size_t resourceLength = questionMark - slash - 1;
        strncpy(parsedUrl->resource, slash + 1, resourceLength);
        parsedUrl->resource[resourceLength] = '\0';
    }

    // Extract the action and data from the query string
    char *actionParam = strstr(url, "action=");

    if (actionParam != NULL)
    {
        sscanf(actionParam, "action=%19[^&]", parsedUrl->action);
    }

    // Extract the remaining data
    if (questionMark != NULL)
    {
        char *ampercent = strchr(questionMark, '&');
        if (ampercent != NULL)
        {
            snprintf(parsedUrl->data, sizeof(parsedUrl->data), "%s", ampercent + 1);
        }
    }
}

/**
 * @brief Parses the HTTP request data and populates the HttpRequest structure.
 *
 * This function parses the HTTP request data and extracts relevant fields such as
 * method, path, protocol, host, connection, user agent, and accept. The parsed data
 * is stored in the provided HttpRequest structure.
 *
 * @param requestData The raw HTTP request data.
 * @param httpRequest Pointer to the HttpRequest structure to store the parsed data.
 */
void parseHttpRequest(char *requestData, HttpRequest *httpRequest)
{
    // Initialize the structure
    memset(httpRequest, 0, sizeof(HttpRequest));

    // Extract method, path, and protocol from the first line
    if (sscanf(requestData, "%9s %99s %19s\r\n", httpRequest->method, httpRequest->path, httpRequest->protocol) == 3)
    {
        // Do nothing for now
    }

    // Process each line separately
    char *line = strtok((char *)requestData, "\n");
    while (line != NULL)
    {
        // Extract other fields based on their names
        if (sscanf(line, "Host: %[^\n]", httpRequest->host) == 1)
        {
            // Do nothing for now
        }
        else if (sscanf(line, "Connection: %[^\r\n]", httpRequest->connection) == 1)
        {
            // Do nothing for now
        }
        else if (sscanf(line, "User-Agent: %[^\r\n]", httpRequest->userAgent) == 1)
        {
            // Do nothing for now
        }
        else if (sscanf(line, "Accept: %[^\r\n]", httpRequest->accept) == 1)
        {
            // Do nothing for now
        }
        // Add more conditions for additional fields as needed
        line = strtok(NULL, "\n");
    }
}

/**
 * @brief Handles the incoming HTTP request, including parsing and processing.
 *
 * This function reads the incoming HTTP request, parses it to extract relevant information,
 * and then determines the appropriate action to take based on the requested API and action.
 * The actual handling of the request is delegated to specific request handler functions.
 *
 * @param client_socket The socket for communication with the client.
 */
void handle_request(int client_socket)
{
    int invalidPara = FALSE;
    char buffer[MAX_BUFFER_SIZE] = {0};
    read(client_socket, buffer, MAX_BUFFER_SIZE - 1);
    //    printf("Received Request:\n%s\n", buffer);

    // Initialize the structure
    memset(&httpRequest, 0, sizeof(HttpRequest));
    parseHttpRequest(buffer, &httpRequest);

    // Example: Accessing parsed data
/* UnComment If Debugs are Needed */
//    printf("Received New Request:\n");
//    printf("Method: %s\n", httpRequest.method);
//    printf("Path: %s\n", httpRequest.path);
//    printf("Protocol: %s\n", httpRequest.protocol);
//    printf("Host: %s\n", httpRequest.host);
//    printf("Connection: %s\n", httpRequest.connection);
//    printf("User-Agent: %s\n", httpRequest.userAgent);
//    printf("Accept: %s\n\n", httpRequest.accept);

    ParsedUrl parsedUrl;

    // Initialize the structure
    memset(&parsedUrl, 0, sizeof(ParsedUrl));

    // Parse the URL
    parseApiUrl(httpRequest.path, &parsedUrl);

    // Example: Accessing parsed data
    printf("Resource: %s\n", parsedUrl.resource);
    printf("Action: %s\n", parsedUrl.action);
    printf("Data: %s\n", parsedUrl.data);

    API_REQUESTS_e requestedApi = convert_string_to_api(parsedUrl.resource);

    if (requestedApi < MAX_API_REQUESTS)
    {
        printf("Requested API: [%s]\n", apiStrings[requestedApi]);
    }
    else
    {
        printf("Invalid API request: [%s]\n", parsedUrl.resource);
        invalidPara = TRUE;
    }

    API_ACTIONS_e matchedAction = matchAction(parsedUrl.action);

    if (matchedAction < MAX_API_ACTIONS)
    {
        printf("Matched Action: [%s]\n", actionStrings[matchedAction]);
    }
    else
    {
        printf("Action not found: [%s]\n", parsedUrl.action);
        invalidPara = TRUE;
    }

    if (invalidPara == TRUE)
    {
        WriteInvalidResponceToWeb(client_socket);
    }
    else
    {
        // Array of function pointers
        RequestHandler requestHandlers[MAX_API_REQUESTS][MAX_API_ACTIONS] = {
            {handle_SETTINGS_GET, handle_SETTINGS_SET, handle_SETTINGS_GET_DEFAULT, handle_SETTINGS_SET_DEFAULT},
            // Add more rows for additional main indices
        };
        requestHandlers[requestedApi][matchedAction](client_socket, parsedUrl.data);
    }
    close(client_socket);
}

/**
 * @brief Writes a valid response to the client's web browser.
 *
 * This function constructs a valid HTTP response and sends it to the client's web browser.
 * The response includes a content type of "text/plain" and the provided response data.
 *
 * @param client_socket The socket for communication with the client.
 * @param respData The response data to be sent.
 */
void WriteResponceToWeb(int client_socket, char *respData)
{
    char buff[500];
    snprintf(buff, sizeof(buff), "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n%s", respData);
    write(client_socket, respData, strlen(respData));
}

/**
 * @brief Writes an invalid response to the client's web browser.
 *
 * This function constructs an invalid HTTP response and sends it to the client's web browser.
 * The response includes a content type of "text/plain" and a message indicating that the request failed
 * due to an invalid command.
 *
 * @param client_socket The socket for communication with the client.
 */
void WriteInvalidResponceToWeb(int client_socket)
{
    char response[500];
    snprintf(response, sizeof(response),
             "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nRequest Failed, Invalid Command:\"%s\"",
             httpRequest.path + 1);
    write(client_socket, response, strlen(response));
}

/**
 * @brief Main function for the web server application.
 *
 * This function initializes the server socket, binds it to the specified address and port, and listens
 * for incoming connections. Upon accepting a connection, it calls the handle_request function to process
 * the incoming HTTP request.
 */
int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    int reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR) failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1)
    {
        // Accept an incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}
