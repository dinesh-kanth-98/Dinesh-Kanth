#include "common_include.h"
#include "fileIO.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

BOOL exeCmd(const char *command)
{
    int status = system(command);

    if (status == NEGITIVE_STATUS)
    {
        perror("system");
        return FAIL; // Error executing the command
    }
    else
    {
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0)
            {
                printf("Command executed successfully.\n");
                return SUCCESS; // Command executed successfully
            }
            else
            {
                fprintf(stderr, "Command failed with exit code: %d\n", exit_status);
                return FAIL; // Command failed
            }
        }
        else
        {
            fprintf(stderr, "Command did not exit normally.\n");
            return FAIL; // Command did not exit normally
        }
    }
}

BOOL isDirExists(const char *path)
{
    struct stat directoryInfo;

    if (stat(path, &directoryInfo) == 0)
    {
        // The directory exists
        DEBUG_PRINT(1, "check dir: %d",S_ISDIR(directoryInfo.st_mode));
        return (S_ISDIR(directoryInfo.st_mode)) ? SUCCESS : FAIL;
    }

    // The directory does not exist
    return SUCCESS;
}