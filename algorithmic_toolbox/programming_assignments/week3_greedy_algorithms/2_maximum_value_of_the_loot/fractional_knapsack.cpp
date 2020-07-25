#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

struct Item
{
  int weight;
  int value;
  double worth;
};

bool items_comparator(Item i1, Item i2)
{
  return i1.worth > i2.worth;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int free_capacity = capacity;
  vector<Item> items;
  for (int i = 0; i < weights.size(); ++i)
  {
    Item it;
    it.weight = weights[i];
    it.value = values[i];
    it.worth = (double)values[i] / weights[i];
    items.push_back(it);
  }
  sort(items.begin(), items.end(), items_comparator);

  for (auto it = items.begin(); it != items.end(); ++it)
  {
    if (free_capacity > 0)
    {
      std::cout << (*it).worth << " " << std::min(free_capacity, (*it).weight) << '\n';
      int goes_in_weight = std::min(free_capacity, (*it).weight);
      value += (*it).worth * goes_in_weight;
      free_capacity -= goes_in_weight;
    }
    else
    {
      break;
    }
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
}
