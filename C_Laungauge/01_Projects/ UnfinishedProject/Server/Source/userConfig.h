#ifndef USER_CONFIG_H
#define USER_CONFIG_H

#define SERVER_FILE_SPACE "/home/dinesh/project_X/server/"
#define USER_CONFIG_FILE_NAME "UserConfig.cfg"
#define USER_NAME_LEN 40
#define PASSWORD_LEN 40
#define MAX_USER_LIMIT 10
#define INVALID_FD -1
#define MAX_CMD_LEN 200
#define USER_CONFIG_VERSION 1
typedef struct
{
    CHAR userName[USER_NAME_LEN];
    CHAR psaaword[PASSWORD_LEN];
} userConfig_st;

userConfig_st UserConfig[MAX_USER_LIMIT];
userConfig_st DefaultUserConfig[MAX_USER_LIMIT] =
    {
        {.userName = "admin",
        .psaaword = "admin"
        }
    };

BOOL readUserConfig(userConfig_st *userconfig);
BOOL writeUserConfig(userConfig_st *userconfig);
BOOL loadDefaultUserConfig(VOID);
VOID InitUserConfig(VOID);


#endif //USER_CONFIG_H