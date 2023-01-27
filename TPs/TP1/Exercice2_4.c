#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned number = 0, sum = 0, numberOfInputs = -1;

    do
    {
        printf("Entrez un entier : ");
        scanf("%u", &number);

        sum += number;
        ++numberOfInputs;
    } while (number != 0);

    if (numberOfInputs == 0)
    {
        printf("Pas de input\n");
    }
    else
    {
        printf("La moyenne vaut : %f\n", (float)sum / numberOfInputs);
    }

    return EXIT_SUCCESS;
}
