#include "CommonInclude.h"
#include "WebServer.h"
#include "Settings.h"

// Array of setting strings
static char *settingStrings[MAX_API_SETTINGS] = {
    #define ARRAY_SETTING_STRING(SETTING_ENUM, SETTING_STRING) SETTING_STRING,
    API_SETTINGS(ARRAY_SETTING_STRING)};

typedef struct
{
    int settingsValue;
    int checkFlag;
} Settings_t;

Settings_t settings = {1, 0};
Settings_t DefSettings = {0, 0};

/**
 * @brief Matches a setting name with its corresponding API_SETTINGS_e enumeration value.
 *
 * This function searches for a match between the input setting name and the predefined
 * settingStrings array, returning the corresponding API_SETTINGS_e value. The function
 * is typically used to map setting names received from external sources to an internal
 * enumeration for processing.
 *
 * @param input The setting name to be matched.
 * @return The API_SETTINGS_e enumeration value corresponding to the input setting name.
 * If no match is found, it returns MAX_API_SETTINGS, indicating that the setting name
 * is not recognized.
 *
 * @sa API_SETTINGS_e, settingStrings
 */
API_SETTINGS_e matchSetting(char *input)
{
    for (int i = 0; i < MAX_API_SETTINGS; ++i)
    {
        if (strcmp(input, settingStrings[i]) == 0)
        {
            return i;
        }
    }
    return MAX_API_SETTINGS; // Not found
}

/**
 * @brief Handles the web API request to retrieve current settings.
 *
 * This function processes the request to get the current settings and sends a response
 * back to the client socket.
 *
 * @param client_socket The client socket for communication.
 * @param payload The payload of the web API request.
 */
void handle_SETTINGS_GET(int client_socket, char *payload)
{
    printf("Handling SETTINGS_GET_DEFAULT   payload:%s\n", payload);
    char respData[100] = {0};
    int cnt = 0;
    int returnStatus = 0;
    char settingName[50];
    char settingValue[50];

    // Tokenize payload and parse values
    char *token = strtok((char *)payload, "&");
    if (token == NULL)
    {
        int idx;
        for (idx = 0, cnt = 0; idx < MAX_API_SETTINGS; idx++)
        {
            switch (idx)
            {
            case SETTINGS_VALUE:
                printf("Setting: %s, Value: %s\n", settingStrings[SETTINGS_VALUE], settingValue);
                cnt += snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[SETTINGS_VALUE], settings.settingsValue);
                break;
            case CHECK_FLAG:
                printf("Setting: %s, Value: %s\n", settingStrings[CHECK_FLAG], settingValue);
                snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[CHECK_FLAG], settings.checkFlag);
                break;
            }
        }
    }
    while (token != NULL)
    {
        // Parse setting name and value
        returnStatus = sscanf(token, "%49[^=]=%49s", settingName, settingValue);
        if ((returnStatus == 2) || (returnStatus == 1))
        {
            API_SETTINGS_e matchedSetting = matchSetting(settingName);
            // Handle different settings
            switch (matchedSetting)
            {
            case SETTINGS_VALUE:
                printf("Setting: %s, Value: %s\n", settingStrings[SETTINGS_VALUE], settingValue);
                cnt += snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[SETTINGS_VALUE], settings.settingsValue);
                break;
            case CHECK_FLAG:
                printf("Setting: %s, Value: %s\n", settingStrings[CHECK_FLAG], settingValue);
                cnt += snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[CHECK_FLAG], settings.checkFlag);
                break;
            default:
                WriteInvalidResponceToWeb(client_socket);
                printf("Unknown Setting: %s\n", settingName);
                return;
            }
        }
        else
        {
            printf("Invalid token: %s\n", token);
            WriteInvalidResponceToWeb(client_socket);
            return;
        }
        token = strtok(NULL, "&");
    }
    printf("respData: %s\n", respData);
    WriteResponceToWeb(client_socket, respData);
}

/**
 * @brief Handles the web API request to set new settings.
 *
 * This function processes the request to set new settings based on the provided payload
 * and sends a response back to the client socket.
 *
 * @param client_socket The client socket for communication.
 * @param payload The payload of the web API request.
 */
void handle_SETTINGS_SET(int client_socket, char *payload)
{
    // Implementation for SETTINGS_SET
    printf("Handling SETTINGS_SET   payload:%s\n", payload);
    char respData[100] = {0};
    int returnStatus = 0;
    char settingName[50];
    char settingValue[50];

    // Tokenize payload and parse values
    char *token = strtok((char *)payload, "&");
    if (token == NULL)
    {
        printf("Invalid Command: %s\n", payload);
        WriteInvalidResponceToWeb(client_socket);
        return;
    }
    while (token != NULL)
    {
        // Parse setting name and value
        returnStatus = sscanf(token, "%49[^=]=%49s", settingName, settingValue);
        if (returnStatus == 2)
        {
            API_SETTINGS_e matchedSetting = matchSetting(settingName);
            // Handle different settings
            switch (matchedSetting)
            {
            case SETTINGS_VALUE:
                printf("Setting: %s, Value: %s\n", settingStrings[SETTINGS_VALUE], settingValue);

                ValidationStatus_e flagValidation = validateValueRange(settingValue, 0, 1);
                if (flagValidation == VALIDATION_OK)
                {
                    settings.settingsValue = atoi(settingValue);
                }
                else
                {
                    printf("Invalid Value for %s  Error Code:%d\n", settingStrings[SETTINGS_VALUE], flagValidation);
                    WriteInvalidResponceToWeb(client_socket);
                    return;
                }
                break;

            case CHECK_FLAG:
                printf("Setting: %s, Value: %s\n", settingStrings[CHECK_FLAG], settingValue);

                ValidationStatus_e checkFlagValidation = validateValueRange(settingValue, 0, 1);
                if (checkFlagValidation == VALIDATION_OK)
                {
                    settings.checkFlag = atoi(settingValue);
                }
                else
                {
                    printf("Invalid Value for %s  Error Code:%d\n", settingStrings[CHECK_FLAG], checkFlagValidation);
                    WriteInvalidResponceToWeb(client_socket);
                    return;
                }
                break;

            default:
                WriteInvalidResponceToWeb(client_socket);
                printf("Unknown Setting: %s\n", settingName);
                return;
            }
        }
        else
        {
            printf("Invalid token: %s\n", token);
            WriteInvalidResponceToWeb(client_socket);
            return;
        }
        token = strtok(NULL, "&");
    }
    snprintf(respData, sizeof(respData), "responce-code=0");
    printf("respData: %s\n", respData);
    WriteResponceToWeb(client_socket, respData);
}

/**
 * @brief Handles the web API request to set default settings.
 *
 * This function processes the request to set default settings based on the provided payload
 * and sends a response back to the client socket.
 *
 * @param client_socket The client socket for communication.
 * @param payload The payload of the web API request.
 */
void handle_SETTINGS_SET_DEFAULT(int client_socket, char *payload)
{
    printf("Handling handle_SETTINGS_SET_DEFAULT   payload:%s\n", payload);
    char respData[100] = {0};
    int returnStatus = 0;
    char settingName[50];
    char settingValue[50];

    // Tokenize payload and parse values
    char *token = strtok((char *)payload, "&");
    if (token == NULL)
    {
        printf("Invalid Command: %s\n", payload);
        WriteInvalidResponceToWeb(client_socket);
        return;
    }
    while (token != NULL)
    {
        // Parse setting name and value
        returnStatus = sscanf(token, "%49[^=]=%49s", settingName, settingValue);
        if ( (returnStatus == 2) || (returnStatus == 1) )
        {
            API_SETTINGS_e matchedSetting = matchSetting(settingName);
            // Handle different settings
            switch (matchedSetting)
            {
            case SETTINGS_VALUE:
                    settings.settingsValue = DefSettings.settingsValue;
                break;

            case CHECK_FLAG:
                    settings.checkFlag = DefSettings.checkFlag;
                break;

            default:
                WriteInvalidResponceToWeb(client_socket);
                printf("Unknown Setting: %s\n", settingName);
                return;
            }
        }
        else
        {
            printf("Invalid token: %s\n", token);
            WriteInvalidResponceToWeb(client_socket);
            return;
        }
        token = strtok(NULL, "&");
    }
    snprintf(respData, sizeof(respData), "responce-code=0");
    printf("respData: %s\n", respData);
    WriteResponceToWeb(client_socket, respData);
}

/**
 * @brief Handles the web API request to retrieve default settings.
 *
 * This function processes the request to get the default settings and sends a response
 * back to the client socket.
 *
 * @param client_socket The client socket for communication.
 * @param payload The payload of the web API request.
 */
void handle_SETTINGS_GET_DEFAULT(int client_socket, char *payload)
{
    printf("Handling SETTINGS_GET_DEFAULT   payload:%s\n", payload);
    char respData[100] = {0};
    int cnt = 0;
    int returnStatus = 0;
    char settingName[50];
    char settingValue[50];

    // Tokenize payload and parse values
    char *token = strtok((char *)payload, "&");
    if (token == NULL)
    {
        int idx;
        for (idx = 0, cnt = 0; idx < MAX_API_SETTINGS; idx++)
        {
            switch (idx)
            {
            case SETTINGS_VALUE:
                printf("Setting: %s, Value: %s\n", settingStrings[SETTINGS_VALUE], settingValue);
                cnt += snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[SETTINGS_VALUE], DefSettings.settingsValue);
                break;
            case CHECK_FLAG:
                printf("Setting: %s, Value: %s\n", settingStrings[CHECK_FLAG], settingValue);
                snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[CHECK_FLAG], DefSettings.checkFlag);
                break;
            }
        }
    }
    while (token != NULL)
    {
        // Parse setting name and value
        returnStatus = sscanf(token, "%49[^=]=%49s", settingName, settingValue);
        if ((returnStatus == 2) || (returnStatus == 1))
        {
            API_SETTINGS_e matchedSetting = matchSetting(settingName);
            // Handle different settings
            switch (matchedSetting)
            {
            case SETTINGS_VALUE:
                printf("Setting: %s, Value: %s\n", settingStrings[SETTINGS_VALUE], settingValue);
                cnt += snprintf(respData, sizeof(respData), "%s=%d ", settingStrings[SETTINGS_VALUE], DefSettings.settingsValue);
                break;
            case CHECK_FLAG:
                printf("Setting: %s, Value: %s\n", settingStrings[CHECK_FLAG], settingValue);
                snprintf(respData + cnt, sizeof(respData), "%s=%d ", settingStrings[CHECK_FLAG], DefSettings.checkFlag);
                break;
            default:
                WriteInvalidResponceToWeb(client_socket);
                printf("Unknown Setting: %s\n", settingName);
                return;
            }
        }
        else
        {
            printf("Invalid token: %s\n", token);
            WriteInvalidResponceToWeb(client_socket);
            return;
        }
        token = strtok(NULL, "&");
    }
    printf("respData: %s\n", respData);
    WriteResponceToWeb(client_socket, respData);
}

/**
 * @brief Validates if a numeric value is within a specified range.
 *
 * This function checks if the provided string value represents a valid integer
 * within the specified range. It is commonly used for validating input values before
 * applying changes to settings.
 *
 * @param value The string representation of the numeric value to be validated.
 * @param minValue The minimum allowed value (inclusive).
 * @param maxValue The maximum allowed value (inclusive).
 * @return The validation status, which can be VALIDATION_OK if the value is within
 * the specified range, VALIDATION_OUT_OF_RANGE if it exceeds the range, or
 * VALIDATION_INVALID_FORMAT if the input is not a valid integer.
 *
 * @sa ValidationStatus_e
 */
ValidationStatus_e validateValueRange(const char *value, int minValue, int maxValue) {
    int intValue;
    if (sscanf(value, "%d", &intValue) == 1)
    {
        if (intValue < minValue || intValue > maxValue)
        {
            return VALIDATION_OUT_OF_RANGE;
        }
        else
        {
            return VALIDATION_OK;
        }
    }
    else
    {
        return VALIDATION_INVALID_FORMAT;
    }
}
