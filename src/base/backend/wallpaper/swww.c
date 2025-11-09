#include "wallbackends.h"
#include "../../../func/def.h"
#include "../../../msg/error.h"
#include "../../../msg/warn.h"
#include "../../../msg/info.h"
#include "../../../msg/log.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swww_wallpaper_update(const char *animation, const char *path)
{
    if (program_testing("swww") != 0) 
        return 1;

    if (systemv("swww img \"%s\" %s > /dev/null", path, animation) != 0) 
        w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_WALLPAPER_UPDATE);

    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    return 0;
}

int swww_random_wallpaper_update(const char *animation, const char *path)
{
    char *wallpaper = random_file(path);

    if (program_testing("swww") != 0)
        return 1;

    if (systemv("swww img \"%s\" %s > /dev/null", wallpaper, animation) != 0) 
        w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_WALLPAPER_UPDATE);

    free(wallpaper);
    w_info(WALLPAPER_SECT, INFO_WALLPAPER_UPDATE);
    return 0;
}

char *swww_get_anim(const char *animation_type)
{
    if (!animation_type) return NULL;
    
    for (size_t i = 0; i < sizeof(type_animations)/sizeof(type_animations[0]); i++)
    {
        if (strcasecmp(type_animations[i], animation_type) == 0)
        {
            size_t buffer = strlen(animation_type) + strlen("--transition-type=") + 1;
            char *cmd_anim = malloc(buffer);
            if (!cmd_anim) return NULL;
            snprintf(cmd_anim, buffer, "--transition-type=%s", type_animations[i]);
            return cmd_anim;
        }
    }
    return NULL;
}