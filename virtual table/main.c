/* VIRTUAL TABLE
 * Authors:        Merijn Hendriks
 * License:        MIT License
 * Documentation:  see readme.md
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct A_vtbl A_vtbl;
typedef struct A A;

struct A_vtbl
{
    void (*print)(A* self);
};

struct A
{
    A_vtbl* vptr;
    int value;
};

static void A_print(A* self)
{
    printf("Value of a: %d\n", self->value);
}

static A_vtbl a_vtbl =
{
    A_print
};

static void A_ctor(struct A* self, int a)
{
    self->value = a;
    self->vptr = &a_vtbl;
}

int main()
{
    struct A a;
    
    A_ctor(&a, 1);
    
    a.vptr->print(&a);    
    
    return EXIT_SUCCESS;
}
