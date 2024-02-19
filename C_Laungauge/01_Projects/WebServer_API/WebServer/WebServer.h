#ifndef WEBSERVER_H
#define WEBSERVER_H

/**
 * @file webserver.h
 *
 * @brief Header file for the web server functionality.
 *
 * This file declares structures, enumerations, and function prototypes related to the web server.
 */

#define PORT 8080                ///< Port number for the web server.
#define MAX_BUFFER_SIZE 1024     ///< Maximum buffer size for handling HTTP requests.

/**
 * @brief Structure to store HTTP request data.
 *
 * This structure contains fields representing various components of an HTTP request.
 */
typedef struct
{
    char method[10];             ///< HTTP request method (e.g., GET, POST).
    char path[100];              ///< Requested path in the URL.
    char protocol[20];           ///< HTTP protocol version.
    char host[50];               ///< Host specified in the request.
    char connection[20];         ///< Connection status specified in the request.
    char userAgent[100];         ///< User agent information.
    char accept[100];            ///< Content types accepted by the client.
    // Add more fields as needed
} HttpRequest;

/**
 * @brief Structure to represent parsed URL components.
 *
 * This structure contains fields for the parsed resource, action, and additional data from the URL.
 */
typedef struct
{
    char resource[50];           ///< Parsed resource from the URL.
    char action[20];             ///< Parsed action from the URL.
    char data[50];               ///< Additional data from the URL.
    // Add more fields as needed
} ParsedUrl;

#define API_REQUESTS(API)              \
    API(SETTINGS_GET, "settings") \
    API(SETTINGS_SET, "CarSettings")


/**
 * @brief Enumeration for web API requests.
 *
 * This enumeration lists the available API requests supported by the web server.
 *
 * @sa API_REQUESTS
 */
typedef enum
{
#define ENUM_API_REQUEST(API_ENUM, API_STRING) API_ENUM,
    API_REQUESTS(ENUM_API_REQUEST)
        MAX_API_REQUESTS,        ///< Sentinel value representing the maximum number of API requests.
} API_REQUESTS_e;


// Define your API actions
#define API_ACTIONS(API)                  \
    API(ACTION_GET, "get")                \
    API(ACTION_SET, "set")                \
    API(ACTION_GET_DEFAULT, "getdefault") \
    API(ACTION_SET_DEFAULT, "setdefault")

/**
 * @brief Enumeration for web API actions.
 *
 * This enumeration lists the available actions that can be performed as part of an API request.
 *
 * @sa API_ACTIONS
 */
typedef enum
{
#define ENUM_API_ACTION(ACTION_ENUM, ACTION_STRING) ACTION_ENUM,
    API_ACTIONS(ENUM_API_ACTION)
        MAX_API_ACTIONS,         ///< Sentinel value representing the maximum number of API actions.
} API_ACTIONS_e;

// Function prototypes for request handlers
void parseApiUrl(char *url, ParsedUrl *parsedUrl);
void parseHttpRequest(char *requestData, HttpRequest *httpRequest);
void handle_request(int client_socket);
void WriteResponceToWeb(int client_socket, char *respData);
void WriteInvalidResponceToWeb(int client_socket);
int main();

#endif // WEBSERVER_H

