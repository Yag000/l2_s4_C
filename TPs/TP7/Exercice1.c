#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

int nbr_words(const char *s);
int word_len(const char *w);
char *extract_word(const char *w, int *pl);
char *next_word(char *w);

void test_nbr_words();
void test_word_len();
void test_extract_word();
void test_next_word();

int main()
{
    test_nbr_words();
    test_word_len();
    test_extract_word();
    test_next_word();
}
int nbr_words(const char *s)
{
    int words_found = 0;
    bool is_inside_word = false;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]))
        {
            is_inside_word = false;
        }
        else
        {
            if (is_inside_word)
            {
                continue;
            }

            ++words_found;
            is_inside_word = true;
        }
    }

    return words_found;
}

int word_len(const char *w)
{
    assert(!isspace(*w));

    int word_length = 0;
    while (!isspace(*w) && *w)
    {
        ++word_length;
        ++w;
    }

    return word_length;
}

char *extract_word(const char *w, int *pl)
{
    *pl = word_len(w);

    char *res = malloc((*pl + 1) * sizeof(char));
    memmove(res, w, (*pl + 1) * sizeof(char));
    res[*pl] = '\0';

    return res;
}

char *next_word(char *w)
{

    while (isspace(*w) && *w)
    {
        ++w;
    }

    if (*w)
    {
        return w;
    }

    return NULL;
}

void test_nbr_words()
{
    puts("---------------- Test nbr_words ----------------");

    char *s1 = "Hello world!";
    printf("%s : %d, expected 2\n", s1, nbr_words(s1));

    char *s2 = "  Hello world!";
    printf("%s : %d, expected 2\n", s2, nbr_words(s2));

    char *s3 = "Hello world!  ";
    printf("%s : %d, expected 2\n", s3, nbr_words(s3));

    char *s4 = "   Hello   world!  ";
    printf("%s : %d, expected 2\n", s4, nbr_words(s4));

    char *s5 = "   Hello\t\tworld!  ";
    printf("%s : %d, expected 2\n", s5, nbr_words(s5));

    char *s6 = " a aa ba a bbbb ";
    printf("%s : %d, expected 5\n", s6, nbr_words(s6));

    puts("---------------- End Test nbr_words ----------------\n\n");
}
void test_word_len()
{
    puts("---------------- Test word_len ----------------");

    char *s1 = "Hello world!";
    printf("%s : %d, expected 5\n", s1, word_len(s1));

    char *s2 = "world!";
    printf("%s : %d, expected 6\n", s2, word_len(s2));

    char *s3 = "\t\tHello world!  ";
    printf("%s adr = s + 2: %d, expected 5\n", s3, word_len(s3 + 2));

    char *s4 = "   Hello   world!  ";
    printf("%s adr = s + 11: %d, expected 6\n", s4, word_len(s4 + 11));

    char *s5 = "   Hello\t\tworld!  ";
    printf("%s adr = s + 5: %d, expected 3\n", s5, word_len(s5 + 5));

    char *s6 = " abc d";
    printf("%s , adr = s + 1 : %d, expected 3\n", s6, word_len(s6 + 1));

    puts("---------------- End Test word_len ----------------\n\n");
}

void test_extract_word()
{
    puts("---------------- Test extract_word ----------------");
    int p = 0;

    char *s1 = "Hello world!";
    char *result = extract_word(s1, &p);
    printf("%s : %s, expected Hello\n", s1, result);
    printf("*pl = %d, expected 5\n\n", p);
    free(result);

    char *s2 = "world!";
    result = extract_word(s2, &p);
    printf("%s : %s, expected world!\n", s2, result);
    printf("*pl = %d, expected 6\n\n", p);
    free(result);

    char *s3 = "\t\tHello world!  ";
    result = extract_word(s3 + 2, &p);
    printf("%s adr = s + 2: %s, expected Hello\n", s3, result);
    printf("*pl = %d, expected 5\n\n", p);
    free(result);

    char *s4 = "   Hello   world!  ";
    result = extract_word(s4 + 11, &p);
    printf("%s adr = s + 11: %s, expected world!\n", s4, result);
    printf("*pl = %d, expected 6\n\n", p);
    free(result);

    char *s5 = "   Hello\t\tworld!  ";
    result = extract_word(s5 + 5, &p);
    printf("%s adr = s + 5: %s, expected llo\n", s5, result);
    printf("*pl = %d, expected 3\n\n", p);
    free(result);

    char *s6 = " abc d";
    result = extract_word(s6 + 1, &p);
    printf("%s , adr = s + 1 : %s, expected abc\n", s6, result);
    printf("*pl = %d, expected 3\n\n", p);
    free(result);

    puts("---------------- End Test extract_word ----------------\n\n");
}
void test_next_word()
{

    puts("---------------- Test next_word ----------------");

    char *s1 = "Hello world!";
    printf("%s : %s, expected world!\n", s1, next_word(s1 + 5));

    char *s2 = "world!";
    printf("%s adr = s + 6: %s, expected (null)\n", s2, next_word(s2 + 6));

    char *s3 = "\t\tHello world!  ";
    printf("%s : %s, expected Hello world!  \n", s3, next_word(s3));

    char *s4 = "   Hello   world!  ";
    printf("%s adr = s + 8: %s, expected world!  \n", s4, next_word(s4 + 8));

    char *s5 = "   Hello\t\tworld!  ";
    printf("%s adr = s + 16: %s, expected (null)\n", s5, next_word(s5 + 16));

    char *s6 = " abc d";
    printf("%s : %s, expected abc d\n", s6, next_word(s6));

    puts("---------------- End Test next_word ----------------\n\n");
}