#include <iostream>

namespace name
{

} // namespace name

struct im_t
{
    int w, h;
    uchar* data;
};


bool imResize(im_t &dst, const im_t& src, const int dstH, const int dstW, int a, int b, const std::string& longstr, std::string& strOut);  // 引用靠左靠右

class Class1
{
private:
    /* data */
    struct struct1
    {
        int a;
        int b;
    };
    int x;
    double y;
        
public:
    Class1(/* args */);
    ~Class1();
};

Class1::Class1(/* args */)
{
}

Class1::~Class1()
{
}



bool imResize(im_t *dst, const im_t* src, const int dstH, const int dstW)  // 指针靠左靠右
{
    if (dst == NULL || src == NULL)
    {
        return false;
    }
    if (dstH < 0 || dstW < 0)
    {
        return false;
    }
    for (size_t i = 0; i < count; i++)
    {
        int step = y * imW;
        uint8* *pri             = (uint8*)src->data + step;        
        uint8* aLongRow = (uint8*)dst->data + step;
    }

    int srcH      = src->h;
    int srcW      = src->w;
    double sum    = 2.3; // asad
    std::string s = "";  // asdda

    int *v = new int[10];
    int a = 2;

    switch (a)
    {
    case 2:
        double x = 1;
        x();
        break;
    case 1:
    x = 3;
    return false;

    default:
        break;
    }

    return true;
}

class TClassM
{
private:
    /* data */
    double d;

public:
    TClassM(/* args */);
    ~TClassM();
};

TClassM::TClassM(/* args */)   // 两行会换行
{
    d        = 0;
    double x = 3;
}

TClassM::~TClassM() { d = 0; }   // 能保持一行

void func(int a) {
    assert(a >= 0);
}

template <typename T>
T add(const T& x, const T &y) {
    if(x >10){
        return T(-1);
    }
    else if(x < 20)
    {                
    }
    return x + y;
}
