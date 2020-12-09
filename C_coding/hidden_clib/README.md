## a C demo lib hiding implementation details
### lib structure
```
hidden_clib/
|-- CMakeLists.txt
|-- README.md
|-- build
|-- install
|   `-- Windows
|       |-- bin
|       |   `-- complex_test.exe
|       |-- include
|       |   `-- complex_api.h
|       `-- lib
|           |-- complex_math.lib
|           `-- libcomplex_math.a
|-- lib
|   |-- CMakeLists.txt
|   |-- inc
|   |   `-- complex_api.h
|   `-- src
|       |-- CMakeLists.txt
|       |-- complex.c
|       |-- complex.h
|       `-- complex_api.c
`-- test
    |-- CMakeLists.txt
    `-- main.c
```
### build 
1. Windows
- build with `Nmake`
```shell
# cd to `build`
cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug ..\hidden_clib
nmake
nmake install
```
- build with `Ninja`
```
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug ..\hidden_clib
ninja
ninja install
```

2. Linux
```shell
# cd to `build`
cmake -DCMAKE_BUILD_TYPE=Debug ../hidden_clib
nmake
nmake install
```