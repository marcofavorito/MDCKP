#ifndef MDCKPROBLEM_HPP
#define MDCKPROBLEM_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>

#include "item.hpp"
#include "knapsack.hpp"

namespace mdckp{

    class MDCKProblem{
        public:
          int n, m;
          int score = 0;
          std::vector<Knapsack> knapsacks;
          std::vector<Item> items;
          std::vector<Item *> itemsByIncreasingProfitPerWeight;
          std::vector<Item *> itemsByDecreasingProfitPerWeight;
    
          static MDCKProblem readFromIstream(std::istream &is);
          int computeScore();
          std::string toString();
          std::string solutionToString();
    };
}

#endif
