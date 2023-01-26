#include <stdio.h>
#include <stdlib.h>

#define N 27

unsigned syracuse(unsigned n)
{
    // printf("%u ", n); Exercice 3.1

    if (n == 1)
    {
        return 0;
    }

    if (n % 2 == 0)
    {
        return 1 + syracuse(n / 2);
    }

    return 1 + syracuse(3 * n + 1);
}

int main()
{

    // printf("%u : %u", N, syracuse(N)); Exercice 3.2

    for (unsigned i = 1; i <= N; ++i)
    {
        printf("%u : %u\n", i, syracuse(i));
    }

    return EXIT_SUCCESS;
}
