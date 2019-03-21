#include "knapsack.hpp"
#include <algorithm>

namespace mdckp{

    Knapsack::Knapsack(int id, int capacity)
    {
        this->id = id;
        this->capacity = capacity;
    }
    
    bool Knapsack::isCompatible(Item &it){
        std::set<int> common_ids;
        std::set_intersection(this->item_ids.begin(), this->item_ids.end(),
                         it.incompatible_items_ids.begin(), it.incompatible_items_ids.end(),
                         inserter(common_ids, common_ids.begin()));
        return common_ids.size()==0;
    }
    
    void Knapsack::addItem(Item &it){
        this->items.insert(&it);
        this->item_ids.insert(it.id);
        this->total_profit += it.profit;
        it.assignment = this->id;
    }
    
    void Knapsack::removeItem(Item &it){
        this->items.erase(&it);
        this->item_ids.erase(it.id);
        this->total_profit -= it.profit;
        it.resetAssignment();
    }
    
    int Knapsack::getResidualCapacity(){
        return this->capacity - this->occupied_space;
    }
    
    std::set<int> Knapsack::fillGreedly(std::vector<Item *> &all_items){
        std::set<int> inserted_bricks_ids;
        for (Item *&it : all_items)
        {
            if (it->isAssigned() && this->isCompatible(*it))
            {
                this->addItem(*it);
                inserted_bricks_ids.insert(it->id);
            }
        }
    
        return inserted_bricks_ids;
    }
}

