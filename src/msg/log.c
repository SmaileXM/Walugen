#include "error.h"
#include "warn.h"
#include "info.h"
#include "log.h"

#include <stdlib.h>
#include <stdio.h>

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

void help_msg(void)
{
    printf(HELP_MSG);
}