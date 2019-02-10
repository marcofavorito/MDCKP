#include "naive_algorithm.hpp"

namespace mdckp{

    void assign_items_greedily(MDCKProblem &problem){
        std::vector<Item *> &items = problem.items_by_decreasing_profit_per_weight;
        // for (Item *item: items){
        //     cout << item->id << " " << endl;
        // }
        std::set<int> total_inserted_items;
        std::set<int> inserted_items;
        for (Knapsack &k : problem.knapsacks)
        {
            inserted_items = k.fill_greedly(items);
        }
    }
    
    void solve(MDCKProblem &problem){
        assign_items_greedily(problem);
    }
}
