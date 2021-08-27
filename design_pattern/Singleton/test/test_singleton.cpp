#include "Singleton.h"

// int main(int argc, char *argv[])
int test_singleton()
{
    Singleton& s1 = Singleton::getInstance();

    s1.printSelf(__FILE__);

    Singleton *p1 = &s1;
    
    return 0;
}