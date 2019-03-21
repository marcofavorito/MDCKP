#include "item.hpp"

namespace mdckp{

    Item::Item(const int id, const int profit, const int weight) : id(id), profit(profit), weight(weight) {}
    
    double Item::profitPerWeight(){ return float(profit) / weight; }
    bool Item::isAssigned(){ return this->assignment == NO_ASSIGNMENT;}
    void Item::resetAssignment() { this->assignment = NO_ASSIGNMENT; }
    
    // compare by mean, and break ties by considering 'worse' the Items with 'more' weight.
    bool Item::compare(Item &i, Item &j) {
        double i_ppw = i.profitPerWeight();
        double j_ppw = j.profitPerWeight();
        return i_ppw < j_ppw || (i_ppw == j_ppw && i.weight < j.weight); };
    
    bool Item::operator==(const Item &it) const {return this->id == it.id; }
    bool Item::operator<(const Item &it) const { return this->id < it.id; }
}

