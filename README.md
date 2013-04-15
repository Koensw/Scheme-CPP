Scheme-CPP
========

Simple Scheme C++ interpreter built just for fun. See also this Haskell implementation: https://github.com/arianvp/Haskeme/tree/develop/src/Language/Haskeme.

Installation
------------
1. g++ interpreter.cpp functions.cpp -o ./interpreter
2. ./interpreter < <file_to_parse>
3. results are printed to stdout

Functions
---------
- default functions are + and *. 
- you can add more functions in functions.cpp
- add the defined function to the init-procedure in interpreter.cpp

Bonus
---------
Small part of the solutions for the SICP (http://mitpress.mit.edu/sicp/full-text/book/book-Z-H-4.html) problems, where I learned Scheme from.