#include "naive_algorithm.hpp"


void assign_items_greedily(MDCKProblem &problem){
    vector<Item *> &items = problem.items_by_decreasing_profit_per_weight;
    // for (Item *item: items){
    //     cout << item->id << " " << endl;
    // }
    set<int> total_inserted_items;
    set<int> inserted_items;
    for (Knapsack &k : problem.knapsacks)
    {
        inserted_items = k.fill_greedly(items);
    }
}

void solve(MDCKProblem &problem){
    assign_items_greedily(problem);
}