#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool sort_comp(string a, string b)
{
  string s1 = a.append(b);
  string s2 = b.append(a);
  return s1.compare(s2) > 0;
}

string largest_number(vector<string> a)
{
  sort(a.begin(), a.end(), sort_comp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }

  std::cout << largest_number(a) << "\n";
}
