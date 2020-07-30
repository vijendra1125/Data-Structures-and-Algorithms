#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <cmath>

using std::max;
using std::min;
using std::string;
using std::vector;

int inf = std::numeric_limits<int>::min();

long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

void fill_mem(const string &exp, vector<vector<long long>> &m1, vector<vector<long long>> &m2, int i, int j)
{
  if (i == j)
  {
    char num[] = {exp[i]};
    m1[i][j] = atoll(num);
    m2[i][j] = atoll(num);
  }
  else
  {
    long long max_val = inf;
    long long min_val = -1 * inf;
    for (int e = i + 1; e < j; e += 2)
    {
      if (m1[i][e - 1] == inf)
      {
        fill_mem(exp, m1, m2, i, e - 1);
      }
      if (m1[e + 1][j] == inf)
      {
        fill_mem(exp, m1, m2, e + 1, j);
      }
      if (m2[i][e - 1] == inf)
      {
        fill_mem(exp, m1, m2, i, e - 1);
      }
      if (m2[e + 1][j] == inf)
      {
        fill_mem(exp, m1, m2, e + 1, j);
      }
      max_val = max(max_val, eval(m1[i][e - 1], m1[e + 1][j], exp[e]));
      max_val = max(max_val, eval(m1[i][e - 1], m2[e + 1][j], exp[e]));
      max_val = max(max_val, eval(m2[i][e - 1], m1[e + 1][j], exp[e]));
      max_val = max(max_val, eval(m2[i][e - 1], m2[e + 1][j], exp[e]));

      min_val = min(min_val, eval(m1[i][e - 1], m1[e + 1][j], exp[e]));
      min_val = min(min_val, eval(m2[i][e - 1], m1[e + 1][j], exp[e]));
      min_val = min(min_val, eval(m1[i][e - 1], m2[e + 1][j], exp[e]));
      min_val = min(min_val, eval(m2[i][e - 1], m2[e + 1][j], exp[e]));
    }
    m1[i][j] = max_val;
    m2[i][j] = min_val;
  }
}

long long get_maximum_value(const string &exp)
{
  int n = exp.size();
  vector<vector<long long>> memory_max(n, vector<long long>(n, inf));
  vector<vector<long long>> memory_min(n, vector<long long>(n, inf));
  fill_mem(exp, memory_max, memory_min, 0, exp.size() - 1);

  return memory_max[0][exp.size() - 1];
}

int main()
{
  string s;
  std::cin >> s;

  std::cout << get_maximum_value(s) << '\n';
}
