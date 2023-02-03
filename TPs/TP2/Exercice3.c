
#include <stdio.h>
#include <stdlib.h>

unsigned f(unsigned n);

unsigned g(unsigned n);

int main()
{

    printf("f(0) : %d\n", f(0));
    printf("f(1) : %d\n", f(1));
    printf("f(2) : %d\n", f(2));
    printf("f(20) : %d\n", f(20));

    return EXIT_SUCCESS;
}

unsigned f(unsigned n)
{
    if (n <= 1)
    {
        return 2;
    }
    else
    {
        return 2 * g(n - 1);
    }
}

unsigned g(unsigned n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return 3 * f(n / 2);
    }
}