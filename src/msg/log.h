#ifndef LOG_H
#define LOG_H

#define LOG_NAME_PROG "[Walugen]:"
#define USAGE_MSG "Usage: walugen [-h or --help] [-b or --backend] [-w or --wallpaper] [-i or --input] path\n"

#define MSG_TYPE_HELP "help"
#define MSG_TYPE_USAGE "usage"

#define HELP_MSG    "Walugen v0.0.4 By SmaileXM\n"\
                    "\n-h,--help                           Print help"\
                    "\n-u,--usage                          Print usage"\
                    "\n-b,--backend <backend or null>      Flag for specifying the backend"\
                    "\n-w,--wallbackend <backend or null>  Flag for specifying the wallpaper backend"\
                    "\n-i,--input <path>                   Flag for specifying the path"\
                    "\n\nSource code: https://github.com/SmaileXM/Walugen.git"\
                    "\nVersion data: 2025.11.06\n"

int w_error(int val, const char *fmt, ...);
void w_nerror(const char *fmt, ...);
void w_warn(const char *fmt, ...);
void w_info(const char *fmt, ...);

void msg(const char *type_print);

#endif