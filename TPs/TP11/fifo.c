#include "fifo.h"

static void *decale(void *f, size_t d)
{
    return (char *)f + d;
}

fifo create_fifo(size_t capacite_init, size_t taille_elem)
{

    fifo liste = malloc(sizeof(fifo));

    void *first = malloc(capacite_init * taille_elem);
    liste->first = first;
    liste->last = decale(first, capacite_init * taille_elem);
    liste->occupe = first;
    liste->libre = liste->occupe;

    return liste;
}

void delete_fifo(fifo f)
{
    free(f->first);
    free(f);
}

int empty_fifo(fifo f)
{
    return f->occupe - f->libre == 0 ? 1 : 0;
}

void *get_fifo(fifo f, void *element)
{

    void *element = malloc(f->te);
    memmove(element, f->occupe, f->te);
    f->occupe = deplace(f->occupe, f->te);

    return element;
}