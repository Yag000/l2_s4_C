#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct
{
    size_t indice;
    size_t len;
} mutation;

int nboc(const char *s, const char *sub);
void affiche_mutation(mutation m);
mutation diff(const char *s, const char *t);

void test_nboc();
void test_diff();

int main()
{
    test_nboc();
    test_diff();
    return EXIT_SUCCESS;
}

bool is_prefix(const char *s, const char *sub)
{
    if (strlen(sub) > strlen(s))
    {
        return false;
    }

    for (size_t j = 0; j < strlen(sub); j++)
    {
        if (s[j] != sub[j])
        {
            return false;
        }
    }
    return true;
}

int nboc(const char *s, const char *sub)
{
    int nb = 0;
    for (size_t i = 0; i < strlen(s); i++)
    {
        if (is_prefix(s + i, sub))
        {
            nb++;
        }
    }
    return nb;
}

void affiche_mutation(mutation m)
{
    printf("indice: %zu, len: %zu", m.indice, m.len);
}

mutation diff(const char *s, const char *t)
{
    assert(strlen(s) == strlen(t));

    mutation m = {0, 0};
    size_t len = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != t[i])
        {
            if (len == 0)
            {
                m.indice = i;
            }

            len++;
        }
        else if (len > 0)
        {
            break;
        }
    }

    m.len = len;
    return m;
}

void test_nboc()
{
    puts("-------------------- Test nboc --------------------");

    char *s = "bonjour";
    char *sub = "on";
    int nb = nboc(s, sub);
    printf("nboc(%s, %s) = %d (expected: 1) \n", s, sub, nb);

    char *s2 = "tolotovo";
    char *sub2 = "to";
    int nb2 = nboc(s2, sub2);
    printf("nboc(%s, %s) = %d (expected: 2) \n", s2, sub2, nb2);

    char *s3 = "aaacaa";
    char *sub3 = "aa";
    int nb3 = nboc(s3, sub3);
    printf("nboc(%s, %s) = %d (expected: 3) \n", s3, sub3, nb3);

    char *s4 = "aaacaa";
    char *sub4 = "acca";
    int nb4 = nboc(s4, sub4);
    printf("nboc(%s, %s) = %d (expected: 0) \n", s4, sub4, nb4);

    puts("-------------------- End Test nboc --------------------\n\n");
}

void test_diff()
{
    puts("-------------------- Test diff --------------------");

    char *s = "bonjour";
    char *t = "bonjouz";
    mutation m = diff(s, t);
    affiche_mutation(m);
    printf("\t expected: indice: 6, len: 1\n");

    char *s2 = "bonjour";
    char *t2 = "rtnjouz";
    mutation m2 = diff(s2, t2);
    affiche_mutation(m2);
    printf("\t expected: indice: 0, len: 2\n");

    char *s3 = "bonjour";
    char *t3 = "bonjour";
    mutation m3 = diff(s3, t3);
    affiche_mutation(m3);
    printf("\t expected: indice: 0, len: 0\n");

    char *s4 = "bonjour";
    char *t4 = "tonrtur";
    mutation m4 = diff(s4, t4);
    affiche_mutation(m4);
    printf("\t expected: indice: 0, len: 1\n");

    puts("-------------------- End Test diff --------------------\n\n");
}