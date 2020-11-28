## About clang-format
`clang-format` is a tool of LLVM and can be used to format C/C++/Java/JavaScript/Objective-C/Protobuf/C# code.

For detailed introduction, see [official document](http://clang.llvm.org/docs/ClangFormat.html).

## Usage
- install LLVM 11.0 (lower versions are not tested)
- download the template file and rename to `.clang-format`
- run to format your code:
```shell
clang-format -i <file>.cpp
```