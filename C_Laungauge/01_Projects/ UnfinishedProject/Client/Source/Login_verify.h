#ifndef LOGIN_VERIFY_H
#define LOGIN_VERIFY_H

#define USER_DATA_PARA_ENUM(USER_PARA_ENUM, USER_PARA_NAME) USER_PARA_ENUM,
#define USER_DATA_PARA_NAME(USER_PARA_ENUM, USER_PARA_NAME) USER_PARA_NAME,

#define USER_DATA_STRINGS(API)\
    API(USER_DATA_PASSWORD,    "password")\
    API(USER_DATA_USERNAME,     "username")\


typedef enum
{
    USER_DATA_STRINGS(USER_DATA_PARA_ENUM)
    MAX_USER_DATA,
} USER_DATA_e;
void VeriftLogin(int client_socket, const char *request_data,VOIDPTR str);

#endif
