#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned retourne1(unsigned n);
unsigned sommeChiffre(unsigned n);
bool estNarcissique(unsigned n);
unsigned cube(unsigned n);
void afficheNarcissique(unsigned n);
unsigned retourne2(unsigned n);

int main()
{

    printf("------- Test de la fonction retourne1 -------\n");

    printf("retourne %u : %u\n", 1, retourne1(1));
    printf("retourne %u : %u\n", 12, retourne1(12));
    printf("retourne %u : %u\n", 123, retourne1(123));
    printf("retourne %u : %u\n", 1234, retourne1(1234));
    printf("retourne %u : %u\n", 12345, retourne1(12345));
    printf("retourne %u : %u\n", 123456, retourne1(123456));
    printf("retourne %u : %u\n", 1234567, retourne1(1234567));
    printf("retourne %u : %u\n", 12345678, retourne1(12345678));

    printf("------- Test de la fonction retourne -------\n");

    printf("sommeChiffre %u : %u\n", 1, sommeChiffre(1));
    printf("sommeChiffre %u : %u\n", 12, sommeChiffre(12));
    printf("sommeChiffre %u : %u\n", 123, sommeChiffre(123));
    printf("sommeChiffre %u : %u\n", 1234, sommeChiffre(1234));
    printf("sommeChiffre %u : %u\n", 12345, sommeChiffre(12345));
    printf("sommeChiffre %u : %u\n", 123456, sommeChiffre(123456));
    printf("sommeChiffre %u : %u\n", 1234567, sommeChiffre(1234567));
    printf("sommeChiffre %u : %u\n", 12345678, sommeChiffre(12345678));

    printf("------- Test de la fonction estNarcissique -------\n");

    printf("estNarcissique %u : %s\n", 1, estNarcissique(1) ? "true" : "false");
    printf("estNarcissique %u : %s\n", 2, estNarcissique(2) ? "true" : "false");
    printf("estNarcissique %u : %s\n", 153, estNarcissique(153) ? "true" : "false");
    printf("estNarcissique %u : %s\n", 154, estNarcissique(154) ? "true" : "false");

    printf("------- Test de la fonction afficheNarcissique -------\n");

    printf("afficheNarcissique %u : ", 1000);
    afficheNarcissique(1000);

    printf("------- Test de la fonction retourne2 -------\n");

    printf("retourne %u : %u\n", 1, retourne2(1));
    printf("retourne %u : %u\n", 12, retourne2(12));
    printf("retourne %u : %u\n", 123, retourne2(123));
    printf("retourne %u : %u\n", 1234, retourne2(1234));
    printf("retourne %u : %u\n", 12345, retourne2(12345));
    printf("retourne %u : %u\n", 123456, retourne2(123456));
    printf("retourne %u : %u\n", 1234567, retourne2(1234567));
    printf("retourne %u : %u\n", 12345678, retourne2(12345678));

    return EXIT_SUCCESS;
}

unsigned retourne1(unsigned n)
{
    unsigned retour = 0;

    while (n > 0)
    {
        ++retour;
        n /= 10;
    }

    return retour;
}

unsigned sommeChiffre(unsigned n)
{
    unsigned somme = 0;

    while (n > 0)
    {
        somme += n % 10;
        n /= 10;
    }

    return somme;
}

bool estNarcissique(unsigned n)
{
    unsigned tmp = n, somme = 0;

    while (tmp > 0)
    {
        somme += cube(tmp % 10);
        tmp /= 10;
    }

    return somme == n;
}

unsigned cube(unsigned n)
{
    return n * n * n;
}

void afficheNarcissique(unsigned n)
{
    for (unsigned i = 1; i <= n; ++i)
    {
        if (estNarcissique(i))
        {
            printf("%u ", i);
        }
    }
    printf("\n");
}

unsigned retourne2(unsigned n)
{
    unsigned retour = 0;

    while (n > 0)
    {
        retour = retour * 10 + n % 10;
        n /= 10;
    }

    return retour;
}
