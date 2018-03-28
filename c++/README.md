C++ OS
======================

[sarah]: https://github.com/percy00010/sarah-cmd

  - [Introduction](#introduction)
  - [Library](#library)

## Introduction ##
## Library ##

### Static Library ###
  Generate.
    * g++ -std=c++11 -c file1.cpp
    * g++ -std=c++11 -c file2.cpp
    * ar rsv mylib.a file1.o file2.o
    * g++ -std=c++11 -o main main.cpp mylib.a
### Dynamic Library ###
  Generate.
    * g++ -std=c++11 -fPIC -c file1.cpp
    * g++ -std=c++11 -fPIC -c file2.cpp
    * g++ -std=c++11 -shared -o mylib.so file1.o file2.o

<!--:sparkles: :camel: :boom:-->

* * *
[Percy Maldonado Quispe UCSP](https://github.com/percy00010)

