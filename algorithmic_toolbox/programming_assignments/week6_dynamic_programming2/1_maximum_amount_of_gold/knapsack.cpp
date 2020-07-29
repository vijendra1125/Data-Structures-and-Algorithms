#include <iostream>
#include <vector>
#include <cmath>

using std::max;
using std::vector;

void optimal_weight_dp(int W, const vector<int> &w, vector<vector<int>> &m, int i)
{
  if ((W == 0) || (i == 0))
  {
    m[W][i] = 0;
  }
  else
  {
    if (m[W][i - 1] == -1)
    {
      optimal_weight_dp(W, w, m, i - 1);
    }
    if ((W >= w[i - 1]))
    {
      if (m[W - w[i - 1]][i - 1] == -1)
      {
        optimal_weight_dp(W - w[i - 1], w, m, i - 1);
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
  optimal_weight_dp(W, w, memory, n);
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
