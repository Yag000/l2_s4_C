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
    if (p.de == 0)
    {
        p2.de = 0;
        return p2;
    }

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

    for (int i = 0; i <= p3.de; ++i)

    {
        unsigned degree = p3.de - i;
        if (p3.co[degree] != 0)
        {
            p3.de = degree;
            break;
        }
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

    polynome p1 = {5, {0, 1, 2, 3, 4, 5}};
    printPoly(p1);
    printf("évalué en 10 vaut: %d\n", eval(p1, 10));

    polynome p2 = {3, {1, 4, 0, 3}};
    printPoly(p2);
    printf("évalué en -1 vaut: %d\n", eval(p2, -1));
}

void testPrintPoly()
{

    puts("-------- Test de la fonction printPoly --------");

    polynome p1 = {3, {1, 4, 0, 3}};
    printPoly(p1);

    polynome p2 = {5, {0, 1, 2, 0, 4, 5}};
    printPoly(p2);

    polynome p3 = {1, {0, 1}};
    printPoly(p3);
    polynome p4 = {2, {0, 0, 2}};
    printPoly(p4);

    polynome p5 = {0, {2}};
    printPoly(p5);

    puts("-------- Fin du test de la fonction printPoly --------");
}

void testDerive()
{

    puts("-------- Test de la fonction derive --------");

    polynome p1 = {3, {1, 4, 0, 3}};
    printPoly(p1);
    puts("Dérivée: ");
    printPoly(derive(p1));

    polynome p2 = {5, {10, 1, 2, 3, 4, 5}};
    printPoly(p2);
    puts("Dérivée: ");
    printPoly(derive(p2));

    puts("-------- Fin du test de la fonction derive --------");
}

void testSomme()
{

    puts("-------- Test de la fonction somme --------");

    polynome p1 = {5, {0, 1, 2, 3, 4, 5}};
    polynome p2 = {2, {1, 0, 2}};

    printPoly(p1);
    puts("+");
    printPoly(p2);
    puts("------------------");
    printPoly(somme(p1, p2));
    puts("========================");

    polynome p3 = {2, {1, 1, 2}};
    polynome p4 = {1, {2, 3}};

    printPoly(p3);
    puts("+");
    printPoly(p4);
    puts("------------------");
    printPoly(somme(p3, p4));
    puts("========================");

    polynome p5 = {4, {1, 1, 2, 1, -5}};
    polynome p6 = {4, {2, 3, 2, -1, 5}};

    printPoly(p5);
    puts("+");
    printPoly(p6);
    puts("------------------");
    printPoly(somme(p5, p6));

    puts("-------- Fin du test de la fonction somme --------");
}

void testMultiplication()
{

    puts("-------- Test de la fonction multiplication --------");

    polynome p1 = {5, {0, 1, 2, 3, 4, 5}};
    polynome p2 = {2, {1, 0, 2}};

    printPoly(p1);
    puts("*");
    printPoly(p2);
    puts("------------------");
    printPoly(multiplication(p1, p2));
    puts("========================");

    polynome p3 = {2, {1, 1, 2}};
    polynome p4 = {1, {2, 3}};

    printPoly(p3);
    puts("*");
    printPoly(p4);
    puts("------------------");
    printPoly(multiplication(p3, p4));
    puts("========================");

    puts("-------- Fin du test de la fonction multiplication --------");
}