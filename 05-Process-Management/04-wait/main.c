#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t cpid;
    pid_t w;
    int wstatus;

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) { /* Code executed by child */
        printf("Child PID is %ld\n", (long)getpid());
        if (argc == 1) {
            pause(); /* Wait for signal */
        }
        _exit(atoi(argv[1]));
    } else { /* Code executed by parent */
        do {
            w = waitpid(cpid, &wstatus, WUNTRACED | WCONTINUED);
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(wstatus)) {
                printf("exited, status = %d\n", WEXITSTATUS(wstatus));
            } else if (WIFSIGNALED(wstatus)) {
                printf("killed by signal %d\n", WTERMSIG(wstatus));
            } else if (WIFSTOPPED(wstatus)) {
                printf("stopped by signal %d\n", WSTOPSIG(wstatus));
            } else if (WIFCONTINUED(wstatus)) {
                printf("continued\n");
            }
        } while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
        exit(EXIT_SUCCESS);
    }

    return 0;
}

/*
 [20:33]vinoth@Vinoth-X1 /04-wait: $ ./main &
 [2] 144
 [20:33]vinoth@Vinoth-X1 /04-wait: $ Child PID is 145

 [20:33]vinoth@Vinoth-X1 /04-wait: $ kill -STOP 145
 stopped by signal 19
 [20:33]vinoth@Vinoth-X1 /04-wait: $ kill -CONT 145
 continued
 [20:34]vinoth@Vinoth-X1 /04-wait: $ kill -TERM 145
 killed by signal 15
 */

