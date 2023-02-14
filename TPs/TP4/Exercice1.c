#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int *q);

int main()
{
    int x, y;
    x = 5;
    y = 6;
    printf("(avant) x : %d, y : %d\n", x, y); // => (avant) 5 6
    swap(&x, &y);
    printf("(apres) x : %d, y : %d\n", x, y); // => (apres) 6 5

    int tab[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", tab[i]);
    }

    printf(" => ");

    swap(&tab[0], &tab[4]);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", tab[i]);
    }

    puts("");
    return EXIT_SUCCESS;
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
