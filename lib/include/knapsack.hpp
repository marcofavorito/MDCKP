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
    
        bool isCompatible(Item &it);
        void addItem(Item &it);
        void removeItem(Item &it);
        int getResidualCapacity();
        std::set<int> fillGreedly(std::vector<Item *> &all_items);
    };
}

# endif
