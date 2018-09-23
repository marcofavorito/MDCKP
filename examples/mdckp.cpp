#include <iostream>
#include <fstream>
#include "mdckp.hpp"

int main()
{
    MDCKProblem p = MDCKProblem::read_from_istream(cin);
    solve(p);
    cout << p.solution_to_string() << endl;
    return 0;
}
