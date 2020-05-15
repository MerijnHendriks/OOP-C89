/* INHERITANCE
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
    struct A baseA;
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

static void B_ctor(struct B* self, int a, int b)
{
    if (!self)
    {
        return;
    }

    A_ctor(&self->baseA, a);
    
    self->value = self->baseA.value + b;
}

int main()
{
    struct B b;
    
    B_ctor(&b, 1, 2);
    
    printf("Value of b: %d\n", b.value);
    printf("Value of a: %d\n", b.baseA.value);
    
    return EXIT_SUCCESS;
}
