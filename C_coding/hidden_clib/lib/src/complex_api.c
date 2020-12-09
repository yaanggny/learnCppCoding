#include "complex_api.h"

#include "complex.h"

#include <stdlib.h>

complex_c* createComplexObj(const double real, const double img)
{
    complex_t* r = (complex_t*)malloc(sizeof(complex_t));
    r->x = real;
    r->y = img;

    return (complex_c*)r;
}

void deleteComplexObj(complex_c* *c)
{
    complex_c* p = *c;
    if(c != NULL)
    {
        free(p);
        p = NULL;
    }
}

double getReal(const complex_c* c)
{
    const complex_t*p = (complex_t*)c;
    return p->x;
}

double getImg(const complex_c* c)
{
    const complex_t* p = (complex_t*)c;
    return p->y;
}

complex_c* api_add(const complex_c* c1, const complex_c* c2)
{
    return (complex_c*)add((complex_t*)c1, (complex_t*)c2);
}

double api_length(const complex_c* c)
{
    return length((complex_t*)c);
}

double api_angleCosine(const complex_c* c1, const complex_c* c2)
{
    return angleCosine((complex_t*)c1, (complex_t*)c2);
}
