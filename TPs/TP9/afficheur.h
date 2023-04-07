#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;
struct node
{
    int val;
    node *left;
    node *right;
};

void print_head(int depth, int addr);
void pretty_print(node *t);
void pretty_rec(node *t, int depth, int addr);

#endif