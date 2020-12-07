#include <stdio.h>
#include <stdlib.h>

void out(void)
{
    printf("atexit() succeeded!\n");
}

int main(void)
{
    if (atexit(out)) {
        printf("atexit() failed\n");
    }

    //exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}

/*
[23:00]vinoth@Vinoth-X1 /03-atexit: $ make
gcc -Wall main.c  -o main
[23:00]vinoth@Vinoth-X1 /03-atexit: $ ./main
atexit() succeeded!
 */

