#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, const int left, const int right, const int x)
{
  if (left > right)
  {
    return -1;
  }
  else
  {
    int middle = (left + right) / 2;
    if (x > a[middle])
    {
      return binary_search(a, middle + 1, right, x);
    }
    else if (x < a[middle])
    {
      return binary_search(a, left, middle - 1, x);
    }
    else
    {
      return middle;
    }
  }
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    // std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, 0, ((int)a.size() - 1), b[i]) << ' ';
  }

  return 0;
}
