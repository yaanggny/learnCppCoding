#ifndef __SINGLETON_H
#define __SINGLETON_H

#include <string>

class Singleton
{
public:
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    void printSelf(const std::string& ext="") const;
    static Singleton& getInstance();
private:
    ~Singleton();
    Singleton();
};

#endif