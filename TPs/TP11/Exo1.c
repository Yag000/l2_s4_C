#include <stdio.h>

typedef struct
{
    int x, y;
} paire;

int main()
{
    int a = 69;

    void *pt = &a;
    printf("a = %d\n", a);
    *(int *)pt = 42;
    printf("a = %d\n", a);
    *(int *)pt = *((int *)pt) * *(int *)pt;
    printf("a = %d\n", a);
}
