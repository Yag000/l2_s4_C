#include <stdio.h>
#include <stdlib.h>

#define N 10

void sort(int *t, size_t start, size_t end);
void sort_ptr(int *start, int *end);
void swap(int *p, int *q);

void quick_sort(int *t, size_t start, size_t end);
size_t partition(int *t, size_t start, size_t end);
int compute_pivot(int *t, size_t start, size_t end);

void test_sort();
void test_sort_ptr();
void test_quicksort();

int main()
{

    test_sort();
    test_sort_ptr();
    test_quicksort();

    return EXIT_SUCCESS;
}

void sort(int *t, size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
    {
        for (size_t j = start; j < end; ++j)
        {
            if (t[j] > t[j + 1])
            {
                swap(&t[j], &t[j + 1]);
            }
        }
    }
}

void sort_ptr(int *start, int *end)
{

    for (int *ptr_i = start; ptr_i < end; ++ptr_i)
    {
        for (int *ptr_j = start; ptr_j < end; ++ptr_j)
        {
            if (*ptr_j > *(ptr_j + 1))
            {
                swap(ptr_j, ptr_j + 1);
            }
        }
    }
}

void quick_sort(int *t, size_t start, size_t end)
{
    if (start >= end || start < 0)
    {
        return;
    }

    size_t p = partition(t, start, end);

    quick_sort(t, start, p - 1);
    quick_sort(t, p + 1, end);
}

size_t partition(int *t, size_t start, size_t end)
{
    int pivot = compute_pivot(t, start, end);

    size_t index = start - 1;

    for (size_t j = start; j < end - 1; ++j)
    {
        if (*(t + j) <= pivot)
        {
            ++index;
            swap(t + index, t + j);
        }
    }

    ++index;
    swap(t + index, t + end);
    return index;
}

int compute_pivot(int *t, size_t start, size_t end)
{
    return *(t + start);
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
    puts("------------- Test sort -------------");

    int tab[N] = {10, 5, 3, 8, 2, 1, 9, 4, 7, 6};
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", tab[i]);
    }
    sort(tab, 0, N - 1);
    puts(" => ");
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", tab[i]);
    }
    puts("");

    puts("------------- End test sort -------------\n");
}

void test_sort_ptr()
{
    puts("------------- Test sort_ptr -------------");

    int tab[N] = {10, 5, 3, 8, 2, 1, 9, 4, 7, 6};
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", tab[i]);
    }
    sort_ptr(tab, tab + N);
    puts(" => ");
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", tab[i]);
    }
    puts("");

    puts("------------- End test sort_ptr -------------\n");
}

void test_quicksort()
{
    puts("------------- Test quicksort -------------");

    int tab[N] = {10, 5, 3, 8, 2, 1, 9, 4, 7, 6};
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", tab[i]);
    }
    quick_sort(tab, 0, N - 1);
    puts(" => ");
    for (size_t i = 0; i < N; ++i)
    {
        printf("%d ", tab[i]);
    }
    puts("");

    puts("------------- End test quicksort -------------\n");
}
