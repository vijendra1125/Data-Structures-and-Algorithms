#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;

  vector<double> value_per_kg;
  for (int i = 0; i < weights.size(); ++i)
  {
    value_per_kg.push_back(double(values[i]) / weights[i]);
  }

  int left_capacity = capacity;
  while (left_capacity > 0)
  {
    double current_max = 0.0;
    int current_max_idx = 0;
    for (int i = 0; i < value_per_kg.size(); ++i)
    {
      if (value_per_kg[i] >= current_max)
      {
        current_max = value_per_kg[i];
        current_max_idx = i;
      }
    }
    value_per_kg.erase(value_per_kg.begin() + current_max_idx);

    int weight_goes_in = 0;
    int available_weight = weights[current_max_idx];
    if ((left_capacity - available_weight) >= 0)
    {
      weight_goes_in = available_weight;
    }
    else
    {
      weight_goes_in = left_capacity;
    }

    left_capacity -= weight_goes_in;
    value += double(weight_goes_in) * current_max;
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
  return 0;
}
