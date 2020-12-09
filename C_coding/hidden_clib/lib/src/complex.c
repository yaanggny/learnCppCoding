#include "complex.h"

#include <math.h>
#include <stdlib.h>

double length(const complex_t* c)
{
    double t = c->x*c->x + c->y*c->y;
    return sqrt(t);
}

double angleCosine(const complex_t* c1, const complex_t* c2)
{
    double l1 = length(c1);
    double l2 = length(c2);
    double num = c1->x*c2->x + c1->y*c2->y;
    return num/(l1*l2);
}

complex_t* add(const complex_t* c1, const complex_t* c2)
{
    complex_t* r = (complex_t*)malloc(sizeof(complex_t));
    r->x = c1->x + c2->x;
    r->y = c1->y + c2->y;
    return r;
}
