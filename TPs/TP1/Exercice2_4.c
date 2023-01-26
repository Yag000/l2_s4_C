#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned number = 0, sum = 0, numberOfInputs = 0;

    while (1)
    {
        printf("Entrez un entier : ");
        scanf("%u", &number);

        if (number == 0)
        {
            break;
        }

        sum += number;
        ++numberOfInputs;
    }

    if (numberOfInputs == 0)
    {
        printf("No input\n");
    }
    else
    {
        printf("La moyenne vaut : %f\n", numberOfInputs, (float)sum / numberOfInputs);
    }

    return EXIT_SUCCESS;
}
