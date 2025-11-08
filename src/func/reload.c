#include "reload.h"
#include "../msg/info.h"
#include "../msg/log.h"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int reloading(void)
{
    waybar_reloading();
    return 0;
}

int waybar_reloading(void)
{
    FILE *result = popen("pidof waybar", "r");

    if (result == NULL)
        return 1;

    int pid;
    if (fscanf(result, "%d", &pid) != 1)
        return 2;

    pclose(result);

    if (kill(pid, SIGUSR2) == -1)
        return 1;
    
    w_info(RELOAD_SECT, INFO_RELOADING_WAYBAR);
    return 0;
}