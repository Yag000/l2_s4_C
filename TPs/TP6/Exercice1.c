#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *dupliquer(const char *s);
int ordrealpha(const char *s1, const char *s2);
char *multiplier(const char *s, unsigned int n);

void test_dupliquer()
{
    char *s1 = "Bonjour";
    char *s2 = dupliquer(s1);
    printf("%s, %s", s1, s2);
    assert(strcmp(s1, s2) == 0);
    free(s2);
}

void test_ordrealpha()
{
    char *s1 = "Bonjour";
    char *s2 = "Bonjour";
    assert(ordrealpha(s1, s2) == 0);
}

void test_multiplier()
{
    char *s1 = "Bonjour";
    char *s2 = multiplier(s1, 3);
    printf("\n %s, %s", s1, s2);
    free(s2);
}

int main()
{
    test_dupliquer();
    test_ordrealpha();
    test_multiplier();
    return EXIT_SUCCESS;
}

char *dupliquer(const char *s)
{
    char *s2 = memcpy(malloc(strlen(s) + 1), s, strlen(s) + 1);
    return s2;
}

int ordrealpha(const char *s1, const char *s2)
{

    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 < *s2)
        {
            return -1;
        }
        else if (*s1 > *s2)
        {
            return 1;
        }
        s1++;
        s2++;
    }

    return 0;

    // return strcmp(s1, s2);
}

char *multiplier(const char *s, unsigned int n)
{
    char *s2 = malloc(strlen(s) * n + 1);
    for (int i = 0; i < n; i++)
    {
        strcat(s2, s);
    }
    return s2;
}
