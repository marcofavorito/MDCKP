#include "mdckproblem.hpp"

namespace mdckp{
    
    std::tuple<int, int> _read_first_line(std::istream &is);
    std::tuple<int, int> _read_item_line(std::istream &is);
    std::vector<Knapsack> _read_knapsacks(std::istream &is, int m);
    std::vector<Item> _read_items(std::istream &is, int n);
    void _read_incompatibilities(std::istream &is, std::vector<Item> &items);
    
    std::tuple<int, int> _read_first_line(std::istream &is)
    {
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
    
        int N, M;
        iss >> N >> M;
        return std::make_tuple(N, M);
    }
    
    std::vector<Knapsack> _read_knapsacks(std::istream &is, int m)
    {
    
        std::vector<Knapsack> knapsacks;
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
    
        int capacity;
        for (int id=0; id<m; id++){
            iss >> capacity;
            Knapsack k = Knapsack(id, capacity);
            knapsacks.push_back(k);
        }
        
        return knapsacks;
    }
    
    std::tuple<int, int> _read_item_line(std::istream &is)
    {
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
    
        int profit, weight;
        iss >> profit >> weight;
        
        return std::make_tuple(profit, weight);
    }
    std::vector<Item> _read_items(std::istream &is, int B)
    {
        std::vector<Item> items;
        int profit, weight;
        
        for (int id = 0; id < B; id++)
        {
            std::tie(profit, weight) = _read_item_line(is);
            Item it = Item(id, profit, weight);
            items.push_back(it);
        }
    
        return items;
    }
    
    template <class T>
    std::vector<T *> from_vector_of_objects_to_vector_of_pointers(std::vector<T> &l)
    {
        std::vector<T *> result = std::vector<T *>();
        for (unsigned int i = 0; i < l.size(); i++)
        {
            result.push_back(&l[i]);
        }
        return result;
    }
    
    void _read_incompatibilities(std::istream &is, std::vector<Item> &items){
        int i, j;
        std::istringstream iss;
        std::string line;
        while (std::getline(is, line))
        {
            std::istringstream iss(line);
            iss >> i >> j;
            items[i].incompatible_items_ids.insert(j);
            items[j].incompatible_items_ids.insert(i);
        }
    }
    
    int MDCKProblem::compute_score(){
        int score = 0;
        for (Knapsack k: this->knapsacks){
            score += k.total_profit;
        }
        return score;
    }
    
    MDCKProblem MDCKProblem::read_from_istream(std::istream &is)
    {
        MDCKProblem data;
        std::tie(data.n, data.m) = _read_first_line(is);
        data.knapsacks = _read_knapsacks(is, data.m);
        data.items = _read_items(is, data.n);
        _read_incompatibilities(is, data.items);
    
        std::vector<Item *> item_pointers = from_vector_of_objects_to_vector_of_pointers(data.items);
    
        data.items_by_decreasing_profit_per_weight = item_pointers;
        data.items_by_increasing_profit_per_weight = item_pointers;
        // sort items by mean value, decreasing
        std::sort(data.items_by_decreasing_profit_per_weight.begin(),
                  data.items_by_decreasing_profit_per_weight.end(),
                  [](Item *a, Item *b) { return !Item::compare(*a, *b); });
        // sort items by mean value, increasing
        std::sort(data.items_by_increasing_profit_per_weight.begin(),
                  data.items_by_increasing_profit_per_weight.end(),
                  [](Item *a, Item *b) { return Item::compare(*a, *b); });
    
        return data;
    }
    
    std::string MDCKProblem::to_string(){
        std::string s = "";
        s += std::to_string(this->n) + " " + std::to_string(this->m) + "\n";
        for (Knapsack k: this->knapsacks){
            s += std::to_string(k.capacity) + " ";
        }
        s+="\n";
        for (Item it : this->items)
        {
            s += std::to_string(it.profit) + " " + std::to_string(it.weight) + ": ";
            for (int i : it.incompatible_items_ids){
                s += std::to_string(i) + ", ";
            }
            s += "\n";
        }
    
        return s;
    }
    
    std::string MDCKProblem::solution_to_string(){
        std::string s = "";
        s += std::to_string(this->compute_score()) + "\n";
        for (Knapsack k: this->knapsacks){
            for (Item * it : k.items){
                s += std::to_string(it->id) + " ";
            }
            s += "\n";
        }
        s.pop_back();
    
        return s;
    }
    
}
