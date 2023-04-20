#include "fifo.h"

static void *decale(void *f, size_t d)
{
    return (char *)f + d;
}

fifo create_fifo(size_t capacite_init, size_t taille_elem)
{
    void *first = malloc(capacite_init * taille_elem);
    void *last = decale(first, capacite_init * taille_elem);

    void *occupe = decale(first, taille_elem);
    void *libre = occupe;

    fifo liste = {first, last, taille_elem, occupe, libre};
    return liste;
}