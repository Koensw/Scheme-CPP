Lisp-CPP
========

Simple Lisp C++ interpreter build just for fun. See also this Haskell implementation: https://github.com/arianvp/Haskeme/tree/develop/src/Language/Haskeme.

==INSTALLATION==
1. g++ interpreter.cpp functions.cpp -o ./interpreter
2. ./interpreter < <file_to_parse>
3. results are printed to stdout

==FUNCTIONS==
- default functions are + and *. 
- you can add more functions in functions.cpp
- add the defined function to the init-procedure in interpreter.cpp
