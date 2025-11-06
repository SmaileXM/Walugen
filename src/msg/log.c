#include "error.h"
#include "warn.h"
#include "info.h"
#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int w_error(int val, const char *fmt)
{
    if (val > EXIT_FAILURE)
    {
        return 1;
    }
    printf("%s%s %s %s\n", LOG_ERROR_COLOR, LOG_ERROR_TXT, LOG_NAME_PROG, fmt);
    exit(val);
    return 0;
}

void w_warn(const char *fmt)
{
    printf("%s%s %s %s\n", LOG_WARN_COLOR, LOG_WARN_TXT, LOG_NAME_PROG, fmt);
}

void w_info(const char *fmt)
{
    printf("%s %s %s\n", LOG_INFO_TXT, LOG_NAME_PROG, fmt);
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