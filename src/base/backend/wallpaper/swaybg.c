#include "wallbackends.h"
#include "../../../func/def.h"
#include "../../../msg/error.h"
#include "../../../msg/info.h"
#include "../../../msg/log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swaybg_wallpaper_update(const char *path)
{
    size_t buf = strlen(path) + 50;
    char *cmd = malloc(buf);

    if (program_testing("swaybg") != 0) return 1;

    snprintf(cmd, buf, "swaybg -i %s > /dev/null", path);

    if (system(cmd) != 0) w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_COLORS_UPDATE);

    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    free(cmd);
    return 0;
}