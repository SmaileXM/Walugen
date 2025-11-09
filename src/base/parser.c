#include "../msg/log.h"
#include "../base/val.h"
#include "../msg/error.h"
#include "../msg/warn.h"
#include "../msg/info.h"
#include "../func/def.h"
#include "../func/reload.h"
#include "backend/backends.h"
#include "backend/wallpaper/wallbackends.h"
#include "parser.h"

#include <string.h>
#include <stdlib.h>

int parser(int argc, char **argv)
{
    struct Arguments;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            msg(MSG_TYPE_HELP);
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--usage") == 0)
        {
            msg(MSG_TYPE_USAGE);
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--backend") == 0)
        {
            if (i + 1 < argc)
            {
                Arguments.backend = argv[i + 1];
                i++;
            }
            else
            {
                msg(MSG_TYPE_USAGE);
                w_error(EXIT_FAILURE, COLORS_SECT ,ERROR_NO_BACKEND);
            }
        }
        else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--wallpaper") == 0)
        {
            if (i + 1 < argc)
            {
                Arguments.wallpaper_backend = argv[i + 1];
                i++;
            }
            else 
            {
                msg(MSG_TYPE_USAGE);
                w_error(EXIT_FAILURE, WALLPAPER_SECT,ERROR_NO_WALL_BACKEND);
            }
        }
        else if (strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--input") == 0)
        {
            if (i + 1 < argc)
            {
                Arguments.path = argv[i + 1];
                i++;
            }
            else 
            {
                msg(MSG_TYPE_USAGE);
                w_error(EXIT_FAILURE, INPUT_SECT, ERROR_NO_PATH);
            }
        }
        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--reload") == 0)
            Arguments.reload = 1;

        else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--animation") == 0)
        {
            Arguments.animation = argv[i + 1];
            i++;
        }
        else
        {
            msg(MSG_TYPE_USAGE);
            w_error(EXIT_FAILURE, TEST_SECT, ERROR_UNKNOWN_ARGUMENT);
        }
    }
    return 0;
}

int validation(void)
{
    struct Arguments;
    int path_testing = path_check(Arguments.path);
    char *animation = swww_get_anim(Arguments.animation);
    Arguments.animation_cmd = animation;

    if (path_testing == -1) 
        w_error(EXIT_FAILURE, TEST_SECT, ERROR_FILE_NOT_FOUND);

    if (animation == NULL)
    {
        Arguments.animation_cmd = strdup("--transition-type=simple");
        w_warn(ANIMATION_SECT, WARN_ANIMATION);
    }
    

    if (Arguments.animation == NULL)
        Arguments.animation = "simple";

    w_info(WALLPAPER_SECT, INFO_PATH_SET, Arguments.path);

    if (Arguments.backend == NULL || strcmp(Arguments.backend, "null") == 0) 
        w_warn(COLORS_SECT, WARN_IGNOR_BACKEND);

    else if (strcmp(Arguments.backend, "pywal") == 0)
    {
        if (path_testing == 1) pywal_colors_update(Arguments.path);
        else if (path_testing == 2) pywal_random_colors_update(Arguments.path);
    }
    else if (strcmp(Arguments.backend, "hellwal") == 0)
    {
        if (path_testing == 1) hellwal_colors_update(Arguments.path);
        else if (path_testing == 2) hellwal_random_colors_update(Arguments.path);
    }
    else w_error(EXIT_FAILURE, COLORS_SECT, ERROR_UNKNOWN_BACKEND);

    if (Arguments.wallpaper_backend == NULL || strcmp(Arguments.wallpaper_backend, "null") == 0) 
        w_warn(WALLPAPER_SECT, WARN_IGNOR_WALLPAPER_BACKEND);

    else if (strcmp(Arguments.wallpaper_backend, "swww") == 0)
    {
        if (path_testing == 1)
        {
            swww_wallpaper_update(Arguments.animation_cmd, Arguments.path);
        }
        else if (path_testing == 2)
        {
            swww_random_wallpaper_update(Arguments.animation_cmd, Arguments.path);
        }
    }
    else if (strcmp(Arguments.wallpaper_backend, "swaybg") == 0)
    {
        if (path_testing == 1)
        {
            swaybg_wallpaper_update(Arguments.path);
        }
        else if (path_testing == 2)
        {
            swaybg_random_wallpaper_update(Arguments.path);
        }
    }
    else w_error(EXIT_FAILURE, WALLPAPER_SECT, ERROR_UNKNOWN_WALLPAPER_BACKEND);

    if (Arguments.reload == 1)
        reloading();
    
    free(Arguments.animation_cmd);
    return 0;
}

