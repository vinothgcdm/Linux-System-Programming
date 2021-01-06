#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ret;
    int which;
    int prio;
    pid_t who;

    if (argc != 4 || strchr("pug", argv[1][0]) == NULL) {
        printf("%s {p|g|u} who priority\n"
               "   set priority of: p= process; g=process group; u=process for user\n", argv[0]);
        return 1;
    }

    ret = getpriority(PRIO_PROCESS, 0);
    printf("nice value is %d\n", ret);

    /* Set nice value according to command-line arguments */
    which = (argv[1][0] == 'p') ? PRIO_PROCESS :
                (argv[1][0] == 'g') ? PRIO_PGRP : PRIO_USER;
    who = strtol(argv[2], NULL, 10);
    prio = strtol(argv[3], NULL, 10);
    //printf("which: %d, who: %d, prio: %d\n", which, who, prio);

    if (setpriority(which, who, prio) == -1) {
        perror("setpriority");
    } else {
        ret = getpriority(which, who);
        printf("new nice value is %d\n", ret);
    }

    return 0;
}
