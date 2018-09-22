#include <iostream>
#include "../include/mdckp.hpp"

int main()
{
    MDCKProblem p = MDCKProblem::read_from_stdin();
    solve(p);
    cout << p.solution_to_string() << endl;
    return 0;
}
