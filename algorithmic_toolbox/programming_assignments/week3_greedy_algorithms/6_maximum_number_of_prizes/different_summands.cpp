#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  int counter = 1;
  while (n >= counter)
  {
    summands.push_back(counter);
    n -= counter;
    counter++;
  }
  // summands[summands.size() - 1] += n;
  summands[-1] += n;
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
