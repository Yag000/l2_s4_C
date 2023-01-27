#include <stdio.h>
#include <stdlib.h>

void fact(unsigned n);

int main()
{
    unsigned n;

    printf("Entrez un entier : ");
    scanf("%u", &n);

    fact(n);

    return EXIT_SUCCESS;
}
void fact(unsigned n)
{
    unsigned acc = 1;

    for (unsigned i = 1; i <= n; ++i)
    {
        acc *= i;
        printf("%u! = %u\n", i, acc);
    }
}
