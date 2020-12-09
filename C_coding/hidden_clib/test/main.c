#include "complex_api.h"

#include <stdio.h>
#include <assert.h>



int main(const int argc, const char* argv[])
{
    complex_c* c1 = createComplexObj(1, 2);
    complex_c* c2 = createComplexObj(2, 1);
    complex_c* s = api_add(c1, c2);

    assert(getReal(s) == getImg(s));
    printf("sum:x,y: %f %f\n", getReal(s), getImg(s));

    complex_c* c = createComplexObj(3, 4);
    double lc = api_length(c);
    assert(lc == 5);
    printf("All test passed.\n");
    deleteComplexObj(&c1);
    deleteComplexObj(&c2);
    deleteComplexObj(&s);
    deleteComplexObj(&c);

    return 0;
}
