#include <stdio.h>
#include <stdlib.h>

unsigned fact(unsigned n);

int main()
{
    unsigned n;

    printf("Entrez un entier : ");
    scanf("%u", &n);

    printf("Factoriel de %u: %u\n", n, fact(n));

    return EXIT_SUCCESS;
}

unsigned fact(unsigned n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}
