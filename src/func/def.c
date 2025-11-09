#include "def.h"
#include "../msg/error.h"
#include "../msg/info.h"
#include "../msg/log.h"

#include <time.h>
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
    va_list arg;
    va_start(arg, cmd);

    va_list argc;
    va_copy(argc, arg);
    int buf = vsnprintf(NULL, 0, cmd, argc);
    va_end(argc);


    char *cmd_buf = malloc(buf + 1);
    vsnprintf(cmd_buf, buf + 1, cmd, arg);
    va_end(arg);

    if (system(cmd_buf) != 0)
        return 1;

    free(cmd_buf);
    return 0;
}

char *random_file(const char *dir)
{
    DIR *path = opendir(dir);
    char *list[1000];
    int count = 0;

    if (!dir) return NULL;

    struct dirent *entry;

    while ((entry = readdir(path)) != NULL && count < 1000)
    {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            list[count++] = strdup(entry->d_name);
        }
    }
    closedir(path);

    if (count == 0) return NULL;

    srand(time(NULL));

    int idx = rand() % count;

    size_t buffer = strlen(dir) + 1 + strlen(list[idx]) + 1;
    char *file = malloc(buffer);

    snprintf(file, buffer, "%s/%s", dir, list[idx]);
    if (wallpaper) return strdup(wallpaper);


    wallpaper = strdup(file);
    return strdup(file);
}
