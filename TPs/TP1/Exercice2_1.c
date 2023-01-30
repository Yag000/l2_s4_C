#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned n;

    printf("Entrez un entier : ");
    scanf("%u", &n);

    unsigned acc = 0;

    for (unsigned i = 1; i <= n; ++i)
    {
        acc += i * i * i;
    }

    printf("La somme des %u premiers cubes: %u\n", n, acc);

    return EXIT_SUCCESS;
}
