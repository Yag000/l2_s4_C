#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "ctype.h"

const char *MESSAGE = "Fëanor did nothing wrong!";

void fill(FILE *flux, unsigned n)
{

    for (unsigned i = 0; i < n; i++)
    {
        fputs(MESSAGE, flux);
        fputc('\n', flux);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("The program needs  2 arguments, the path and the number of lines to write into it.");
        return EXIT_FAILURE;
    }

    char *path = argv[1];

    for (unsigned i = 0; i < strlen(argv[2]); i++)
    {
        if (!isdigit(argv[2][i]))
        {
            printf("The second argument must be an integer.");
            return EXIT_FAILURE;
        }
    }

    int number_of_lines = atoi(argv[2]);

    if (number_of_lines < 0)
    {
        printf("The number of lines must be positive.");
        return EXIT_FAILURE;
    }

    FILE *flux = fopen(path, "a");

    assert(flux != NULL);

    fill(flux, number_of_lines);

    fclose(flux);

    return EXIT_SUCCESS;
}