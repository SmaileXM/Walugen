#ifndef WALLBACKENDS_H
#define WALLBACKENDS_H

int swww_wallpaper_update(const char *animation_type, const char *path);
int swww_random_wallpaper_update(const char *animation_type, const char *path);
int swaybg_wallpaper_update(const char *path);
int swaybg_random_wallpaper_update(const char *path);
char *swww_get_anim(const char *animation_type);

static char *type_animations[] = {
    "wave",
    "wipe", 
    "outer",
    "center",
    "simple",
};

#endif