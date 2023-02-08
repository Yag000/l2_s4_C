
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

struct fraction
{
    long int num;
    long int den;
};

typedef struct fraction fraction;

fraction build(long int num, long int den);
bool eq_fraction(fraction f, fraction g);
bool is_int(fraction f);

fraction sum(fraction f, fraction g); // somme
fraction sub(fraction f, fraction g); // soustraction
fraction mul(fraction f, fraction g); // multiplication

fraction reduce(fraction f);
long int pgcd(long int a, long int b);

void testEqFraction();
void testis_int();
void testSum();
void testSub();
void testMul();
void testReduce();

void testEqFractionExFractions(fraction ex_fractions[], size_t n);
void testIsIntExFractions(fraction ex_fractions[], size_t n);
void testSumExFractions(fraction ex_fractions[], size_t n);
void testSubExFractions(fraction ex_fractions[], size_t n);
void testMulExFractions(fraction ex_fractions[], size_t n);
void testReduceExFractions(fraction ex_fractions[], size_t n);

int main()
{
    fraction ex_fractions[7] = {build(1, 1), build(1, 2), build(2, 4), build(-9, 3), build(8, -20), build(-5, -1), build(1, -3)};

    puts("Test avec des fractions construites à la main");

    testEqFraction();
    testis_int();
    testSum();
    testSub();
    testMul();
    testReduce();

    puts("\nTest avec des fractions construites à partir de ex_fractions");

    testEqFractionExFractions(ex_fractions, 7);
    testIsIntExFractions(ex_fractions, 7);
    testSumExFractions(ex_fractions, 7);
    testSubExFractions(ex_fractions, 7);
    testMulExFractions(ex_fractions, 7);
    testReduceExFractions(ex_fractions, 7);

    return EXIT_SUCCESS;
}

fraction build(long int num, long int den)
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
    long int p = pgcd(f.num, f.den);

    if (p < 0)
        p = -p;

    if (f.den < 0)
    {
        f.num = -f.num;
        f.den = -f.den;
    }

    fraction g = {f.num / p, f.den / p};
    return g;
}

long int pgcd(long int a, long int b)
{
    long int x = a;
    long int y = b;

    while (y != 0)
    {
        long int r = x % y;
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

void testis_int()
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

    puts("Test is_int int passed");
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
    fraction f = reduce(build(2, 4));
    fraction g = build(1, 2);
    assert(f.num == g.num && f.den == g.den);

    f = reduce(build(2, 3));
    g = build(2, 3);
    assert(f.num == g.num && f.den == g.den);

    f = reduce(build(6, 4));
    g = build(3, 2);
    assert(f.num == g.num && f.den == g.den);

    f = reduce(build(2, -4));
    g = build(-1, 2);
    assert(f.num == g.num && f.den == g.den);

    f = reduce(build(-2, 4));
    g = build(-1, 2);
    assert(f.num == g.num && f.den == g.den);

    f = reduce(build(-2, -4));
    g = build(1, 2);
    assert(f.num == g.num && f.den == g.den);

    puts("Test reduce passed");
}

void testEqFractionExFractions(fraction ex_fractions[], size_t n)
{

    assert(eq_fraction(ex_fractions[1], ex_fractions[2]));
    assert(eq_fraction(ex_fractions[3], build(-3, 1)));
    assert(eq_fraction(ex_fractions[4], build(-2, 5)));

    puts("Test eq_fraction ex_fractions passed");
}

void testIsIntExFractions(fraction ex_fractions[], size_t n)
{
    assert(is_int(ex_fractions[0]));
    assert(!is_int(ex_fractions[1]));
    assert(!is_int(ex_fractions[2]));
    assert(is_int(ex_fractions[3]));
    assert(!is_int(ex_fractions[4]));
    assert(is_int(ex_fractions[5]));
    assert(!is_int(ex_fractions[6]));

    puts("Test is_int int ex_fractions passed");
}

void testSumExFractions(fraction ex_fractions[], size_t n)
{
    assert(eq_fraction(sum(ex_fractions[1], ex_fractions[2]), ex_fractions[0]));
    assert(eq_fraction(sum(ex_fractions[2], ex_fractions[3]), build(-5, 2)));

    puts("Test sum ex_fractions passed");
}

void testSubExFractions(fraction ex_fractions[], size_t n)
{
    assert(eq_fraction(sub(ex_fractions[0], ex_fractions[3]), build(4, 1)));
    assert(eq_fraction(sub(ex_fractions[1], ex_fractions[2]), build(0, 1)));
    assert(eq_fraction(sub(ex_fractions[5], ex_fractions[3]), build(8, 1)));

    puts("Test sub ex_fractions passed");
}

void testMulExFractions(fraction ex_fractions[], size_t n)
{

    assert(eq_fraction(mul(ex_fractions[0], ex_fractions[1]), ex_fractions[1]));
    assert(eq_fraction(mul(ex_fractions[2], ex_fractions[1]), build(1, 4)));
    assert(eq_fraction(mul(ex_fractions[3], ex_fractions[5]), build(-15, 1)));

    puts("Test mul ex_fractions passed");
}

void testReduceExFractions(fraction ex_fractions[], size_t n)
{
    fraction result = reduce(ex_fractions[2]);
    assert(result.num == 1 && result.den == 2);

    result = reduce(ex_fractions[0]);
    assert(result.num == 1 && result.den == 1);

    result = reduce(ex_fractions[3]);
    assert(result.num == -3 && result.den == 1);

    result = reduce(ex_fractions[4]);
    assert(result.num == -2 && result.den == 5);

    result = reduce(ex_fractions[5]);
    assert(result.num == 5 && result.den == 1);

    result = reduce(ex_fractions[6]);
    assert(result.num == -1 && result.den == 3);

    puts("Test reduce ex_fractions passed");
}
