#ifndef VAL_H
#define VAL_H

struct {
    const char *path;
    const char *backend;
    const char *wallpaper_backend;
    const char *animation;
    char *animation_cmd;
    int reload;
} Arguments;

#endif