//============================================================================================
//  FileName    : complex_api.h
//  Date        : 2020-12-01
//  Author      :
//  Desciption  : 


#ifndef __COMPLEX_API_H
#define __COMPLEX_API_H

#ifdef __cplusplus
extern  "C" {
#endif

typedef struct complex_t complex_c;

complex_c* createComplexObj(const double real, const double img);
void deleteComplexObj(complex_c** c);
double getReal(const complex_c* c);
double getImg(const complex_c* c);
// double getReal(const void* c);
// double getImg(const void* c);
complex_c* api_add(const complex_c* c1, const complex_c* c2);
double api_length(const complex_c* c);
double api_angleCosine(const complex_c* c1, const complex_c* c2);

#ifdef __cplusplus
}
#endif

#endif /* __COMPLEX_API_H */
