#include "afficheur.h"

node *cons_tree(int val, node *tl, node *tr);
void free_tree(node *t);
int size_tree(node *t);

void test_cons_tree();
void test_insert_abr();

int main()
{
    test_cons_tree();
    test_insert_abr();
    puts("");
    return EXIT_SUCCESS;
}

node *cons_tree(int val, node *tl, node *tr)
{
    node *t = malloc(sizeof(node));
    assert(t != NULL);
    t->val = val;
    t->left = tl;
    t->right = tr;
    return t;
}

void free_tree(node *t)
{
    if (t == NULL)
    {
        return;
    }
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

int size_tree(node *t)
{
    if (t == NULL)
    {
        return 0;
    }

    return size_tree(t->left) + size_tree(t->right) + 1;
}
int sum_tree(node *t)
{
    if (t == NULL)
    {
        return 0;
    }

    return size_tree(t->left) + sum_tree(t->right) + t->val;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int depth_tree(node *t)
{
    if (t == NULL)
    {
        return 0;
    }

    int left = depth_tree(t->left);
    int right = depth_tree(t->right);

    return max(left, right) + 1;
}

void print_abr(node *t)
{
    if (t == NULL)
    {
        return;
    }

    print_abr(t->left);
    printf("%d ", t->val);
    print_abr(t->right);
}

node *insert_abr(node *t, int val)
{
    if (t == NULL)
    {
        return cons_tree(val, NULL, NULL);
    }

    if (val < t->val)
    {
        t->left = insert_abr(t->left, val);
    }
    else
    {
        t->right = insert_abr(t->right, val);
    }
    return t;
}

node *search_abr(node *t, int val)
{
    if (t == NULL)
    {
        return NULL;
    }

    if (val < t->val)
    {
        return search_abr(t->left, val);
    }

    return insert_abr(t->right, val);
}
node *max_abr(node *t)
{
}
void test_cons_tree()
{
    node *t;
    t = cons_tree(1, cons_tree(3, NULL, NULL),
                  cons_tree(6, cons_tree(4, NULL, NULL), NULL));
    pretty_print(t);
    free(t);
}

void test_insert_abr()
{
    node *t = NULL;
    int vals[10] = {8, 3, 1, 2, 6, 4, 7, 10, 14, 13};

    for (int i = 0; i < 10; i++)
    {
        t = insert_abr(t, vals[i]);
    }

    pretty_print(t);
    print_abr(t);
}
