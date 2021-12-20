#include "complex.h"

complexf32 complexAdd(const complexf32& c1, const complexf32& c2)
{
    return {c1.real + c2.real, c1.imag + c2.imag};
}