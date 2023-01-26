#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned n;

    printf("Enter a number: ");
    scanf("%u", &n);

    unsigned acc = 0;

    for (unsigned i = 1; i <= n; ++i)
    {
        acc += i * i * i;
    }

    printf("Sum of the first %u cubes: %u\n", n, acc);

    return EXIT_SUCCESS;
}
