#include "naive_algorithm.hpp"

namespace mdckp{

    void assign_items_greedily(MDCKProblem &problem){
        std::vector<Item *> &items = problem.itemsByDecreasingProfitPerWeight;
        std::set<int> total_inserted_items;
        std::set<int> inserted_items;
        for (Knapsack &k : problem.knapsacks)
        {
            inserted_items = k.fillGreedly(items);
        }
    }
    
    void solve(MDCKProblem &problem){
        assign_items_greedily(problem);
    }
}
