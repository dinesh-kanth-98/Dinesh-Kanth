#include "common_include.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "intit_Config.h"
#include "userConfig.h"
#include "fileIO.h"

BOOL writeUserConfig(userConfig_st *userconfig)
{
    INT32 fd = INVALID_FD;
    UINT64 ret = 0;
    CHAR filePath[MAX_CMD_LEN];
    UINT8 version = USER_CONFIG_VERSION;

    snprintf(filePath, MAX_CMD_LEN, "%s%s", SERVER_FILE_SPACE, USER_CONFIG_FILE_NAME);

    fd = open(filePath, O_CREAT | O_RDWR | O_SYNC);

    if (fd == INVALID_FD)
    {
        DEBUG_PRINT(1, "Failed to open the %s with error :", filePath, errno);
        return FAIL;
    }

    ret = write(fd, (UINT8PTR)&version, sizeof(UINT8));

    if ((ret < sizeof(UINT8)) || (ret == INVALID_FD))
    {
        DEBUG_PRINT(1, "Failed to write version in  the %s with error :", filePath, errno);
        return FAIL;
    }

    ret = write(fd, (userConfig_st *)userconfig, (sizeof(userConfig_st) * MAX_USER_LIMIT));

    if ((ret < (sizeof(userConfig_st) * MAX_USER_LIMIT)) || (ret == INVALID_FD))
    {
        DEBUG_PRINT(1, "Failed to write the %s with error :", filePath, errno);
        return FAIL;
    }

    close(fd);

    return SUCCESS;
}

BOOL readUserConfig(userConfig_st *userconfig)
{
    INT32 fd = INVALID_FD;
    INT64 ret = 0;
    CHAR filePath[MAX_CMD_LEN];
    UINT8 version = USER_CONFIG_VERSION;

    if(userconfig == NULL)
    {
        return FAIL;
    }
    snprintf(filePath, MAX_CMD_LEN, "%s%s", SERVER_FILE_SPACE, USER_CONFIG_FILE_NAME);

    fd = open(filePath, O_RDONLY | O_SYNC);

    if (fd == INVALID_FD)
    {
        DEBUG_PRINT(1, "Failed to open the %s with error :", filePath, errno);
        return FAIL;
    }

    ret = read(fd, (UINT8PTR)&version, sizeof(UINT8));
    if ((ret < sizeof(UINT8)) || (ret == INVALID_FD))
    {
        DEBUG_PRINT(1, "Failed to read version in  the %s with error :", filePath, errno);
        return FAIL;
    }

    ret = read(fd, (userConfig_st *)userconfig, (sizeof(userConfig_st) * MAX_USER_LIMIT));
    if ((ret < (sizeof(userConfig_st) * MAX_USER_LIMIT)) || (ret == INVALID_FD))
    {
        DEBUG_PRINT(1, "Failed to write the %s with error :", filePath, errno);
        return FAIL;
    }

    return SUCCESS;
}

BOOL loadDefaultUserConfig()
{
    CHAR buf[MAX_CMD_LEN];
    // UINT8 version = USER_CONFIG_VERSION;

    snprintf(buf, MAX_CMD_LEN, "%s", SERVER_FILE_SPACE);

    if (isDirExists(buf))
    {
        snprintf(buf, MAX_CMD_LEN, "mkdir -p %s", SERVER_FILE_SPACE);
        if (exeCmd(buf) == FAIL)
        {
            DEBUG_PRINT(1, "FAILED TO CREATE THE DIR :%s", buf);
            exit(1);
        }

        MEMCPY(UserConfig, DefaultUserConfig, sizeof(DefaultUserConfig));
        if (writeUserConfig(UserConfig) == FAIL)
        {
            return FAIL;
        }
    }

    return SUCCESS;
}

VOID InitUserConfig()
{
    if (readUserConfig(UserConfig) == FAIL)
    {
        if (loadDefaultUserConfig() != SUCCESS)
        {
            DEBUG_PRINT(1, "Failed to Read User Config");
        }
    }
}