#include "complex.h"

#include <stdio.h>
#include <iostream>

int main(const int argc, const char* argv[])
{
    printf("Hello CMake!\n");
    std::cout << "Hello CMake print by c++!" << std::endl;

    complexf32 c1 = {1.0f, 2.0f};
    complexf32 c2 = {2.0f, 2.0f};

    complexf32 sum = complexAdd(c1, c2);

    c1.printSelf();
    c2.printSelf();
    sum.printSelf();
    
    return 0;
}