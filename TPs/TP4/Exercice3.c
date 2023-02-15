#include <stdio.h>
#include <stdlib.h>

#define N 10

size_t nbr_occ(int *t, size_t nbr, int v);
void nbr_occ_op(int *t, size_t nbr, int v, size_t *pnv);
void min_max_op(int *t, size_t nbr, int *pmin, int *pmax);

void test_nbr_occ();
void test_nbr_occ_op();
void test_min_max_op();

int main()
{
    test_nbr_occ();
    test_nbr_occ_op();
    test_min_max_op();

    return EXIT_SUCCESS;
}

size_t nbr_occ(int *t, size_t nbr, int v)
{
    size_t count = 0;
    for (unsigned i = 0; i < nbr; i++)
    {
        if (*(t + i) == v)
        {
            ++count;
        }
    }

    return count;
}

void nbr_occ_op(int *t, size_t nbr, int v, size_t *pnv)
{
    *pnv = nbr_occ(t, nbr, v);
}

void min_max_op(int *t, size_t nbr, int *pmin, int *pmax)
{

    if (nbr == 0)
    {
        *pmin = 0;
        *pmax = 0;
        return;
    }

    int tmpMin = *t;
    int tmpMax = *t;

    for (unsigned i = 0; i < nbr; i++)
    {
        if (*(t + i) < tmpMin)
        {
            tmpMin = *(t + i);
        }
        if (*(t + i) > tmpMax)
        {
            tmpMax = *(t + i);
        }
    }
    *pmin = tmpMin;
    *pmax = tmpMax;
}

void test_nbr_occ()
{
    puts("------------- Test nbr_occ -------------");

    int t1[N] = {1, 2, 3, 4, 3, 3, 3, 8, 9, 3};

    printf("nbr_occ(t, N, 3) = %zu (expected 5) \n", nbr_occ(t1, N, 3));

    int t2[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    printf("nbr_occ(t, N, 1) = %zu (expected 10) \n", nbr_occ(t2, N, 1));
    printf("nbr_occ(t, N, 2) = %zu (expected 0) \n", nbr_occ(t2, N, 2));

    puts("------------- End test nbr_occ -------------\n");
}

void test_nbr_occ_op()
{
    puts("------------- Test nbr_occ_op -------------");

    int t1[N] = {1, 2, 3, 4, 3, 3, 3, 8, 9, 3};

    size_t count = 0;
    nbr_occ_op(t1, N, 3, &count);
    printf("nbr_occ_op(t, N, 3, &count) = %zu (expected 5) \n", count);

    int t2[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    nbr_occ_op(t2, N, 1, &count);
    printf("nbr_occ_op(t, N, 1, &count) = %zu (expected 10) \n", count);
    nbr_occ_op(t2, N, 2, &count);
    printf("nbr_occ_op(t, N, 2, &count) = %zu (expected 0) \n", count);

    puts("------------- End test nbr_occ_op -------------\n");
}

void test_min_max_op()
{
    puts("------------- Test min_max_op -------------");

    int t1[N] = {1, 2, 3, 4, 3, 3, 3, 8, 9, 3};

    int min = 0;
    int max = 0;
    min_max_op(t1, N, &min, &max);
    printf("min_max_op(t, N, &min, &max) = %d, %d (expected 1, 9) \n", min, max);

    int t2[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    min_max_op(t2, N, &min, &max);
    printf("min_max_op(t, N, &min, &max) = %d, %d (expected 1, 1) \n", min, max);

    int t3[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    min_max_op(t3, N, &min, &max);
    printf("min_max_op(t, N, &min, &max) = %d, %d (expected 1, 10) \n", min, max);

    int t4[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    min_max_op(t4, N, &min, &max);
    printf("min_max_op(t, N, &min, &max) = %d, %d (expected 1, 10) \n", min, max);

    puts("------------- End test min_max_op -------------\n");
}