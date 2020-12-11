#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void fun1(int num, void *ptr)
{
    uint32_t *p = (uint32_t *)ptr;
    printf("On Exit:[%u], num: %d\n", *p, num);
}

uint32_t exit1 = 1;
uint32_t exit2 = 2;

int main(void)
{
    on_exit(fun1, &exit1);
    on_exit(fun1, &exit2);
    printf("End main.\n");
    exit(3);
    return 0;
}

/*
[11:26]gkqv83@zmy33lxcna11 /vinoth: $ gcc test.c -Wall && ./a.out
End main.
On Exit:[2], num: 3
On Exit:[1], num: 3
 */
