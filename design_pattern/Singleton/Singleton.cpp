#include "Singleton.h"

#include <stdio.h>

Singleton::Singleton()
{
    printf("%s(): line:%d:  Constructor called. %p\n", __func__, __LINE__, this);
}

Singleton::~Singleton()
{
    printf("%s(): line:%d:  deConstructor called. %p\n", __func__, __LINE__, this);
}

// static void Singleton::printSelf()
// {
//     printf("%s(): line:%d:  %p\n", __func__, __LINE__, this);
// }

void Singleton::printSelf(const std::string& ext) const
{
    std::string s = "";
    if(! ext.empty())
        s+= ext + ":";
    printf("%s%s():line:%d:  %p\n", s.c_str(), __func__, __LINE__, this);
}

// static 
Singleton& Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}
