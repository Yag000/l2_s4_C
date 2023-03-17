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

            words_found++;
            is_inside_word = true;
        }
    }

    return words_found;
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
}
void test_word_len() {}
void test_extract_word() {}
void test_next_word() {}