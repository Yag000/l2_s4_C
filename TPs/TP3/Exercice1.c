#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NBC 10

enum etat
{
    VALIDEE,
    ENCOURS,
    EXPEDIEE
};
typedef enum etat etat;

struct commande
{
    int num_com;
    int prix_exp;
    int prix_prod;
    etat etat_com;
};
typedef struct commande commande;

commande com_alea(int num);
void affiche_com(commande c);
void affiche_exp(commande t[], size_t taille);
int nbr_en_cours(commande t[], size_t taille);
int cout_validees(commande t[], size_t taille);
void change_prix(commande *c, int newprice);
void expedie_tout(commande tab[], size_t n);

int main()
{
    srand(time(NULL));

    commande c1;
    c1.num_com = 1;
    c1.prix_exp = 10;
    c1.prix_prod = 20;
    c1.etat_com = VALIDEE;
    affiche_com(c1);

    puts("");
    commande c2 = {2, 15, 25, ENCOURS};
    affiche_com(c2);

    puts("");

    commande commandes[NBC];
    for (int i = 0; i < NBC; i++)
    {
        commandes[i] = com_alea(i + 1);
    }

    commande c = {.prix_prod = 100};
    change_prix(&c, 200);
    printf("%d\n", c.prix_prod);

    puts("-------------------");
    affiche_exp(commandes, NBC);

    expedie_tout(commandes, NBC);
    puts("-------------------");
    affiche_exp(commandes, NBC);

    return EXIT_SUCCESS;
}

void affiche_com(commande c)
{
    printf("Numéro de commande : %d \n", c.num_com);
    printf("Prix de l'expédition : %d \n", c.prix_exp);
    printf("Prix du produit : %d \n", c.prix_prod);
    switch (c.etat_com)
    {
    case VALIDEE:
        printf("Etat de la commande : Validée \n");
        break;
    case ENCOURS:
        printf("Etat de la commande : En cours \n");
        break;
    case EXPEDIEE:
        printf("Etat de la commande : Expédiée \n");
        break;
    default:
        break;
    }
}

commande com_alea(int num)
{
    commande c;
    c.num_com = num;
    c.prix_exp = rand() % 20 + 1;
    c.prix_prod = rand() % 200 + 1;
    c.etat_com = (etat)(rand() % 3);

    return c;
}

void affiche_exp(commande t[], size_t taille)
{
    for (int i = 0; i < taille; i++)
    {
        if (t[i].etat_com == EXPEDIEE)
        {
            affiche_com(t[i]);
            puts("");
        }
    }
}

int nbr_en_cours(commande t[], size_t taille)
{
    int nbr = 0;
    for (int i = 0; i < taille; i++)
    {
        if (t[i].etat_com == ENCOURS)
        {
            nbr++;
        }
    }
    return nbr;
}

int cout_validees(commande t[], size_t taille)
{
    int cout = 0;
    for (int i = 0; i < taille; i++)
    {
        if (t[i].etat_com == VALIDEE)
        {
            cout += t[i].prix_exp;
        }
    }
    return cout;
}

void change_prix(commande *c, int newprice)
{
    c->prix_prod = newprice;
}

void expedie_tout(commande tab[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i].etat_com = EXPEDIEE;
    }
}