#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define iterations 100000000

int isInsideUnitDisk(double x, double y);
double computePi(int n);

int main()
{
    srand(time(NULL));

    double pi = computePi(iterations);

    printf("Pi is approximately : %lf\n", pi);
}

int isInsideUnitDisk(double x, double y)
{
    return sqrt(x * x + y * y) <= 1;
}

double computePi(int n)
{

    if (n <= 0)
    {
        return 0;
    }

    double x;
    double y;

    unsigned count = 0;
    for (unsigned i = 0; i < n; ++i)
    {
        x = ((double)rand()) / RAND_MAX;
        y = ((double)rand()) / RAND_MAX;

        if (isInsideUnitDisk(x, y))
        {
            ++count;
        }
    }

    return (4.0 * count) / n;
}