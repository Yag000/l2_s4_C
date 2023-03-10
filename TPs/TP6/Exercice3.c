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
mutation longest(const char *s, const char *t);
char *longest_string(const char *s, const char *t);

void test_nboc();
void test_diff();
void test_longest();
void test_longest_string();

int main()
{
    test_nboc();
    test_diff();
    test_longest();
    test_longest_string();
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

mutation longest(const char *s, const char *t)
{
    mutation m = {0, 0};
    mutation m2;

    int index = 0;
    while (index < strlen(s))
    {
        m2 = diff(s + index, t + index);
        if (m2.len > m.len)
        {
            m = m2;
            m.indice += index;
        }

        if (m2.len == 0)
        {
            index += 1;
        }
        else
        {
            index += m2.len;
        }
    }

    return m;
}

char *longest_string(const char *s, const char *t)
{
    mutation m = longest(s, t);

    char *sub = malloc(sizeof(char) * (m.len + 1));
    memmove(sub, t + m.indice, sizeof(char) * (m.len + 1));
    sub[m.len] = '\0';

    return sub;
}

void test_nboc()
{
    puts("-------------------- Test nboc --------------------");

    char *s = "actccttg";
    char *sub = "cc";
    int nb = nboc(s, sub);
    printf("nboc(%s, %s) = %d (expected: 1) \n", s, sub, nb);

    char *s2 = "cacacttgtctaatc";
    char *sub2 = "ac";
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

    char *s = "aaactgc";
    char *t = "aaactgt";
    mutation m = diff(s, t);
    affiche_mutation(m);
    printf("\t expected: indice: 6, len: 1\n");

    char *s2 = "aaactgc";
    char *t2 = "tgactgc";
    mutation m2 = diff(s2, t2);
    affiche_mutation(m2);
    printf("\t expected: indice: 0, len: 2\n");

    char *s3 = "aaactgc";
    char *t3 = "aaactgc";
    mutation m3 = diff(s3, t3);
    affiche_mutation(m3);
    printf("\t expected: indice: 0, len: 0\n");

    char *s4 = "aaactgc";
    char *t4 = "tacatgc";
    mutation m4 = diff(s4, t4);
    affiche_mutation(m4);
    printf("\t expected: indice: 0, len: 1\n");

    puts("-------------------- End Test diff --------------------\n\n");
}

void test_longest()
{
    puts("-------------------- Test longest --------------------");

    char *s = "aaactgc";
    char *t = "aaactgt";
    mutation m = longest(s, t);
    affiche_mutation(m);
    printf("\t expected: indice: 6, len: 1\n");

    char *s2 = "aaactgc";
    char *t2 = "tgactgc";
    mutation m2 = longest(s2, t2);
    affiche_mutation(m2);
    printf("\t expected: indice: 0, len: 2\n");

    char *s3 = "aaactgc";
    char *t3 = "aaactgc";
    mutation m3 = longest(s3, t3);
    affiche_mutation(m3);
    printf("\t expected: indice: 0, len: 0\n");

    char *s4 = "aaactgc";
    char *t4 = "tacatgc";
    mutation m4 = longest(s4, t4);
    affiche_mutation(m4);
    printf("\t expected: indice: 2, len: 2\n");

    char *s5 = "aaactgc";
    char *t5 = "tacagat";
    mutation m5 = longest(s5, t5);
    affiche_mutation(m5);
    printf("\t expected: indice: 2, len: 5\n");

    char *s6 = "aaactgc";
    char *t6 = "taactaa";
    mutation m6 = longest(s6, t6);
    affiche_mutation(m6);
    printf("\t expected: indice: 5, len: 2\n");

    puts("-------------------- End Test longest --------------------\n\n");
}

void test_longest_string()
{
    puts("-------------------- Test longest_string --------------------");

    char *s = "aaactgc";
    char *t = "aaactgt";
    char *m = longest_string(s, t);
    printf("longest_string(%s, %s) = %s (expected: %s) \n", s, t, m, "t");

    char *s2 = "aaactgc";
    char *t2 = "tgactgc";
    char *m2 = longest_string(s2, t2);
    printf("longest_string(%s, %s) = %s (expected: %s) \n", s2, t2, m2, "tg");

    char *s3 = "aaactgc";
    char *t3 = "aaactgc";
    char *m3 = longest_string(s3, t3);
    printf("longest_string(%s, %s) = %s (expected: %s) \n", s3, t3, m3, "");

    char *s4 = "aaactgc";
    char *t4 = "tacatgc";
    char *m4 = longest_string(s4, t4);
    printf("longest_string(%s, %s) = %s (expected: %s) \n", s4, t4, m4, "ca");

    char *s5 = "aaactgc";
    char *t5 = "tacagat";
    char *m5 = longest_string(s5, t5);
    printf("longest_string(%s, %s) = %s (expected: %s) \n", s5, t5, m5, "cagat");

    char *s6 = "aaactgc";
    char *t6 = "taactaa";
    char *m6 = longest_string(s6, t6);
    printf("longest_string(%s, %s) = %s (expected: %s) \n", s6, t6, m6, "aa");

    puts("-------------------- End Test longest_string --------------------\n\n");
}
