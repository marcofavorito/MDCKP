#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include "mdckp.hpp"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int solve(string path)
{
    ifstream myfile;
    myfile.open(path);
    mdckp::MDCKProblem p = mdckp::MDCKProblem::readFromIstream(myfile);
    mdckp::solve(p);
    return p.computeScore();
}

TEST_CASE("read from file 1", "[mdckp]")
{
    REQUIRE(solve("data/input_test_1") == 20);
}

TEST_CASE("read from file 2", "[mdckp]")
{
    REQUIRE(solve("data/input_test_2") == 71);
}

