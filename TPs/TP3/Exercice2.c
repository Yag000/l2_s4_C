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
polynome derive(polynome p);
polynome somme(polynome p1, polynome p2);
polynome multiplication(polynome p1, polynome p2);

void testEval();
void testPrintPoly();
void testDerive();
void testSomme();
void testMultiplication();

int main()
{
    testEval();
    testPrintPoly();
    testDerive();
    testSomme();
    testMultiplication();

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
            printf(p.co[power] < 0 ? " " : " + ");
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

polynome somme(polynome p1, polynome p2)
{
    polynome p3;
    p3.de = p1.de > p2.de ? p1.de : p2.de;
    for (int i = 0; i <= p3.de; ++i)
    {
        if (i > p1.de)
        {
            p3.co[i] = p2.co[i];
            continue;
        }
        if (i > p2.de)
        {
            p3.co[i] = p1.co[i];
            continue;
        }

        p3.co[i] = p1.co[i] + p2.co[i];
    }

    return p3;
}

polynome multiplication(polynome p1, polynome p2)
{
    polynome p3;
    p3.de = p1.de + p2.de;
    for (int i = 0; i <= p3.de; ++i)
    {
        p3.co[i] = 0;
    }

    for (int i = 0; i <= p1.de; ++i)
    {
        for (int j = 0; j <= p2.de; ++j)
        {
            p3.co[i + j] += p1.co[i] * p2.co[j];
        }
    }

    return p3;
}

void testEval()
{

    puts("-------- Test de la fonction eval --------");

    polynome p1;
    p1.de = 5;
    p1.co[0] = 0;
    p1.co[1] = 1;
    p1.co[2] = 2;
    p1.co[3] = 3;
    p1.co[4] = 4;
    p1.co[5] = 5;

    printPoly(p1);
    printf("évalué en 10 vaut: %d\n", eval(p1, 10));
}

void testPrintPoly()
{

    puts("-------- Test de la fonction printPoly --------");

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

    puts("-------- Fin du test de la fonction printPoly --------");
}

void testDerive()
{

    puts(" -------- Test de la fonction derive --------");

    polynome p1;
    p1.de = 5;
    p1.co[0] = 10;
    p1.co[1] = 1;
    p1.co[2] = 2;
    p1.co[3] = 3;
    p1.co[4] = 4;
    p1.co[5] = 5;

    printPoly(p1);
    printPoly(derive(p1));

    puts(" -------- Fin du test de la fonction derive --------");
}

void testSomme()
{

    puts("-------- Test de la fonction somme --------");

    polynome p1;
    p1.de = 5;
    p1.co[0] = 0;
    p1.co[1] = 1;
    p1.co[2] = 2;
    p1.co[3] = 3;
    p1.co[4] = 4;
    p1.co[5] = 5;

    polynome p2;
    p2.de = 2;
    p2.co[0] = 1;
    p2.co[1] = 0;
    p2.co[2] = 2;

    printPoly(p1);
    printPoly(p2);
    printPoly(somme(p1, p2));

    puts("-------- Fin du test de la fonction somme --------");
}

void testMultiplication()
{

    puts("-------- Test de la fonction multiplication --------");

    polynome p1;
    p1.de = 5;
    p1.co[0] = 0;
    p1.co[1] = 1;
    p1.co[2] = 2;
    p1.co[3] = 3;
    p1.co[4] = 4;
    p1.co[5] = 5;

    polynome p2;
    p2.de = 2;
    p2.co[0] = 1;
    p2.co[1] = 0;
    p2.co[2] = 2;

    printPoly(p1);
    printPoly(p2);
    printPoly(multiplication(p1, p2));

    puts("-------- Fin du test de la fonction multiplication --------");
}