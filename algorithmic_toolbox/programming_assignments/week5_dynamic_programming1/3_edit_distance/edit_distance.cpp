#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::min;
using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2, vector<vector<int>> &m)
{
  if (str1 == "")
  {
    m[0][str2.size()] = str2.size();
    return str2.size();
  }
  if (str2 == "")
  {
    m[str1.size()][0] = str1.size();
    return str1.size();
  }

  if (m[str1.size() - 1][str2.size()] == -1)
  {
    edit_distance(str1.substr(0, str1.size() - 1), str2, m);
  }
  if (m[str1.size()][str2.size() - 1] == -1)
  {
    edit_distance(str1, str2.substr(0, str2.size() - 1), m);
  }
  if (m[str1.size() - 1][str2.size() - 1] == -1)
  {
    edit_distance(str1.substr(0, str1.size() - 1), str2.substr(0, str2.size() - 1), m);
  }
  int dist_insert = m[str1.size() - 1][str2.size()];
  int dist_delete = m[str1.size()][str2.size() - 1];
  int dist_mis_match = m[str1.size() - 1][str2.size() - 1];
  int dist;
  if (str1.back() == str2.back())
  {

    dist = min({dist_insert + 1, dist_delete + 1, dist_mis_match});
  }
  else
  {
    dist = min({dist_insert + 1, dist_delete + 1, dist_mis_match + 1});
  }
  m[str1.size()][str2.size()] = dist;

  return dist;
}

int main()
{
  string str1;
  string str2;
  cin >> str1 >> str2;

  vector<vector<int>> memory(str1.size() + 1, vector<int>(str2.size() + 1, -1));
  cout << edit_distance(str1, str2, memory) << std::endl;
  // for (int i = 0; i < memory.size(); ++i)
  // {
  //   for (int j = 0; j < memory[0].size(); ++j)
  //   {
  //     std::cout << memory[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
}
