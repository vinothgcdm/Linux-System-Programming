#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    printf("My pid = %d\n", getpid());
    printf("Parent's pid = %d\n", getppid());
    return 0;
}

/*
 [21:29]vinoth@Vinoth-X1 /01-optaining-pid-ppid: $ make
 gcc -Wall main.c  -o main
 [21:29]vinoth@Vinoth-X1 /01-optaining-pid-ppid: $ ./main
 My pid = 246
 Parent's pid = 117
 [21:29]vinoth@Vinoth-X1 /01-optaining-pid-ppid: $ ./main
 My pid = 247
 Parent's pid = 117
 [21:29]vinoth@Vinoth-X1 /01-optaining-pid-ppid: $ ./main
 My pid = 248
 Parent's pid = 117
 [21:29]vinoth@Vinoth-X1 /01-optaining-pid-ppid: $ ./main
 My pid = 249
 Parent's pid = 117
 [21:29]vinoth@Vinoth-X1 /01-optaining-pid-ppid: $ ./main
 My pid = 250
 Parent's pid = 117
*/

