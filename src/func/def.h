#ifndef DEF_H
#define DEF_H

#define NULL ((void *)0)

int path_check(const char *path);
int program_testing(const char *prg);
int systemv(const char *cmd, ...);
char *random_file(const char *dir);

static char *wallpaper = NULL;

#endif