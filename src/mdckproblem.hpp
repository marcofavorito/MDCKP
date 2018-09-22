#ifndef MDCKPROBLEM_H
#define MDCKPROBLEM_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>

#include "item.hpp"
#include "knapsack.hpp"

using namespace std;

class MDCKProblem{
    public:
      int n, m;
      int score = 0;
      vector<Knapsack> knapsacks;
      vector<Item> items;
      vector<Item *> items_by_increasing_profit_per_weight;
      vector<Item *> items_by_decreasing_profit_per_weight;

      static MDCKProblem read_from_stdin();
      string to_string();
      string solution_to_string();
};

#endif