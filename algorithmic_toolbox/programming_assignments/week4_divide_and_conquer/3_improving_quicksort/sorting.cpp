#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;

int partition2(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

struct Partition
{
  int m1, m2;
};

Partition partition3(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  int k = 0;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] < x)
    {
      j++;
      swap(a[j], a[j + k]);
      swap(a[i], a[j]);
    }
    else if (a[i] == x)
    {
      k++;
      k += j;
      swap(a[i], a[k]);
    }
  }
  swap(a[l], a[j]);
  Partition m;
  m.m1 = j;
  m.m2 = j + k;

  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  // int m = partition2(a, l, r);
  Partition m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.m1 - 1);
  randomized_quick_sort(a, m.m2 + 1, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
