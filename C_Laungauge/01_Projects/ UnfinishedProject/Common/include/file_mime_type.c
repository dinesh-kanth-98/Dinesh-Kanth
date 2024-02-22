// #ifndef FILE_MIME_TYPE_H
// #define FILE_MIME_TYPE_H
#include "file_mime_type.h"

extern fileMimeTypeInfo fileMimeTypeInfos[MAX_FILE_MIME_TYPES];

fileMimeTypeInfo fileMimeTypeInfos[MAX_FILE_MIME_TYPES] = {
    FILE_MIME_TYPE(FILE_MIME_TYPE_NAMES)};
// #endif