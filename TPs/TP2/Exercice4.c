
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct fraction
{
    long num;
    int den;
};

typedef struct fraction fraction;

fraction build(long num, int den);
bool eq_fraction(fraction f, fraction g);
bool is_int(fraction f);

fraction sum(fraction f, fraction g); // somme
fraction sub(fraction f, fraction g); // soustraction
fraction mul(fraction f, fraction g); // multiplication

fraction reduce(fraction f);
int pgcd(int a, int b);

void testEqFraction();
void testIsInt();
void testSum();
void testSub();
void testMul();

int main(int argc, char const *argv[])
{
    fraction ex_fractions[7] = {build(1, 1), build(1, 2), build(2, 9), build(-9, 3), build(8, -20), build(-5, -1), build(1, -3)};

    testEqFraction();
    testIsInt();
    testSum();
    testSub();
    testMul();
    testReduce();

    return EXIT_SUCCESS;
}

fraction build(long num, int den)
{
    assert(den != 0);
    fraction f = {num, den};
    return f;
}

bool eq_fraction(fraction f, fraction g)
{
    return f.num * g.den == g.num * f.den;
}

bool is_int(fraction f)
{
    return f.num % f.den == 0;
}

fraction sum(fraction f, fraction g)
{
    fraction h = {f.num * g.den + g.num * f.den, f.den * g.den};
    return h;
}

fraction sub(fraction f, fraction g)
{
    fraction h = {f.num * g.den - g.num * f.den, f.den * g.den};
    return h;
}

fraction mul(fraction f, fraction g)
{
    fraction h = {f.num * g.num, f.den * g.den};
    return h;
}

fraction reduce(fraction f)
{
    int p = pgcd(f.num, f.den);
    fraction g = {f.num / p, f.den / p};
    return g;
}

int pgcd(int a, int b)
{
    int x = a;
    int y = b;

    while (y != 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }

    return x;
}

void testEqFraction()
{
    fraction f = build(1, 2);
    fraction g = build(2, 4);
    fraction h = build(3, 6);
    fraction i = build(1, 3);
    fraction j = build(1, 4);

    assert(eq_fraction(f, g));
    assert(eq_fraction(g, h));
    assert(!eq_fraction(f, i));
    assert(!eq_fraction(f, j));

    puts("Test eq_fraction passed");
}

void testIsInt()
{
    fraction f = build(2, 1);
    fraction g = build(4, 2);
    fraction h = build(6, 3);
    fraction i = build(1, 3);
    fraction j = build(1, 4);

    assert(is_int(f));
    assert(is_int(g));
    assert(is_int(h));
    assert(!is_int(i));
    assert(!is_int(j));

    puts("Test is_int passed");
}

void testSum()
{
    fraction f = build(1, 2);
    fraction g = build(1, 3);
    fraction h = build(5, 6);

    assert(eq_fraction(sum(f, g), h));

    puts("Test sum passed");
}

void testSub()
{
    fraction f = build(1, 2);
    fraction g = build(1, 3);
    fraction h = build(1, 6);

    assert(eq_fraction(sub(f, g), h));

    puts("Test sub passed");
}

void testMul()
{
    fraction f = build(1, 2);
    fraction g = build(1, 3);
    fraction h = build(1, 6);

    assert(eq_fraction(mul(f, g), h));

    puts("Test mul passed");
}

void testReduce()
{
    fraction f = build(2, 4);
    fraction g = build(1, 2);

    assert(eq_fraction(reduce(f), g));

    f = build(2, 3);
    g = build(2, 3);

    assert(eq_fraction(reduce(f), g));

    f = build(6, 4);
    g = build(3, 2);

    assert(eq_fraction(reduce(f), g));
    puts("Test reduce passed");
}
