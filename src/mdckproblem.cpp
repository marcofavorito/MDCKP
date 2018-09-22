#include "mdckproblem.hpp"

tuple<int, int> _read_first_line();
tuple<int, int> _read_item_line();
vector<Knapsack> _read_knapsacks(int m);
vector<Item> _read_items(int n);
void _read_incompatibilities(vector<Item> items);

tuple<int, int> _read_first_line()
{
    string line;
    getline(cin, line);
    istringstream iss(line);

    int N, M;
    iss >> N >> M;
    return make_tuple(N, M);
}

vector<Knapsack> _read_knapsacks(int m){

    vector<Knapsack> knapsacks;
    string line;
    getline(cin, line);
    istringstream iss(line);

    int capacity;
    for (int id=0; id<m; id++){
        iss >> capacity;
        Knapsack k = Knapsack(id, capacity);
        knapsacks.push_back(k);
    }
    
    return knapsacks;
}

tuple<int, int> _read_item_line()
{
    string line;
    getline(cin, line);
    istringstream iss(line);

    int profit, weight;
    iss >> profit >> weight;
    
    return make_tuple(profit, weight);
}
vector<Item> _read_items(int B)
{
    vector<Item> items;
    Item* it;

    int profit, weight;
    
    for (int id = 0; id < B; id++)
    {
        tie(profit, weight) = _read_item_line();
        Item it = Item(id, profit, weight);
        items.push_back(it);
    }

    return items;
}

template <class T>
vector<T *> from_vector_of_objects_to_vector_of_pointers(vector<T> &l)
{
    vector<T *> result = vector<T *>();
    for (int i = 0; i < l.size(); i++)
    {
        result.push_back(&l[i]);
    }
    return result;
}

void _read_incompatibilities(vector<Item> items){
    int i, j;
    istringstream iss;
    std::string line;
    while (getline(cin, line))
    {
        istringstream iss(line);
        iss >> i >> j;
        items[i].incompatible_items_ids.insert(j);
        items[j].incompatible_items_ids.insert(i);
    }
}

MDCKProblem MDCKProblem::read_from_stdin()
{
    MDCKProblem data;
    tie(data.n, data.m) = _read_first_line();
    data.knapsacks = _read_knapsacks(data.m);
    data.items = _read_items(data.n);
    _read_incompatibilities(data.items);

    vector<Item *> item_pointers = from_vector_of_objects_to_vector_of_pointers(data.items);

    data.items_by_decreasing_profit_per_weight = item_pointers;
    data.items_by_increasing_profit_per_weight = item_pointers;
    // sort items by mean value, decreasing
    sort(data.items_by_decreasing_profit_per_weight.begin(),
              data.items_by_decreasing_profit_per_weight.end(),
              [](Item *a, Item *b) { return !Item::compare(*a, *b); });
    // sort items by mean value, increasing
    sort(data.items_by_increasing_profit_per_weight.begin(),
              data.items_by_increasing_profit_per_weight.end(),
              [](Item *a, Item *b) { return Item::compare(*a, *b); });

    return data;
}

string MDCKProblem::to_string(){
    string s = "";
    s += std::to_string(this->n) + " " + std::to_string(this->m) + "\n";
    for (Knapsack k: this->knapsacks){
        // s += "\t" + std::to_string(k.id) + ", " + std::to_string(k.capacity) + "\n";
        s += std::to_string(k.capacity) + " ";
    }
    s+="\n";
    for (Item it : this->items)
    {
        // s += "\t" + std::to_string(it.id) + ", " + std::to_string(it.profit) + ", " + std::to_string(it.weight) + "\n";
        s += std::to_string(it.profit) + " " + std::to_string(it.weight);
    }
    s+="\n";

    return s;
}

string MDCKProblem::solution_to_string(){
    string s = "";
    s += std::to_string(this->score) + "\n";
    for (Knapsack k: this->knapsacks){
        for (Item * it : k.items){
            s += std::to_string(it->id) + " ";
        }
        s += "\n";
    }

    return s;
}