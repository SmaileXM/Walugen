#include "wallbackends.h"
#include "../../../func/def.h"
#include "../../../msg/error.h"
#include "../../../msg/info.h"
#include "../../../msg/log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swww_wallpaper_update(const char *path)
{
    if (program_testing("swww") != 0) 
        return 1;

    if (systemv("swww img \"%s\" > /dev/null", path) != 0) 
        w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_WALLPAPER_UPDATE);

    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    return 0;
}

int swww_random_wallpaper_update(const char *path)
{
    char *wallpaper = random_file(path);

    if (program_testing("swww") != 0)
        return 1;

    if (systemv("swww img \"%s\" > /dev/null", wallpaper) != 0)
        w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_WALLPAPER_UPDATE);

    free(wallpaper);
    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    return 0;
}