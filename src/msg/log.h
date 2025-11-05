#ifndef LOG_H
#define LOG_H

#define LOG_NAME_PROG "[Walugen]:"
#define HELP_MSG "Usage: walugen [-h or --help] [-b or --backend] [-w or --wallpaper] [-i or --input] path\n"

int w_error(int val, const char *fmt);
void w_warn(const char *fmt);
void w_info(const char *fmt);

void help_msg(void);

#endif