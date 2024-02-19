#ifndef SETTINGS_H
#define SETTINGS_H

#include "CommonInclude.h"

/**
 * @file settings.h
 *
 * @brief Header file defining API settings, enumeration, and request handler prototypes.
 *
 * This file defines API settings using a macro, declares an enumeration for web API settings,
 * and provides prototypes for request handlers related to settings. It also includes a
 * function prototype for validating a value within a specified range.
 */

// Define your API settings
#define API_SETTINGS(API)                 \
    API(SETTINGS_VALUE, "settings-value") \
    API(CHECK_FLAG, "check-flag")

/**
 * @brief Enumeration for web API settings.
 *
 * This enumeration lists the available settings for the web API. The settings are defined
 * using the API_SETTINGS macro and are used to identify and handle specific settings in
 * request handlers.
 *
 * @sa API_SETTINGS
 */
typedef enum
{
#define ENUM_API_SETTING(SETTING_ENUM, SETTING_STRING) SETTING_ENUM,
    API_SETTINGS(ENUM_API_SETTING)
        MAX_API_SETTINGS, ///< Sentinel value representing the maximum number of API settings.
} API_SETTINGS_e;

// Function prototypes for request handlers
void handle_SETTINGS_GET(int client_socket, char *payload);
void handle_SETTINGS_SET(int client_socket, char *payload);
void handle_SETTINGS_SET_DEFAULT(int client_socket, char *payload);
void handle_SETTINGS_GET_DEFAULT(int client_socket, char *payload);
ValidationStatus_e validateValueRange(const char *value, int minValue, int maxValue);

#endif // SETTINGS_H

