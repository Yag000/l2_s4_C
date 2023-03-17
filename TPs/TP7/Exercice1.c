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

    char *res = malloc((*pl) * sizeof(char));
    memmove(res, w, (*pl) * sizeof(char));
    res[*pl] = '\0';

    return res;
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
    char *result1 = extract_word(s1, &p);
    printf("%s : %s, expected Hello\n", s1, result1);
    printf("*pl = %d, expected 5\n\n", p);
    free(result1);

    char *s2 = "world!";
    char *result2 = extract_word(s2, &p);
    printf("%s : %s, expected world!\n", s2, result2);
    printf("*pl = %d, expected 6\n\n", p);
    free(result2);

    char *s3 = "\t\tHello world!  ";
    char *result3 = extract_word(s3 + 2, &p);
    printf("%s adr = s + 2: %s, expected Hello\n", s3, result3);
    printf("*pl = %d, expected 5\n\n", p);
    free(result3);

    char *s4 = "   Hello   world!  ";
    char *result4 = extract_word(s4 + 11, &p);
    printf("%s adr = s + 11: %s, expected world!\n", s4, result4);
    printf("*pl = %d, expected 6\n\n", p);
    free(result4);

    char *s5 = "   Hello\t\tworld!  ";
    char *result5 = extract_word(s5 + 5, &p);
    printf("%s adr = s + 5: %s, expected llo\n", s5, result5);
    printf("*pl = %d, expected 3\n\n", p);
    free(result5);

    char *s6 = " abc d";
    char *result6 = extract_word(s6 + 1, &p);
    printf("%s , adr = s + 1 : %s, expected abc\n", s6, result6);
    printf("*pl = %d, expected 3\n\n", p);
    free(result6);

    puts("---------------- End Test extract_word ----------------\n\n");
}
void test_next_word() {}