#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>
#include <set>
#include "item.hpp"

namespace mdckp{

    class Knapsack
    {
      public:
        int id;
        int capacity;
        int occupied_space = 0;
        int total_profit = 0;
        ItemPtrSet items;
        std::set<int> item_ids;
        
        Knapsack(int id, int capacity);
    
        bool is_compatible(Item &it);
        void add_item(Item &it);
        void remove_item(Item &it);
        int get_residual_capacity();
        std::set<int> fill_greedly(std::vector<Item *> &all_items);
    };
}

# endif
