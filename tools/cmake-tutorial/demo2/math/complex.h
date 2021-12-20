#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <stdio.h>

struct complexf32
{
    float real, imag;   
    void printSelf() const 
    {
        printf("%.2f+%.2fi\n", real, imag);
    } 
};

complexf32 complexAdd(const complexf32& c1, const complexf32& c2);


#endif /* __COMPLEX_H */
