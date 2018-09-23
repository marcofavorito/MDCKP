# MDCKP
Multiple Disjunctively Constrained Knapsak problem: definition and an approximation algorithm implementation.

The problem is formally explained in [this document](https://github.com/MarcoFavorito/MDCKP/blob/master/docs/main.pdf).
In this repo you can find also an implementation in C++ of a naive algorithm for a simple solution.

## How to use

- Build the software:
```
make
```

- Run the algorithm:
```
bin/mdckp < input_file
```

## Examples
```
bin/mdckp < data/input_test_1
```

For the source, look at [`examples/mdckp.cpp`](https://github.com/MarcoFavorito/MDCKP/blob/master/examples/mdckp.cpp).

## Use in your project

- Do `make`. Now in `lib` you should have `libmdckp.so.1`
- In your code, `#include "mdckp.hpp"`, that you can find in [`include/mdckp.hpp`](https://github.com/MarcoFavorito/MDCKP/blob/master/include/mdckp.hpp)
- Compile your source file (e.g. `myprog.cpp`) with the following:
```
g++ myprog.cpp -o myprog -I<include-dir> -L<lib-dir> -lmdckp -std=c++14
```

where `<include-dir>` and `<lib-dir>` are, respectively, the directories where `mdckp.hpp` and `libmdckp.so.1` are stored.
- Test it with:

```
LD_LIBRARY_PATH="<lib-dir>" myprog < data/input_test_2
```

It should print:
```71
1 5 9 13
2 3 4
0 12
6 7 10
```
