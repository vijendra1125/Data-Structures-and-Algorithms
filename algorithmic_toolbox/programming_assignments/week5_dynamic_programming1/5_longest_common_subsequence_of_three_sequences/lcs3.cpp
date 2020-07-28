#include <iostream>
#include <vector>

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

vector<int> lcs2(vector<int> &a, vector<int> &b, vector<vector<int>> &m)
{
  fill_mem(a, b, m, a.size(), b.size());
  vector<int> lcs;
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
      lcs.push_back(a[i - 1]);
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

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  vector<vector<int>> m_ab(a.size() + 1, vector<int>(b.size() + 1, -1));
  vector<vector<int>> m_bc(b.size() + 1, vector<int>(c.size() + 1, -1));
  vector<vector<int>> m_ca(c.size() + 1, vector<int>(a.size() + 1, -1));
  vector<int> lcs_ab, lcs_bc, lcs_ca;
  lcs_ab = lcs2(a, b, m_ab);
  lcs_bc = lcs2(b, c, m_bc);
  lcs_ca = lcs2(c, a, m_ca);

  sort(lcs_ab.begin(), lcs_ab.end());
  sort(lcs_bc.begin(), lcs_bc.end());
  sort(lcs_ca.begin(), lcs_ca.end());
  vector<int> vec_ab_bc(lcs_ab.size() + lcs_bc.size());
  vector<int>::iterator it;
  it = set_intersection(lcs_ab.begin(), lcs_ab.end(),
                        lcs_bc.begin(), lcs_bc.end(),
                        vec_ab_bc.begin());
  vec_ab_bc.erase(it, vec_ab_bc.end());
  vector<int> vec_abc(vec_ab_bc.size() + lcs_ca.size());
  it = set_intersection(vec_ab_bc.begin(), vec_ab_bc.end(),
                        lcs_ca.begin(), lcs_ca.end(),
                        vec_abc.begin());
  vec_abc.erase(it, vec_abc.end());

  return vec_abc.size();
}

int main()
{
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++)
  {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++)
  {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++)
  {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
