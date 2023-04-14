#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "ctype.h"

void fill(FILE *flux)
{

    char c = fgetc(stdin);

    while (c != EOF)
    {
        fputc(c, flux);
        c = fgetc(stdin);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("The program needs  1 argument : the path.");
        return EXIT_FAILURE;
    }

    char *path = argv[1];

    FILE *flux = fopen(path, "a");

    assert(flux != NULL);

    fill(flux);

    fclose(flux);

    return EXIT_SUCCESS;
}