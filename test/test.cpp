#include <iostream>
#include "../include/mdckp.hpp"

int main()
{
    MDCKProblem p = MDCKProblem::read_from_stdin();

    cout << p.to_string() << endl;
    return 0;
}
