#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    int status;
    pid_t pid;

    if (!fork()) {
        return 10;
        //abort();
    }

    pid = wait(&status);
    if (pid == -1) {
        perror("wait");
    } else {
        printf("pid = %d\n", pid);
    }

    if (WIFEXITED(status)) {
        printf("Normal termination with exit status = %d\n", WEXITSTATUS(status));
    }

    if (WIFSIGNALED(status)) {
        printf("Killed by signal = %d%s\n", WTERMSIG(status), WCOREDUMP(status) ? "(dumped core)" : "");
    }

    if (WIFSTOPPED(status)) {
        printf("Stopped by signal = %d\n", WSTOPSIG(status));
    }

    if (WIFCONTINUED(status)) {
        printf("Continued\n");
    }

    return 0;
}

/*
[16:36]gkqv83@zmy33lxcna11 /vinoth: $ gcc test.c -Wall && ./a.out
pid = 12573
Killed by signal = 6(dumped core)
[16:39]gkqv83@zmy33lxcna11 /vinoth: $ gcc test.c -Wall && ./a.out
pid = 12621
Normal termination with exit status = 10
[16:39]gkqv83@zmy33lxcna11 /vinoth: $
 */
