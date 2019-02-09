#include <iostream>
#include <fstream>
#include "mdckp.hpp"


int main()
{
    mdckp::MDCKProblem p = mdckp::MDCKProblem::read_from_istream(std::cin);
    mdckp::solve(p);
    std::cout << p.solution_to_string() << std::endl;
    return 0;
}
