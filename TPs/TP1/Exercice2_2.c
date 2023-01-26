#include <stdio.h>
#include <stdlib.h>

unsigned fact(unsigned n);

int main()
{
    unsigned n;

    printf("Enter a number: ");
    scanf("%u", &n);

    printf("Factorial of %u: %u\n", n, fact(n));

    return EXIT_SUCCESS;
}

unsigned fact(unsigned n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
