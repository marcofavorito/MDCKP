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
          std::vector<Item *> items_by_increasing_profit_per_weight;
          std::vector<Item *> items_by_decreasing_profit_per_weight;
    
          static MDCKProblem read_from_istream(std::istream &is);
          int compute_score();
          std::string to_string();
          std::string solution_to_string();
    };
}

#endif
