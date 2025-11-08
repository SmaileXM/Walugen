#include "def.h"
#include "../msg/error.h"
#include "../msg/info.h"
#include "../msg/log.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int path_check(const char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) == 0)
    {
        if (S_ISREG(path_stat.st_mode) == 0) return 2;
        if (S_ISDIR(path_stat.st_mode) == 0) return 1;
    }
    else return -1;
    return 0;
}

int program_testing(const char *prg)
{
    size_t prg_len = strlen(prg);
    size_t buf = prg_len + 25;
    char *cmd = malloc(buf);
    


    if (cmd == NULL) return 1;

    if (access(prg, F_OK) == 0) return 1;

    if (systemv("which %s > /dev/null", prg) != 0) 
    {
        w_nerror(TEST_SECT, ERROR_PROGRAM_NOT_FOUND, prg);
        return 1;
    }
    w_info(TEST_SECT, INFO_PROGRAM_FOUND, prg);
    free(cmd);
    return 0;
}

int systemv(const char *cmd, ...)
{
    size_t len = strlen(cmd);
    size_t buf = len + 40;
    char *cmd_buf = malloc(buf);

    va_list arg;
    va_start(arg, cmd);
    vsnprintf(cmd_buf, buf, cmd, arg);
    va_end(arg);

    if (system(cmd_buf) != 0)
        return 1;

    free(cmd_buf);
    return 0;
}
