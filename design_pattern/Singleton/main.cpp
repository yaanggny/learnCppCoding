#include "Singleton.h"
#include "test_singleton.h"

#include <cassert>

int main(int argc, char *argv[])
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    test_singleton();

    s1.printSelf(__FILE__);
    s2.printSelf(__FILE__);

    Singleton *p1 = &s1;
    Singleton *p2 = &s2;
    // assert(p1 != p2);
    
    return 0;
}