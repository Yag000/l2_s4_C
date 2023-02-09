#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

struct polynome
{
    int de;
    int co[N];
};

typedef struct polynome polynome;
int eval(polynome p, int valeur);
void printPoly(polynome p);
void printPoly(polynome p);
void testPoly();

int main()
{
    polynome p;
    p.de = 5;
    p.co[0] = 0;
    p.co[1] = 1;
    p.co[2] = 2;
    p.co[3] = 3;
    p.co[4] = 4;
    p.co[5] = 5;

    printf("Valeur : %d\n", eval(p, 1));
    puts("");
    printPoly(p);

    puts("--------------------");

    testPoly();
    return EXIT_SUCCESS;
}

int eval(polynome p, int x)
{
    int valeur = 0;

    for (int i = 0; i <= p.de; ++i)
    {
        valeur += p.co[i] * pow(x, i);
    }

    return valeur;
}

void printPoly(polynome p)
{
    for (int i = 0; i <= p.de; ++i)
    {
        int power = p.de - i;
        if (p.co[power] == 0)
        {
            continue;
        }
        if (i != 0)
        {
            printf(" + ");
        }

        if (p.co[power] != 1 || power == 0)
        {
            printf("%d", p.co[power]);
        }
        if (power >= 1)
        {
            printf("X");
            if (power > 1)
            {
                printf("^%d", power);
            }
        }
    }

    printf("\n");
}

polynome derive(polynome p)
{
    polynome p2;
    p2.de = p.de - 1;
    for (int i = 0; i <= p2.de; ++i)
    {
        p2.co[i] = p.co[i + 1] * (i + 1);
    }

    return p2;
}

void testPoly()
{

    polynome p1;
    p1.de = 5;
    p1.co[0] = 0;
    p1.co[1] = 1;
    p1.co[2] = 2;
    p1.co[3] = 0;
    p1.co[4] = 4;
    p1.co[5] = 5;

    printPoly(p1);

    polynome p2;
    p2.de = 1;
    p2.co[0] = 0;
    p2.co[1] = 0;

    printPoly(p2);

    polynome p3;
    p3.de = 1;
    p3.co[0] = 0;
    p3.co[1] = 1;

    printPoly(p3);

    polynome p5;
    p5.de = 0;
    p5.co[0] = 2;

    printPoly(p5);

    polynome p6;
    p6.de = 2;
    p6.co[0] = 0;
    p6.co[1] = 0;
    p6.co[2] = 2;

    printPoly(p6);
}
