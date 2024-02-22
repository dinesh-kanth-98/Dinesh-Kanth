#include "common_include.h"
#include "Login_verify.h"

static char *userDataStrings[MAX_USER_DATA] =
    {
        USER_DATA_STRINGS(USER_DATA_PARA_NAME)};

typedef struct
{
    CHAR userNmae[15];
    CHAR password[15];
} USER_DATA_t;

static USER_DATA_t userLoginData = {"Admin", "1234"};

void VeriftLogin(int client_socket, const char *request_data,VOIDPTR str)
{
    (void)userDataStrings;
    json_error_t error;
    json_t *root = json_loads(request_data, 0, &error);

    if (root == NULL)
    {
        const char *response = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\n\nInvalid JSON data";
        send(client_socket, response, strlen(response), 0);
        return;
    }

    DEBUG_PRINT(2, "handle_post_request got called");

    // json_t *key1 = json_object_get(root, "key1");
    // json_t *key2 = json_object_get(root, "key2");
    // json_t *key3 = json_object_get(root, "key3");

    // if (json_is_string(key1) && json_is_string(key2) && json_is_integer(key3))
    // {
    //     const char *value1 = json_string_value(key1);
    //     const char *value2 = json_string_value(key2);
    //     int value3 = json_integer_value(key3);

    //     // Now you can use value1, value2, and value3 as needed
    //     DEBUG_PRINT(2, "Value of key1: %s", value1);
    //     DEBUG_PRINT(2, "Value of key2: %s", value2);
    //     DEBUG_PRINT(2, "Value of key3: %d", value3);
    // }

    // if (key1 != NULL && key2 != NULL && key3 != NULL)
    // {
    //     json_t *response_json = json_object();
    //     json_object_set(response_json, "status", json_string("success"));
    //     json_object_set(response_json, "message", json_string("Data received and processed successfully"));
    //     char *response_data = json_dumps(response_json, JSON_COMPACT);

    //     const char *response = "HTTP/1.1 200 OK\nContent-Type: application/json\n\n";
    //     send(client_socket, response, strlen(response), 0);
    //     send(client_socket, response_data, strlen(response_data), 0);
    //     free(response_data);
    //     json_decref(response_json);
    // }
    // else
    // {
    //     const char *response = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\n\nInvalid JSON data format";
    //     send(client_socket, response, strlen(response), 0);
    // }

    const char *key;
    json_t *value;
    int idx, notValid = FALSE;
    USER_DATA_t tempLogInData;

    json_t *response_json = json_object();
    json_object_foreach(root, key, value)
    {
        for (idx = 0; idx < MAX_USER_DATA; idx++)
        {
            if (strcmp(key, userDataStrings[idx]) == 0)
            {
                break;
            }
        }
        switch (idx)
        {
        case USER_DATA_USERNAME:
            DEBUG_PRINT(2, "USER_DATA_USERNAME got called");
            DEBUG_PRINT(2, "%s: %s", key, json_string_value(value));
            snprintf(tempLogInData.userNmae, 15, "%s", json_string_value(value));
            DEBUG_PRINT(2, "userNmae:--> %s", tempLogInData.userNmae);
            if (strcmp(tempLogInData.userNmae, userLoginData.userNmae) != 0)
            {
                json_object_set(response_json, "status", json_integer(-1));
                notValid = TRUE;
                break;
            }

            /* code */
            break;
        case USER_DATA_PASSWORD:
            DEBUG_PRINT(2, "USER_DATA_PASSWORD got called");
            DEBUG_PRINT(2, "%s: %s", key, json_string_value(value));
            snprintf(tempLogInData.password, 15, "%s", json_string_value(value));
            DEBUG_PRINT(2, "password:--> %s", tempLogInData.password);
            if (strcmp(tempLogInData.password, userLoginData.password) != 0)
            {
                json_object_set(response_json, "status", json_integer(-2));
                notValid = TRUE;
                break;
            }
            break;

        default:
            break;
        }

        if (notValid == TRUE)
        {
            break;
        }
    }

    if (notValid == FALSE)
    {
        json_object_set(response_json, "status", json_integer(SUCCESS_RESPONCE_CODE));
    }

    // json_object_set(response_json, "message", json_string("Data received and processed successfully"));
    char *response_data = json_dumps(response_json, JSON_COMPACT);
    DEBUG_PRINT(2, "response_data = %s\n", response_data);
    const char *response = "HTTP/1.1 200 OK\nContent-Type: application/json\n\n";
    send(client_socket, response, strlen(response), 0);
    send(client_socket, response_data, strlen(response_data), 0);
    free(response_data);
    json_decref(response_json);
    json_decref(root);
}