#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned v;
    unsigned w;

    scanf("%u", &v);
    scanf("%u", &w);

    printf("v : %u\n", v);
    printf("w : %u\n", w);

    printf("Sum : %u\n", v + w);

    return EXIT_SUCCESS;
}