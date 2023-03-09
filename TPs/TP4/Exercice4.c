#include <stdio.h>
#include <stdlib.h>

#define N 10

void print_tab_old(int *t, size_t start, size_t end);
void print_tab(int *pstart, int *pend);

void test_print_tab_old();
void test_print_tab();

int main()
{
    test_print_tab_old();
    test_print_tab();

    return EXIT_SUCCESS;
}

void print_tab_old(int *t, size_t start, size_t end)
{
    while (start < end)
    {
        printf("%p : %d\n", t + start, *(t + start));
        ++start;
    }
}
void print_tab(int *pstart, int *pend)
{
    while (pstart < pend)
    {
        printf("%p : %d\n", pstart, *pstart);
        ++pstart;
    }
}

void test_print_tab_old()
{

    puts("------------- Test print_tab_old -------------\n");

    int t[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    puts("print_tab_old(t, 0, N)");
    print_tab_old(t, 0, N);

    puts("\print_tab_old(t, 1, 5)");
    print_tab_old(t, 1, 5);

    puts("\print_tab_old(t, 3, 4)");
    print_tab_old(t, 3, 4);
    puts("");

    puts("------------- End test print_tab_old -------------\n");
}

void test_print_tab()
{

    puts("------------- Test print_tab_old -------------\n");

    int t[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *start = t;
    int *end = t + N;

    puts("print_tab(0, N)");
    print_tab(start, end);

    start = t + 1;
    end = t + 5;

    puts("\nprint_tab(1, 5)");
    print_tab(start, end);

    start = t + 3;
    end = t + 4;
    puts("\nprint_tab(3, 4)");
    print_tab(start, end);
    puts("");

    puts("------------- End test print_tab_old -------------\n");
}
