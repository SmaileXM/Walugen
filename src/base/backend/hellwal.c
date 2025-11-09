#include "backends.h"
#include "../../func/def.h"
#include "../../msg/log.h"
#include "../../msg/error.h"
#include "../../msg/info.h"

#include <stdlib.h>

int hellwal_colors_update(const char *path)
{
    if (program_testing("hellwal") != 0) 
        return 1;

    if (systemv("hellwal -i \"%s\" > /dev/null", path) != 0) 
        w_error(EXIT_FAILURE, COLORS_SECT, ERROR_COLORS_UPDATE);

    w_info(COLORS_SECT, INFO_COLORS_UPDATE);
    return 0;
}

int hellwal_random_colors_update(const char *path)
{
    char *wallpaper = random_file(path);

    if (program_testing("hellwal") != 0) 
        return 1;

    if (systemv("hellwal -i \"%s\" --random > /dev/null", wallpaper) != 0) 
        w_error(EXIT_FAILURE, COLORS_SECT, ERROR_COLORS_UPDATE);

    w_info(COLORS_SECT, INFO_COLORS_UPDATE);
    free(wallpaper);
    return 0;
}