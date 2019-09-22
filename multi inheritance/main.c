/* MULTI INHERITANCE
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
    int value;
};

struct C
{
    struct A baseA;
    struct B baseB;
    int value;
};

static void A_ctor(struct A* self, int a)
{
    self->value = a;
}

static void B_ctor(struct B* self, int b)
{
    self->value = b;
}

static void C_ctor(struct C* self, int a, int b)
{
    A_ctor(&self->baseA, a);
    B_ctor(&self->baseB, b);

    self->value = self->baseA.value + self->baseB.value;
}

int main()
{
    struct C c;
    
    C_ctor(&c, 1, 2);
    
    printf("Value of c: %d\n", c.value);
    printf("Value of b: %d\n", c.baseB.value);
    printf("Value of a: %d\n", c.baseA.value);
    
    return EXIT_SUCCESS;
}
