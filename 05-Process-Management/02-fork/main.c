#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid > 0) {
        printf("I am the parent of pid=%d\n", pid);
    } else if (!pid) {
        printf("I am the baby!\n");
        const char *args[] = {"figlet", "HELLO", NULL};
        int ret;

        ret = execv("/usr/bin/figlet", args);
        if (ret == -1) {
            perror("execv");
            exit(EXIT_FAILURE);
        }
    } else if (pid == -1) {
        perror("fork");
    }

    return 0;
}

/*
[21:54]vinoth@Vinoth-X1 /02-fork: $ ./main
I am the parent of pid=637
I am the baby!
[21:54]vinoth@Vinoth-X1 /02-fork: $  _   _ _____ _     _     ___
| | | | ____| |   | |   / _ \
| |_| |  _| | |   | |  | | | |
|  _  | |___| |___| |__| |_| |
|_| |_|_____|_____|_____\___/

./main
I am the parent of pid=639
I am the baby!
[21:54]vinoth@Vinoth-X1 /02-fork: $  _   _ _____ _     _     ___
| | | | ____| |   | |   / _ \
| |_| |  _| | |   | |  | | | |
|  _  | |___| |___| |__| |_| |
|_| |_|_____|_____|_____\___/

./main
I am the parent of pid=641
I am the baby!
[21:54]vinoth@Vinoth-X1 /02-fork: $  _   _ _____ _     _     ___
| | | | ____| |   | |   / _ \
| |_| |  _| | |   | |  | | | |
|  _  | |___| |___| |__| |_| |
|_| |_|_____|_____|_____\___/
 */

