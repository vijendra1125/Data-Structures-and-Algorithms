#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using std::cin;
using std::cout;
using std::min;
using std::vector;

int inf = std::numeric_limits<int>::max();

struct MetaData
{
  int prev_n = 0;
  int ops = 0;
};

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  while (n >= 1)
  {
    sequence.push_back(n);
    if (n % 3 == 0)
    {
      n /= 3;
    }
    else if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

void fill_mem(int n, vector<MetaData> &t)
{
  if (n == 1)
  {
    t[n].prev_n = 1;
    t[n].ops = 0;
  }
  else if ((n == 3) || (n == 2))
  {
    t[n].prev_n = 1;
    t[n].ops = 1;
  }
  else
  {
    int ops_add1 = inf;
    int ops_mul3 = inf;
    int ops_mul2 = inf;
    if (n % 3 == 0)
    {
      if (t[n / 3].prev_n == 0)
      {
        fill_mem(n / 3, t);
      }
      ops_mul3 = t[n / 3].ops;
    }
    if (n % 2 == 0)
    {
      if (t[n / 2].prev_n == 0)
      {
        fill_mem(n / 2, t);
      }
      ops_mul2 = t[n / 2].ops;
    }
    if (t[n - 1].prev_n == 0)
    {
      fill_mem(n - 1, t);
    }
    ops_add1 = t[n - 1].ops;
    int min_ops = min({ops_mul3, ops_mul2, ops_add1});

    t[n].ops = min_ops + 1;
    if (min_ops == ops_add1)
    {
      t[n].prev_n = n - 1;
    }
    else if (min_ops == ops_mul3)
    {
      t[n].prev_n = n / 3;
    }
    else
    {
      t[n].prev_n = n / 2;
    }
  }
}

vector<int> optimal_sequence_dp(int n, vector<MetaData> &m)
{
  fill_mem(n, m);

  vector<int> sequence;
  int idx = m.size() - 1;
  while (idx != 1)
  {
    sequence.insert(sequence.begin(), idx);
    idx = m[idx].prev_n;
  }
  sequence.insert(sequence.begin(), 1);

  return sequence;
}

int main()
{
  int n;
  std::cin >> n;

  // vector<int> sequence = optimal_sequence(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i)
  // {
  //   std::cout << sequence[i] << " ";
  // }
  // std::cout << std::endl;

  vector<MetaData> memory(n + 1);
  vector<int> sequence_dp = optimal_sequence_dp(n, memory);
  std::cout << sequence_dp.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence_dp.size(); ++i)
  {
    std::cout << sequence_dp[i] << " ";
  }
}
