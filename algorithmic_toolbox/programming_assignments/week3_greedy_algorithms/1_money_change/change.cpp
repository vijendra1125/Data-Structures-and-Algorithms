#include <iostream>

int get_change(int m)
{
  int coins[3] = {10, 5, 1};
  int n = 0;
  int leftover = m;
  int idx = 0;
  while (leftover != 0)
  {
    int coin_pulled = leftover / coins[idx];
    n += coin_pulled;
    leftover -= coin_pulled * coins[idx];
    idx++;
  }
  return n;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
