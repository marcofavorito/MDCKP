#ifndef ITEM_HPP
#define ITEM_HPP

#include <set>

namespace mdckp{

    class Item
    {
      private:
        int NO_ASSIGNMENT = -1;
      public:
        const int id;
        const int profit;
        const int weight;
        int assignment = NO_ASSIGNMENT;
        std::set<int> incompatible_items_ids;
    
        Item(const int id, const int profit, const int weight);
    
        double profit_per_weight();
        bool is_assigned();
        void reset_assignment();
        static bool compare(Item &i, Item &j);
        bool operator==(const Item &it) const;
        bool operator<(const Item &it) const;
    };
    
    
    struct _ItemPtrComp{
      bool operator()(const Item *x, const Item *y) const { return *x < *y; }
    };
    
    typedef std::set<Item*, _ItemPtrComp> ItemPtrSet;

}
#endif
