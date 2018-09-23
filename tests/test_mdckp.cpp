#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "mdckp.hpp"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int solve(string path)
{
    ifstream myfile;
    myfile.open(path);
    MDCKProblem p = MDCKProblem::read_from_istream(myfile);
    solve(p);
    return p.compute_score();
}

TEST_CASE("Test case")
{
    REQUIRE(solve("data/input_test_2") == 71);
}