#ifndef BASIC_C_FUN_H
#define BASIC_C_FUN_H

#define SNPRINTF(x, size, format, ...)  snprintf(x, size,format, ...)
#define FPRINTF(fd, format, ...)        fprintf(fd, format, ...)

#define MEMCMP(s1, s2, n)               memcmp(s1, s2, n)
#define MEMCPY(d, s, n)                 memcpy(d, s, n)

#define STRNLEN(s, maxlen)              strnlen(s, maxlen)
#endif