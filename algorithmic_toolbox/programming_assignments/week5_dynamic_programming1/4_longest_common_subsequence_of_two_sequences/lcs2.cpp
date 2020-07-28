#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::max;
using std::min;
using std::vector;

void fill_mem(vector<int> &a, vector<int> &b, vector<vector<int>> &m, int i, int j)
{
  if ((i == 0) || (j == 0))
  {
    m[i][j] = max(i, j);
  }
  else
  {
    if (m[i - 1][j] == -1)
    {
      fill_mem(a, b, m, i - 1, j);
    }
    if (m[i][j - 1] == -1)
    {
      fill_mem(a, b, m, i, j - 1);
    }
    if (m[i - 1][j - 1] == -1)
    {
      fill_mem(a, b, m, i - 1, j - 1);
    }

    if (a[i - 1] == b[j - 1])
    {
      m[i][j] = min({m[i - 1][j] + 1, m[i][j - 1] + 1, m[i - 1][j - 1]});
    }
    else
    {
      m[i][j] = min(m[i - 1][j] + 1, m[i][j - 1] + 1);
    }
  }
}

int lcs2(vector<int> &a, vector<int> &b, vector<vector<int>> &m)
{
  fill_mem(a, b, m, a.size(), b.size());

  int lcs = 0;
  int i = a.size();
  int j = b.size();
  while (((i > 0) && (j > 0)))
  {
    int min_d;
    if (a[i - 1] == b[j - 1])
    {
      min_d = min({m[i - 1][j], m[i][j - 1], m[i - 1][j - 1]});
    }
    else
    {
      min_d = min(m[i - 1][j], m[i][j - 1]);
    }

    if ((min_d == m[i - 1][j - 1]) && (a[i - 1] == b[j - 1]))
    {
      lcs++;
      i -= 1;
      j -= 1;
    }
    else if (min_d == m[i - 1][j])
    {
      i -= 1;
    }
    else
    {
      j -= 1;
    }
  }
  return lcs;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  vector<vector<int>> memory(a.size() + 1, vector<int>(b.size() + 1, -1));
  cout << lcs2(a, b, memory) << '\n';
  // for (int i = 0; i <= a.size(); ++i)
  // {
  //   for (int j = 0; j <= b.size(); ++j)
  //   {
  //     std::cout << memory[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
}
