#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int first = atoi(argv[2]);
    int second = atoi(argv[3]);

    printf("\n%s %d * %d = %d\n\n", argv[1], first, second, first * second);

    return 0;
}