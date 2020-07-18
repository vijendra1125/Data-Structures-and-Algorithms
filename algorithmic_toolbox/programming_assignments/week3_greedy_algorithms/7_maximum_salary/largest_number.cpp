#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

vector<string> get_max_candidates(vector<string> v, int digit_position)
{
  vector<string> max_candidates;
  char max = 0;
  for (size_t i = 0; i < v.size(); ++i)
  {
    char digit = v[i][digit_position % v[i].length()];
    if (digit > max)
    {
      max_candidates.clear();
      max = digit;
      max_candidates.push_back(v[i]);
    }
    else if (digit == max)
    {
      max_candidates.push_back(v[i]);
    }
  }
  return max_candidates;
}

string largest_number(vector<string> a)
{
  vector<string> remaining_numbers = a;
  vector<string> arranged_numbers;
  while (remaining_numbers.size() > 1)
  {
    vector<string> candidates = remaining_numbers;
    for (int i = 0; i < 4; ++i)
    {
      vector<string> temp = get_max_candidates(candidates, i);
      candidates.clear();
      candidates = temp;
    }

    for (size_t i = 0; i < candidates.size(); ++i)
    {
      arranged_numbers.push_back(candidates[i]);
    }
    vector<string>::iterator ip;
    ip = std::unique(candidates.begin(), candidates.end());
    candidates.resize(std::distance(candidates.begin(), ip));
    for (int i = 0; i < candidates.size(); ++i)
    {
      remaining_numbers.erase(remove(remaining_numbers.begin(),
                                     remaining_numbers.end(), candidates[i]),
                              remaining_numbers.end());
    }
  }
  arranged_numbers.push_back(remaining_numbers[0]);

  std::stringstream ret;
  for (size_t i = 0; i < arranged_numbers.size(); i++)
  {
    ret << arranged_numbers[i];
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
