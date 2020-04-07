#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char cmd[256] = {0};
    int ret;
    char *ch;

    while (printf("cmd = "), fgets(cmd, 256, stdin) == cmd)
    {
        ch = strchr(cmd, '\n');
        if (ch)
            *ch = 0;
        printf("cmd = %s\n", cmd);
        ret = system(cmd);
        printf("system ret = 0x%x\n", ret);
    }
    return 0;
}