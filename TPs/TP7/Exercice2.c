#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    int nbr;
    char **words;
} w_index;

void free_index(w_index *pi);
void print_index(w_index *pi);
int size_words(w_index *pi);
char *concat_words(w_index *pi);
w_index *cons_index(const char *s);

