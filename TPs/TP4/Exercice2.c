

#include <stdio.h>
#include <stdlib.h>

#define N 10

size_t occ(int *t, size_t nbr, int v);
int *occ_ptr(int *t, size_t nbr, int v);

void test_occ();
void test_occ_ptr();

int main()
{

    test_occ();
    test_occ_ptr();

    return EXIT_SUCCESS;
}

size_t occ(int *t, size_t nbr, int v)
{

    if (nbr == 0)
    {
        return nbr;
    }

    for (unsigned i = 0; i < nbr; i++)
    {
        if (*(t + i) == v)
        {
            return i;
        }
    }

    return nbr;
}
int *occ_ptr(int *t, size_t nbr, int v)
{

    if (nbr == 0)
    {
        return NULL;
    }

    for (unsigned i = 0; i < nbr; i++)
    {
        if (*(t + i) == v)
        {
            return t + i;
        }
    }

    return NULL;
}

void test_occ()
{

    puts("------------- Test occ -------------");

    printf("t : ");

    int t[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (unsigned i = 0; i < N; i++)
    {
        printf("%d ", t[i]);
    }

    puts("");

    for (int i = -1; i < N + 2; ++i)
    {
        printf("v : %d, occ : %zu\n", i, occ(t, N, i));
    }

    puts("------------- End Test occ -------------\n");
}

void test_occ_ptr()
{

    puts("------------- Test occ_ptr -------------");

    printf("t : ");

    int t[N] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    for (unsigned i = 0; i < N; i++)
    {
        printf("%d ", t[i]);
    }

    puts("");

    for (int i = -1; i < N + 2; ++i)
    {
        printf("v : %d, occ : %p\n", i + 10, occ_ptr(t, N, i + 10));
    }

    puts("------------- End Test occ_ptr -------------\n");
}