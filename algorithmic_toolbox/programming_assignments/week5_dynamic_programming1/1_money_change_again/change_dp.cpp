#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::vector;

int inf = std::numeric_limits<int>::max();

int get_change(int m, vector<int> &t, vector<int> &coins)
{
  if (m <= 0)
  {
    return inf;
  }
  else if ((m == 1) || (m == 3) || (m == 4))
  {
    return 1;
  }

  int min_coin = inf;
  for (int i = 0; i < coins.size(); ++i)
  {
    int m_c = max(0, m - coins[i]);
    if (t[m_c] == inf)
    {
      t[m_c] = get_change(m_c, t, coins);
    }
    min_coin = min(min_coin, t[m_c]);
  }
  t[m] = min_coin + 1;

  return t[m];
}

int main()
{
  int m;
  cin >> m;

  vector<int> memory(m + 1, inf);
  vector<int> coins = {1, 3, 4};
  cout << get_change(m, memory, coins) << '\n';
  // for (int i = 0; i < memory.size(); ++i)
  // {
  //   cout << memory[i] << " ";
  // }
}
