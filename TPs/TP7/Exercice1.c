#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

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

void test_nbr_words() {}
void test_word_len() {}
void test_extract_word() {}
void test_next_word() {}