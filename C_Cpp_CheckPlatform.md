# C++判断系统/平台  
参考： [CPROFILE](https://github.com/skywind3000/collection/tree/master/vintage/cprofile)
```c++
//---------------------------------------------------------------------
// 平台判断
//---------------------------------------------------------------------
#if (defined(_WIN32) && !defined(WIN32))
	#define WIN32 _WIN32
#elif (defined(WIN32) && !defined(_WIN32))
	#define _WIN32 WIN32
#endif

#if (defined(_WIN32) && !defined(_MSC_VER))
	#ifndef __i386__
	#define __i386__
	#endif
#elif defined(_MSC_VER)
	#if (defined(_M_IX86) && !defined(__i386__))
	#define __i386__
	#endif
#endif

#ifndef __i386__
	#if (defined(__386__) || defined(__I386__) || _M_IX86)
	#define __i386__
	#endif
#endif

#if (defined(__i386__) && !defined(__I386__))
	#define __I386__
#endif

#if (defined(__unix)) && (!defined(CHAVE_QPC) && defined(__i386__))
	#define CHAVE_QPC
#endif
```
