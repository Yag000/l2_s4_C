
#include <stdio.h>
#include <stdbool.h>

#define SUP 1000

void initialisation(bool T[], size_t n);
void remplissage(bool T[], size_t n);
void afficheNbPremier(bool T[], size_t n);

int main(int argc, char const *argv[])
{

    bool T[SUP] = {true};
    initialisation(T, SUP);
    remplissage(T, SUP);
    afficheNbPremier(T, SUP);

    return 0;
}

void initialisation(bool T[], size_t n)
{
    if (n < 2)
    {
        return;
    }

    T[0] = false;
    T[1] = false;

    for (unsigned i = 2; i < n; i++)
    {
        T[i] = true;
    }
}

void remplissage(bool T[], size_t n)
{
    for (unsigned i = 2; i < n; i++)
    {
        if (T[i])
        {
            for (unsigned j = i + i; j < n; j += i)
            {
                T[j] = false;
            }
        }
    }
}

void afficheNbPremier(bool T[], size_t n)
{
    for (unsigned i = 0; i < n; i++)
    {
        if (T[i])
        {
            printf("%d, ", i);
        }
    }
}