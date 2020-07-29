#include <iostream>
#include <vector>
#include <cmath>

using std::max;
using std::vector;

void fill_mem(int W, int i, const vector<int> &w, vector<vector<int>> &m)
{
  if ((W == 0) || (i == 0))
  {
    m[W][i] = 0;
  }
  else
  {
    if (m[W][i - 1] == -1)
    {
      fill_mem(W, i - 1, w, m);
    }
    if ((W >= w[i - 1]))
    {
      if (m[W - w[i - 1]][i - 1] == -1)
      {
        fill_mem(W - w[i - 1], i - 1, w, m);
      }
      m[W][i] = max(m[W - w[i - 1]][i - 1] + w[i - 1], m[W][i - 1]);
    }
    else
    {
      m[W][i] = m[W][i - 1];
    }
  }
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }

  vector<vector<int>> memory(W + 1, vector<int>(n + 1, -1));
  fill_mem(W, n, w, memory);
  std::cout << memory[W][n] << '\n';
  // for (int i = 0; i < W + 1; ++i)
  // {
  //   for (int j = 0; j < n + 1; ++j)
  //   {
  //     std::cout << memory[i][j] << " ";
  //   }
  //   std::cout << '\n';
  // }
}
