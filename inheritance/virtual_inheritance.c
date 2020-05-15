/* VIRTUAL INHERITANCE
 * Authors:        Merijn Hendriks
 * License:        MIT License
 * Documentation:  see readme.md
 */

#include <stdio.h>
#include <stdlib.h>

struct A
{
    int value;
};

struct B
{
    struct A* virtualA;
    struct A baseA;
    int value;
};

struct C
{
    struct A* virtualA;
    struct A baseA;
    int value;
};

struct D
{
    struct B baseB;
    struct C baseC;
    int value;
};

static void A_ctor(struct A* self, int a)
{
    if (!self)
    {
        return;
    }

    self->value = a;
}

static void B_ctor(struct B* self, struct A* virtualA, int a, int b)
{
    if (!self)
    {
        return;
    }

    self->virtualA = virtualA;
    A_ctor(virtualA, a);

    self->value = virtualA->value + b;
}

static void C_ctor(struct C* self, struct A* virtualA, int a, int c)
{
    if (!self)
    {
        return;
    }

    self->virtualA = virtualA;
    A_ctor(virtualA, a);

    self->value = virtualA->value + c;
}

static void D_ctor(struct D* self, int a, int b, int c)
{
    if (!self)
    {
        return;
    }

    B_ctor(&self->baseB, &self->baseB.baseA, a, b);
    C_ctor(&self->baseC, &self->baseB.baseA, a, c);

    self->value = self->baseB.value + self->baseC.value;
}

int main()
{
    struct D d;
    
    D_ctor(&d, 1, 2, 3);
    
    printf("Value of d: %d\n", d.value);
    printf("Value of d's b: %d\n", d.baseB.value);
    printf("Value of d's c: %d\n", d.baseC.value);
    printf("Value of b's virtual a: %d\n", d.baseB.virtualA->value);
    printf("Value of c's virtual a: %d\n", d.baseC.virtualA->value);
    printf("Value of b's base a: %d\n", d.baseB.baseA.value);
    printf("Value of c's base a: %d\n", d.baseC.baseA.value);
    
    return EXIT_SUCCESS;
}
