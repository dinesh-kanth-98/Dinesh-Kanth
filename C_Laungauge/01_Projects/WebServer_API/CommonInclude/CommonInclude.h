#ifndef COMMONINCLUDE_H
#define COMMONINCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

/**
 * @file commoninclude.h
 *
 * @brief Common include file for shared headers and global constants.
 *
 * This file includes standard C library headers and defines commonly used constants.
 * It also declares an enumeration for validation status, which is used to provide
 * information about the result of value validation operations.
 */

#define TRUE 1   ///< Represents the boolean value for true.
#define FALSE 0  ///< Represents the boolean value for false.

/**
 * @brief Enumeration for validation status.
 *
 * This enumeration defines different validation statuses that can be used to convey
 * the result of value validation operations, such as checking if a value is within a
 * specified range or if it has a valid format.
 *
 * @sa ValidationStatus_e
 */
typedef enum {
    VALIDATION_OK,             ///< The validation was successful.
    VALIDATION_OUT_OF_RANGE,   ///< The validated value is out of the specified range.
    VALIDATION_INVALID_FORMAT  ///< The format of the validated value is invalid.
} ValidationStatus_e;

#endif // COMMONINCLUDE_H
