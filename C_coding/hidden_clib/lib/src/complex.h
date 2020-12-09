//============================================================================================
//  FileName    : complex.h
//  Date        : 2020-12-01
//  Author      :
//  Desciption  : 

#ifndef __COMPLEX_H
#define __COMPLEX_H

typedef struct 
{
    double x;   // real
    double y;   // img
}complex_t;

#ifdef __cplusplus
extern "C" {
#endif

double length(const complex_t* c);
double angleCosine(const complex_t* c1, const complex_t* c2);
complex_t* add(const complex_t* c1, const complex_t* c2);


#ifdef __cplusplus
}
#endif

#endif /* __COMPLEX_H */
