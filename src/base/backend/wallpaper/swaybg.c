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
    if (program_testing("swaybg") != 0) 
        return 1;

    if (systemv("swaybg -i \"%s\" > /dev/null", path) != 0) 
        w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_WALLPAPER_UPDATE);

    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    return 0;
}

int swaybg_random_wallpaper_update(const char *path)
{
    char *wallpaper = random_file(path);

    if (program_testing("swaybg") != 0)
        return 1;

    if (systemv("swaybg -i \"%s\" > /dev/null", wallpaper) != 0)
        w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_WALLPAPER_UPDATE);

    free(wallpaper);
    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    return 0;
}