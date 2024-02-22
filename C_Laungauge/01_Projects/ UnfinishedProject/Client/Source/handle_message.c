#include "common_include.h"
#include "handle_message .h"
extern int sock;


static char *userMessageDataStrings[MAX_MESSAGE_DATA] =
    {
        USER_MESSAGE_DATA_STRINGS(USER_MESSAGE_PARA_NAME)};

typedef struct
{
    CHAR currentChatUserName[15];
    CHAR currentUserMessage[15];
} USER_MESSAGE_DATA_t;

void ParseAndSendMessage(int client_socket, const char *request_data,VOIDPTR str)
{
    json_error_t error;
    json_t *root = json_loads(request_data, 0, &error);

    if (root == NULL)
    {
        const char *response = "HTTP/1.1 400 Bad Request\nContent-Type: text/plain\n\nInvalid JSON data";
        send(client_socket, response, strlen(response), 0);
        return;
    }

    DEBUG_PRINT(2, "ParseAndSendMessage got called");

    const char *key;
    json_t *value;
    int idx, notValid = FALSE;
    USER_MESSAGE_DATA_t tempMsgData;

    json_t *response_json = json_object();
    json_object_foreach(root, key, value)
    {
        for (idx = 0; idx < MAX_MESSAGE_DATA; idx++)
        {
            if (strcmp(key, userMessageDataStrings[idx]) == 0)
            {
                break;
            }
        }
        switch (idx)
        {
        case USER_MESSAGE_DATA_NAME:
            DEBUG_PRINT(2, "USER_MESSAGE_DATA_NAME got called");
            DEBUG_PRINT(2, "%s: %s", key, json_string_value(value));
            snprintf(tempMsgData.currentUserMessage, 15, "%s", json_string_value(value));
            DEBUG_PRINT(2, "userNmae:--> %s", tempMsgData.currentUserMessage);
            break;
        case USER_MESSAGE_DATA_MESSAGE:
            DEBUG_PRINT(2, "USER_MESSAGE_DATA_MESSAGE    got called");
            DEBUG_PRINT(2, "%s: %s", key, json_string_value(value));
            snprintf(tempMsgData.currentChatUserName, 15, "%s", json_string_value(value));
            DEBUG_PRINT(2, "currentChatUserName:--> %s", tempMsgData.currentChatUserName);
            break;

        default:
            break;
        }
    }


    json_object_set(response_json, "status", json_integer(SUCCESS_RESPONCE_CODE));

    ClientMessageInfo_t message;

    // json_object_set(response_json, "message", json_string("Data received and processed successfully"));
    char *response_data = json_dumps(response_json, JSON_COMPACT);
    DEBUG_PRINT(2, "response_data = %s\n", response_data);
    const char *response = "HTTP/1.1 200 OK\nContent-Type: application/json\n\n";
    send(client_socket, response, strlen(response), 0);
    send(client_socket, response_data, strlen(response_data), 0);
    free(response_data);
    json_decref(response_json);
    json_decref(root);

        strcpy(message.MsgID, "12345");
        strcpy(message.MsgFrom, tempMsgData.currentChatUserName);
        strcpy(message.Message, tempMsgData.currentUserMessage);
        strcpy(message.MsgTo, "Dinesh Name");
        int datalen=send(sock, &message, sizeof(message), 0);
        printf("SEND datalen:%d\n", datalen);
}
