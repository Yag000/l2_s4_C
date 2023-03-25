#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

typedef struct polynome
{
    int coef;
    int degre;
    struct polynome *suiv;
} polynome;

polynome *creer_polynome_vide();
polynome *creer_monome(int c, int d);
void polynome_destroy(polynome *p);
double evaluer_polynome(polynome *p, double x);
void afficher_polynome(polynome *p);
void ajouter_monome(polynome *p, int c, int d);
polynome *copie(polynome *p);
polynome *somme(polynome *p1, polynome *p2);
polynome *produit_monome(polynome *p, int c, int d);
polynome *produit(polynome *p1, polynome *p2);

void test_evaluer_polynome();
void test_afficher_polynome();
void test_ajouter_monome();
void test_copie();
void test_somme();
void test_produit_monome();
void test_produit();

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s nb_monomes_poly1 nb_monomes_poly2\n", argv[0]);
        return 1;
    }

    int nb_monomes1 = atoi(argv[1]);
    int nb_monomes2 = atoi(argv[2]);

    // Création des polynômes
    polynome *poly1 = creer_polynome_vide();

    polynome *poly2 = creer_polynome_vide();

    char *question_text = "Entrez le coefficient et le degré du monôme %d du polynôme : ";
    puts("--------------------------- Polynôme 1 ---------------------------");
    for (int i = 0; i < nb_monomes1; i++)
    {
        int c, d;
        printf(question_text, i + 1);
        scanf("%d %d", &c, &d);
        ajouter_monome(poly1, c, d);
    }

    puts("--------------------------- Polynôme 2 ---------------------------");
    for (int i = 0; i < nb_monomes2; i++)
    {
        int c, d;
        printf(question_text, i + 1);
        scanf("%d %d", &c, &d);
        ajouter_monome(poly2, c, d);
    }

    // Affichage des polynômes et de leur somme
    printf("Premier polynôme : ");
    afficher_polynome(poly1);
    printf("\n");

    printf("Deuxième polynôme : ");
    afficher_polynome(poly2);
    printf("\n");

    polynome *p_somme = somme(poly1, poly2);
    printf("Somme des deux polynômes : ");
    afficher_polynome(p_somme);
    printf("\n");

    polynome *p_produit = produit(poly1, poly2);
    printf("Produit des deux polynômes : ");
    afficher_polynome(p_produit);
    printf("\n");

    // Destruction des polynômes
    polynome_destroy(poly1);
    polynome_destroy(poly2);
    polynome_destroy(p_somme);
    polynome_destroy(p_produit);

    puts("--------------------------- Tests ---------------------------");
    test_evaluer_polynome();
    test_afficher_polynome();
    test_ajouter_monome();
    test_copie();
    test_somme();
    test_produit_monome();
    test_produit();

    return EXIT_SUCCESS;
}

polynome *creer_polynome_vide()
{
    polynome *p = malloc(sizeof(polynome));
    p->coef = 0;
    p->degre = -1;
    p->suiv = NULL;

    return p;
}

polynome *creer_monome(int c, int d)
{
    assert(d >= 0);
    polynome *p = creer_polynome_vide();
    polynome *p2 = malloc(sizeof(polynome));
    p2->coef = c;
    p2->degre = d;
    p2->suiv = NULL;

    p->suiv = p2;

    return p;
}

void polynome_destroy(polynome *p)
{
    polynome *p2 = p->suiv;
    while (p2 != NULL)
    {
        free(p);
        p = p2;
        p2 = p2->suiv;
    }
    free(p);
}

double power(double x, int n)
{
    double res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= x;
    }
    return res;
}

double evaluer_polynome(polynome *p, double x)
{
    double res = 0;
    polynome *p2 = p->suiv;
    while (p2 != NULL)
    {
        res += p2->coef * power(x, p2->degre);
        p2 = p2->suiv;
    }
    return res;
}

void afficher_polynome(polynome *p)
{
    polynome *p2 = p->suiv;
    while (p2 != NULL)
    {
        int power = p2->degre;
        int coef = p2->coef;
        if (coef == 0)
        {
            p2 = p2->suiv;
            continue;
        }
        if (p->suiv != p2)
        {

            printf(coef < 0 ? " " : " + ");
        }
        if ((coef != 1 || power == 0) && coef != -1)
        {
            printf("%d", coef);
        }
        if (coef == -1)
        {
            printf("-");
        }
        if (power >= 1)
        {
            printf("X");
            if (power > 1)
            {
                printf("^%d", power);
            }
        }
        p2 = p2->suiv;
    }
}

void ajouter_monome(polynome *p, int c, int d)
{
    assert(d >= 0);
    assert(p != NULL);

    if (c == 0)
    {
        return;
    }

    polynome *p2 = p;

    while (p2->suiv != NULL && p2->suiv->degre > d)
    {
        p2 = p2->suiv;
    }

    if (p2->suiv != NULL && p2->suiv->degre == d)
    {
        if (p2->suiv->coef + c == 0)
        {
            polynome *temp = p2->suiv;
            p2->suiv = p2->suiv->suiv;
            free(temp);
        }
        else
        {
            p2->suiv->coef += c;
        }
    }
    else
    {
        polynome *p3 = malloc(sizeof(polynome));
        p3->coef = c;
        p3->degre = d;
        p3->suiv = NULL;
        if (p2->suiv == NULL)
        {
            p2->suiv = p3;
        }
        else if (p2->suiv->degre < d)
        {
            p3->suiv = p2->suiv;
            p2->suiv = p3;
        }
        else
        {
            p3->suiv = p2->suiv;
            p2->suiv = p3;
        }
    }
}

polynome *copie(polynome *p)
{
    polynome *iterator = creer_polynome_vide();
    polynome *res = iterator;
    polynome *tmp;
    p = p->suiv;
    while (p != NULL)
    {
        tmp = malloc(sizeof(polynome));
        tmp->coef = p->coef;
        tmp->degre = p->degre;
        tmp->suiv = NULL;
        iterator->suiv = tmp;

        afficher_polynome(res);

        iterator = iterator->suiv;
        p = p->suiv;
    }
    return res;
}

polynome *somme(polynome *p1, polynome *p2)
{
    polynome *res = creer_polynome_vide();
    polynome *iterator = res;
    polynome *tmp;
    while (p1 != NULL || p2 != NULL)
    {
        tmp = malloc(sizeof(polynome));
        if (p1 != NULL && p2 != NULL && p1->degre == p2->degre)
        {
            tmp->coef = p1->coef + p2->coef;

            tmp->degre = p1->degre;
            p1 = p1->suiv;
            p2 = p2->suiv;
        }
        else if (p1 != NULL && p1->degre > p2->degre)
        {
            tmp = malloc(sizeof(polynome));
            tmp->coef = p1->coef;
            tmp->degre = p1->degre;
            p1 = p1->suiv;
        }
        else if (p2 != NULL)
        {
            tmp = malloc(sizeof(polynome));
            tmp->coef = p2->coef;
            tmp->degre = p2->degre;
            p2 = p2->suiv;
        }
        if (tmp->coef == 0)
        {
            continue;
        }
        tmp->suiv = NULL;
        iterator->suiv = tmp;
        iterator = iterator->suiv;
    }
    return res;
}

polynome *produit_monome(polynome *p, int c, int d)
{
    assert(p != NULL);

    polynome *res = creer_polynome_vide();

    polynome *dernier = res;
    polynome *courant = p->suiv;

    while (courant != NULL)
    {
        polynome *nouveau = malloc(sizeof(polynome));
        nouveau->coef = courant->coef * c;
        nouveau->degre = courant->degre + d;
        nouveau->suiv = NULL;

        dernier->suiv = nouveau;
        dernier = nouveau;

        courant = courant->suiv;
    }

    return res;
}

polynome *produit(polynome *p1, polynome *p2)
{
    assert(p1 != NULL);
    assert(p2 != NULL);

    polynome *res = creer_polynome_vide();
    polynome *courant = p2->suiv;

    while (courant != NULL)
    {
        polynome *produit = produit_monome(p1, courant->coef, courant->degre);
        polynome *temp = res;
        res = somme(res, produit);
        polynome_destroy(temp);
        polynome_destroy(produit);
        courant = courant->suiv;
    }

    return res;
}

void test_evaluer_polynome()
{
    puts("--------------- Test evaluer_polynome ---------------\n");
    polynome *p = creer_monome(5, 6);
    polynome *p2 = creer_polynome_vide();
    p2->coef = 1;
    p2->degre = 7;
    (p->suiv)->suiv = p2;

    printf("p(0) = %lf, expected 0\n", evaluer_polynome(p, 0));
    printf("p(1) = %lf, expected 6\n", evaluer_polynome(p, 1));
    printf("p(2) = %lf, expected 448\n", evaluer_polynome(p, 2));
    printf("p(10) = %lf, expected 15000000\n", evaluer_polynome(p, 10));

    polynome_destroy(p);

    puts("--------------- End of test ---------------\n");
}

void test_afficher_polynome()
{
    puts("--------------- Test afficher_polynome ---------------\n");
    polynome *p = creer_monome(5, 6);
    polynome *p2 = creer_polynome_vide();
    p2->coef = 1;
    p2->degre = 7;
    (p->suiv)->suiv = p2;

    printf("p = ");
    afficher_polynome(p);
    printf(", expected 5X^6 + X^7 \n");

    p->suiv->coef = -1;
    printf("p = ");
    afficher_polynome(p);
    printf(", expected -X^6 + X^7 \n");

    p->suiv->suiv->coef = -1;
    printf("p = ");
    afficher_polynome(p);
    printf(", expected -X^6 -X^7\n");

    polynome_destroy(p);

    puts("--------------- End of test ---------------\n");
}

void test_ajouter_monome()
{
    puts("--------------- Test ajouter_monome ---------------\n");
    polynome *p = creer_monome(5, 6);
    ajouter_monome(p, 1, 7);
    printf("p = ");
    afficher_polynome(p);
    printf(", expected X^7 + 5X^6 \n");

    ajouter_monome(p, -1, 6);
    printf("p = ");
    afficher_polynome(p);
    printf(", expected X^7 + 4X^6 \n");

    ajouter_monome(p, -1, 7);
    printf("p = ");
    afficher_polynome(p);
    printf(", expected 4X^6 \n");

    polynome_destroy(p);

    polynome *p2 = creer_monome(1, 7);
    ajouter_monome(p2, -1, 6);
    printf("p2 = ");
    afficher_polynome(p2);
    printf(", expected  X^7 -X^6 \n");

    polynome_destroy(p2);

    polynome *p3 = creer_polynome_vide();

    ajouter_monome(p3, 2, 3);
    afficher_polynome(p3);
    printf(", expected 2X^3 \n");

    ajouter_monome(p3, -4, 2);
    afficher_polynome(p3);
    printf(", expected 2X^3 - 4X^2 \n");

    ajouter_monome(p3, 1, 1);
    afficher_polynome(p3);
    printf(", expected 2X^3 - 4X^2 + X \n");

    ajouter_monome(p3, 3, 3);
    afficher_polynome(p3);
    printf(", expected 5X^3 - 4X^2 + X \n");

    ajouter_monome(p, 0, 2);
    afficher_polynome(p3);
    printf(", expected 5X^3 - 4X^2 + X \n");

    ajouter_monome(p, 5, 0);
    afficher_polynome(p3);
    printf(", expected 5X^3 - 4X^2 + X + 5 \n");

    ajouter_monome(p, 4, 2);
    afficher_polynome(p3);
    printf(", expected 5X^3 + X + 5 \n");

    puts("--------------- End of test ---------------\n");
}

void test_copie()
{
    puts("--------------- Test copie ---------------\n");
    polynome *p = creer_monome(5, 6);
    ajouter_monome(p, 1, 7);
    polynome *p2 = copie(p);
    printf("p = ");
    afficher_polynome(p);
    printf(", expected X^7 + 5X^6 \n");
    printf("p2 = ");
    afficher_polynome(p2);
    printf(", expected X^7 + 5X^6 \n");

    ajouter_monome(p, -1, 6);
    printf("p = ");
    afficher_polynome(p);
    printf(", expected X^7 + 4X^6 \n");
    printf("p2 = ");
    afficher_polynome(p2);
    printf(", expected X^7 + 5X^6 \n");

    polynome_destroy(p);
    polynome_destroy(p2);

    puts("--------------- End of test ---------------\n");
}

void test_somme()
{
    puts("--------------- Test somme ---------------\n");
    polynome *p = creer_monome(5, 6);
    ajouter_monome(p, 1, 7);
    polynome *p2 = creer_monome(1, 7);
    ajouter_monome(p2, -1, 6);
    polynome *p3 = somme(p, p2);
    printf("p = ");
    afficher_polynome(p);
    printf(", expected X^7 + 5X^6 \n");
    printf("p2 = ");
    afficher_polynome(p2);
    printf(", expected X^7 - X^6 \n");
    printf("p3 = p + p2 =");
    afficher_polynome(p3);
    printf(", expected 2X^7 + 4X^6 \n");

    polynome_destroy(p);
    polynome_destroy(p2);
    polynome_destroy(p3);

    puts("--------------- End of test ---------------\n");
}

void test_produit_monome()
{
    puts("--------------- Test produit_monome ---------------\n");
    polynome *p = creer_polynome_vide();
    ajouter_monome(p, 3, 5);
    ajouter_monome(p, 2, 3);
    ajouter_monome(p, 1, 2);
    ajouter_monome(p, 4, 1);
    ajouter_monome(p, 5, 0);

    printf("Polynome avant multiplication par 2x^3 : ");
    afficher_polynome(p);

    polynome *p2 = produit_monome(p, 2, 3);

    printf("\nPolynome après multiplication par 2x^3 : ");
    afficher_polynome(p2);
    printf(", expected 6X^8 + 4X^6 + 2X^5 + 8X^4 + 10X^3\n");

    polynome_destroy(p);
    polynome_destroy(p2);

    puts("--------------- End of test ---------------\n");
}

void test_produit()
{

    puts("--------------- Test produit ---------------\n");

    polynome *p1 = creer_polynome_vide();
    ajouter_monome(p1, 3, 2);
    ajouter_monome(p1, 2, 1);
    ajouter_monome(p1, 1, 0);
    printf("p1 = ");
    afficher_polynome(p1);
    puts("");

    polynome *p2 = creer_polynome_vide();
    ajouter_monome(p2, 2, 1);
    ajouter_monome(p2, 1, 0);
    printf("p2 = ");
    afficher_polynome(p2);
    puts("");

    polynome *p3 = produit(p1, p2);
    printf("p1 * p2 = ");
    afficher_polynome(p3);
    printf(" , expected 6X^3 + 7X^2 + 4X + 1 \n");

    polynome_destroy(p1);
    polynome_destroy(p2);
    polynome_destroy(p3);

    puts("--------------- End of test ---------------\n");
}