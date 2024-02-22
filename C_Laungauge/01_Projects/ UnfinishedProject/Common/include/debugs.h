#ifndef DEBUGS_H
#define DEBUGS_H
#include <string.h>  // Include the header for strrchr
#include <stdarg.h>  // Include the header for va_list and va_start

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define DEBUG_LEVEL 2  // Define DEBUG_LEVEL as needed

#define DEBUG_PRINT(level, format, ...) debugPrint(level, __FILENAME__, __LINE__, __func__, format, ##__VA_ARGS__)

void debugPrint(int level, const char *file, int line, const char *func, const char *format, ...);

#endif