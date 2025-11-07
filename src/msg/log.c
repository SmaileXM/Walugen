#include "error.h"
#include "warn.h"
#include "info.h"
#include "log.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int w_error(int val, const char *mdl, const char *fmt, ...)
{
    if (val > EXIT_FAILURE)
    {
        return 1;
    }
    printf("[%sE%s] %s%s%s: ", LOG_ERROR_COLOR, NO_COLOR, LOG_ERROR_COLOR, mdl, NO_COLOR);
    va_list argl;
    va_start(argl, fmt);
    vprintf(fmt, argl);
    va_end(argl);
    exit(val);
    return 0;
}

void w_nerror(const char *mdl, const char *fmt, ...)
{
    printf("[%sE%s] %s%s%s: ", LOG_ERROR_COLOR, NO_COLOR, LOG_ERROR_COLOR, mdl, NO_COLOR);
    va_list argl;
    va_start(argl, fmt);
    vprintf(fmt, argl);
    va_end(argl);
}

void w_warn(const char *mdl, const char *fmt, ...)
{
    printf("[%sW%s] %s%s%s: ", LOG_WARN_COLOR, NO_COLOR, LOG_WARN_COLOR, mdl, NO_COLOR);
    va_list argl;
    va_start(argl, fmt);
    vprintf(fmt, argl);
    va_end(argl);
}

void w_info(const char *mdl, const char *fmt, ...)
{
    printf("[%sI%s] %s%s%s: ", LOG_INFO_COLOR, NO_COLOR, LOG_INFO_COLOR, mdl, NO_COLOR);
    va_list argl;
    va_start(argl, fmt);
    vprintf(fmt, argl);
    va_end(argl);
}

void msg(const char *type_print)
{
    if (strcmp(type_print, MSG_TYPE_HELP) == 0)
        printf(HELP_MSG);

    else if (strcmp(type_print, MSG_TYPE_USAGE) == 0)
        printf(USAGE_MSG);

    else
        printf(HELP_MSG);
}