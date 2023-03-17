#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *dupliquer(const char *s);
int ordrealpha(const char *s1, const char *s2);
char *multiplier(const char *s, unsigned int n);

int main(int argc, char *argv[])
{
    assert(argc == 3);

    char *s1 = argv[1];
    char *s2 = argv[2];

    int ordre = ordrealpha(s1, s2);

    char correctChar;
    if (ordre == 0)
    {
        correctChar = '=';
    }
    else if (ordre == 1)
    {
        correctChar = '>';
    }
    else
    {
        correctChar = '<';
    }

    printf("%s %c %s", s1, correctChar, s2);
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
        if (*s1 > *s2)
        {
            return -1;
        }
        else if (*s1 < *s2)
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
