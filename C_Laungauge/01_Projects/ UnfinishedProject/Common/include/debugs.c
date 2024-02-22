#include "common_include.h"
#include "debugs.h"

// Define debug_counter and DEBUG_LEVEL if not already defined
static int debug_counter = 0;

void debugPrint(int level, const char *file, int line, const char *func, const char *format, ...) {
    if (level > DEBUG_LEVEL) {
        return; // Debug message level too low
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);
    char time_buffer[40];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", localtime(&tv.tv_sec));
    char ms_buffer[8];
    snprintf(ms_buffer, sizeof(ms_buffer), ".%03ld", tv.tv_usec / 1000);

    va_list args;
    va_start(args, format);

    printf("[%s%s] [DBG:%d] - [%s:%s():%d]: ", time_buffer, ms_buffer,debug_counter++, file, func, line);
    vprintf(format, args);
    printf("\n");
    printf("\n");
    va_end(args);
}

