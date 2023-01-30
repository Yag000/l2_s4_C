

#include <stdio.h>

void somme(int T[], int S[], size_t b);
void permute(int T[], size_t n);

void testSomme();
void testSommeHelper(int n);

void testPermute();
void testPermuteHelper(int n);

int main()
{

    testSomme();
    testPermute();
    return 0;
}

void somme(int T[], int S[], size_t b)
{
    if (b == 0)
    {
        return;
    }

    S[0] = T[0];

    for (unsigned i = 1; i < b; i++)
    {
        S[i] = T[i] + S[i - 1];
    }
}

void permute(int T[], size_t n)
{
    if (n == 0)
    {
        return;
    }

    int temp = T[n - 1];

    for (unsigned i = n - 1; i > 0; i--)
    {
        T[i] = T[i - 1];
    }

    T[0] = temp;
}

void testSomme()
{

    puts("------ Test de la fonction somme ------");

    puts("Test 0");
    testSommeHelper(0);

    puts("Test 1");
    testSommeHelper(1);

    puts("\nTest 2");
    testSommeHelper(2);

    puts("\nTest 10");
    testSommeHelper(10);

    puts("\n------ Fin du test ------");
}

void testSommeHelper(int n)
{
    int T[n];
    int S[n];

    for (unsigned i = 0; i < n; i++)
    {
        T[i] = i + 1;
    }

    somme(T, S, n);

    for (unsigned i = 0; i < n; i++)
    {
        printf("%d ", S[i]);
    }
}

void testPermute()
{

    puts("------ Test de la fonction somme ------");

    puts("Test 0");
    testPermuteHelper(0);

    puts("Test 1");
    testPermuteHelper(1);

    puts("\nTest 2");
    testPermuteHelper(2);

    puts("\nTest 10");
    testPermuteHelper(10);

    puts("\n------ Fin du test ------");
}

void testPermuteHelper(int n)
{
    int T[n];

    for (unsigned i = 0; i < n; i++)
    {
        T[i] = i + 1;
    }

    permute(T, n);

    for (unsigned i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }
}
