#include <stdio.h>

typedef struct
{
    int x, y;
} paire;

void print(paire *p)
{
    printf("x=%d, y=%d\n", p->x, p->y);
}

int maino()
{
    int a = 69;

    void *pt = &a;
    printf("a = %d\n", a);
    *(int *)pt = 42;
    printf("a = %d\n", a);
    *(int *)pt = *((int *)pt) * *(int *)pt;
    printf("a = %d\n", a);

    paire b = {1, 1};
    pt = &b;
    print(&b);
    ((paire *)pt)->y++;
    print(&b);
}
