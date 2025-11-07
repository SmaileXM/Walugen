#include "backends.h"
#include "../../func/def.h"
#include "../../msg/log.h"
#include "../../msg/error.h"
#include "../../msg/info.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pywal_colors_update(const char *path)
{
    size_t buf = strlen(path) + 40;
    char *cmd = malloc(buf);

    if (program_testing("wal") != 0) return 1;
    
    snprintf(cmd, buf, "wal -i %s > /dev/null", path);

    if (system(cmd) != 0) w_error(EXIT_FAILURE, COLORS_SECT, ERROR_COLORS_UPDATE);

    w_info(COLORS_SECT, INFO_COLORS_UPDATE);
    free(cmd);
    return 0;
}