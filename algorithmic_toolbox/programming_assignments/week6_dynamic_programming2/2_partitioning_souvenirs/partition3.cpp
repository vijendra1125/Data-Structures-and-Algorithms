#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using std::accumulate;
using std::cin;
using std::cout;
using std::max;
using std::vector;

void fill_mem(int value, int i, const vector<int> &souvenirs, vector<vector<int>> &m)
{
  if ((value == 0) || (i == 0))
  {
    m[value][i] = 0;
  }
  else
  {
    if (m[value][i - 1] == -1)
    {
      fill_mem(value, i - 1, souvenirs, m);
    }
    if ((value >= souvenirs[i - 1]))
    {
      if (m[value - souvenirs[i - 1]][i - 1] == -1)
      {
        fill_mem(value - souvenirs[i - 1], i - 1, souvenirs, m);
      }
      m[value][i] = max(m[value - souvenirs[i - 1]][i - 1] + souvenirs[i - 1],
                        m[value][i - 1]);
    }
    else
    {
      m[value][i] = m[value][i - 1];
    }
  }
}

vector<int> find_souvenir(int value, vector<int> &souvenirs, vector<vector<int>> &m)
{
  vector<int> souvenirs_idx;
  int i = value;
  int j = souvenirs.size();
  int remainig_value = value;

  while (remainig_value != 0)
  {
    if (m[i][j] == m[i][j - 1])
    {
      j = j - 1;
    }
    else
    {
      souvenirs_idx.push_back(j - 1);
      remainig_value -= souvenirs[j - 1];
      i -= souvenirs[j - 1];
      j = j - 1;
    }
  }
  return souvenirs_idx;
}

int partition3(vector<int> &A)
{
  int value = std::accumulate(A.begin(), A.end(), 0);
  int value_per_person = value / 3;
  for (int i = 0; i < 2; ++i)
  {
    vector<vector<int>> memory(value_per_person + 1, vector<int>(A.size() + 1, -1));
    fill_mem(value_per_person, A.size(), A, memory);
    if (memory[value_per_person][A.size()] == value_per_person)
    {
      vector<int> souvenirs = find_souvenir(value_per_person, A, memory);
      for (auto it = souvenirs.begin(); it != souvenirs.end(); ++it)
      {
        A.erase(A.begin() + (*it));
      }
    }
    else
    {
      return 0;
    }
  }
  if (std::accumulate(A.begin(), A.end(), 0) == value_per_person)
  {
    return 1;
  }
  return 0;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }

  std::cout << partition3(A) << '\n';
}
