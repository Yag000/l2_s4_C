
#include "afficheur.h"

void print_head(int depth, int addr)
{
    if (depth > 1)
    {
        int pre = addr / 2;
        print_head(depth - 1, pre);
        printf("%s", (pre % 2) != (addr % 2) ? "|    " : "     ");
        return;
    }
    if (depth == 1)
        printf("     ");
}

void pretty_rec(node *t, int depth, int addr)
{
    if (t == NULL)
    {
        return;
    }
    pretty_rec(t->right, depth + 1, 2 * addr + 1);
    print_head(depth, addr);
    const char *s = (depth == 0) ? "─" : addr & 1 ? "┌"
                                                  : "└";
    printf("%s────%d\n", s, t->val);
    pretty_rec(t->left, depth + 1, 2 * addr);
}

// fonction principale d'affichage.
void pretty_print(node *t)
{
    pretty_rec(t, 0, 0);
}