# MDCKP

![](https://img.shields.io/badge/version-c%2B%2B14-ff69b4.svg)

Multiple Disjunctively Constrained Knapsak problem: definition and an approximation algorithm implementation.

The problem is formally explained in [this document](https://github.com/MarcoFavorito/MDCKP/blob/master/docs/main.pdf).
In this repo you can find also an implementation in C++ of a naive algorithm for a simple solution.

- [How to use](#how-to-use)
- [Use it in your project](#use-in-your-project)
- [Input and output file formats](#input-and-output-file-formats)

## How to use

- Build the software:
```
make
```

- Run the algorithm:
```
LD_LIBRARY_PATH="./lib" bin/mdckp < input_file
```

### Example:
```
LD_LIBRARY_PATH="./lib" bin/mdckp < data/input_test_2
```

- Test it with:

It should print:
```
71
1 5 9 13
2 3 4
0 12
6 7 10
```

See [output format](#input-and-output-file-formats) for more details.

For the source of this example, look at [`examples/mdckp.cpp`](https://github.com/MarcoFavorito/MDCKP/blob/master/examples/mdckp.cpp).

## Use in your project

- Do `make`. Now in `lib` you should have `libmdckp.so.1`
- In your code, `#include "mdckp.hpp"`, that you can find in [`include/mdckp.hpp`](https://github.com/MarcoFavorito/MDCKP/blob/master/include/mdckp.hpp)
- Compile your source file (e.g. `myprog.cpp`) with the following:
```
g++ myprog.cpp -o myprog -I<include-dir> -L<lib-dir> -lmdckp -std=c++14
```

where `<include-dir>` and `<lib-dir>` are, respectively, the directories where `mdckp.hpp` and `libmdckp.so.1` are stored.

## Input and output file formats

### Input format

```N M
c1 c2 c3 ... cm
p1 w1
p2 w2
...
pn wn
e11 e12
e21 e22
...
```

where:
```
N = number of items
M = number of knapsacks
pi = profit of item i
wi = weight of item i
cj = capacity of knapsack j
ex ey = pair of items id that are not compatible
```

- Example (`data/input_test_1`):
```
2 1
10
20 5
10 5
0 1
```
- There are `2` items and `1` knapsack
- The knapsack has capacity `10`
- item `0` has profit `20` and weight `5`
- item `1` has profit `10` and weight `5`
- item `0` and item `1` are incompatible.


### Output format
```
S
x11 x21 ...
...
x1m x2m ...
```

where:

```
S = total score
x1j x2j ... = ids of items assigned to knapsack j
```

- Example:
```
20
0
```
- The total profit of the following assignment is `20`;
- To the first knapsack (knapsack `0`) has been assigned the item `0`

Try it out:
```
LD_LIBRARY_PATH="./lib" ./bin/mdckp < data/input_test_1
```
