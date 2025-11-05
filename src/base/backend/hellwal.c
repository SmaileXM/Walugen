#include "backends.h"
#include "../../func/def.h"
#include "../../msg/log.h"
#include "../../msg/error.h"
#include "../../msg/info.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hellwal_colors_update(const char *path)
{
    size_t buf = strlen(path) + 50;
    char *cmd = malloc(buf);

    if (program_testing("hellwal") != 0) return 1;

    snprintf(cmd, buf, "hellwal -i %s > /dev/null", path);

    if (system(cmd) != 0) w_error(EXIT_FAILURE, ERROR_COLORS_UPDATE);

    w_info(INFO_COLORS_UPDATE);
    free(cmd);
    return 0;
}

int hellwal_random_colors_update(const char *path)
{
    size_t buf = strlen(path) + 50;
    char *cmd = malloc(buf);

    if (program_testing("hellwal") != 0) return 1;

    snprintf(cmd, buf, "hellwal -i %s --random > /dev/null", path);

    if (system(cmd) != 0) w_error(EXIT_FAILURE, ERROR_COLORS_UPDATE);

    w_info(INFO_COLORS_UPDATE);
    free(cmd);
    return 0;
}