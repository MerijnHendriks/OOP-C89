/* UPCASTING
 * Authors:        Merijn Hendriks
 * License:        MIT License
 * Documentation:  see readme.md
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct A A;
typedef struct B B;

struct A
{
    int x;
};

struct B
{
    A base;
    int y;
};

static void A_ctor(A* self, int x)
{
    if (!self)
    {
        return;
    }

    self->x = x;
}

static void B_ctor(B* self, int x, int y)
{
    if (!self)
    {
        return;
    }

    A_ctor(&self->base, x);
    
    self->y = y;
}

int main()
{
    B b;
    
    B_ctor(&b, 1, 2);
    A_ctor(&b.base, 3);
    
    printf("%d\n", b.base.x);

    return EXIT_SUCCESS;
}
