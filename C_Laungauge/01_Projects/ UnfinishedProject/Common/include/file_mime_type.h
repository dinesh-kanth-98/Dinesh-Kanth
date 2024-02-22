#ifndef FILE_MIME_TYPE_H
#define FILE_MIME_TYPE_H

#define FILE_MIME_TYPE_ENUM(FILE_MIME_PARA_ENUM, FILE_MIME_EXT_TYPE, FILE_CONTENT_TYPE) FILE_MIME_PARA_ENUM,
#define FILE_MIME_TYPE_NAMES(FILE_MIME_PARA_ENUM, FILE_MIME_EXT_TYPE, FILE_CONTENT_TYPE) {FILE_MIME_PARA_ENUM, FILE_MIME_EXT_TYPE, FILE_CONTENT_TYPE},

//  Define a list of supported file extensions and their corresponding content types
#define FILE_MIME_TYPE(API)                 \
    API(HTML, "html", "text/html")          \
    API(CSS, "css", "text/css")             \
    API(JS, "js", "application/javascript") \
    API(PNG, "png", "image/png")            \
    API(JPG, "jpeg", "image/jpeg")          \
    API(JSON, "json", "application/json")

typedef enum
{
    FILE_MIME_TYPE(FILE_MIME_TYPE_ENUM)
        MAX_FILE_MIME_TYPES,
} FILE_MIME_TYPE_e;

typedef struct
{
    FILE_MIME_TYPE_e num;
    const char *ext_type;
    const char *content_type;
} fileMimeTypeInfo;


#define NUMBERS_ENUM_ENTRY(FILE_MIME_PARA_ENUM) FILE_MIME_PARA_ENUM,


#endif