#include <stdio.h>
#include <stdlib.h>

#define N 10

void sort(int *t, size_t start, size_t end);
void swap(int *p, int *q);

void test_sort();

int main()
{

    test_sort();

    return EXIT_SUCCESS;
}

void sort(int *t, size_t start, size_t end)
{
    for (size_t i = start; i < end; i++)
    {
        for (size_t j = start; j < end; j++)
        {
            if (t[j] > t[j + 1])
            {
                swap(&t[j], &t[j + 1]);
            }
        }
    }
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void test_sort()
{
    int tab[N] = {10, 5, 3, 8, 2, 1, 9, 4, 7, 6};
    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", tab[i]);
    }
    sort(tab, 0, N - 1);
    puts(" => ");
    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", tab[i]);
    }
    puts("");
}