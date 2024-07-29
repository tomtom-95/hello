#include <stdlib.h>
#include <stdio.h>

int *ReturnInt(void)
{
    int x = 1;
    return &x;
}

int main(int argc, char **argv)
{
    int *y = ReturnInt();
    printf("%d", *y);
    return 0;
}