#include <stdio.h>
#include <stdlib.h>

void fact(unsigned n)
{
    unsigned acc = 1;

    for (unsigned i = 1; i <= n; ++i)
    {
        acc *= i;
        printf("%u! = %u\n", i, acc);
    }
}

int main()
{
    unsigned n;

    printf("Enter a number: ");
    scanf("%u", &n);

    fact(n);

    return EXIT_SUCCESS;
}