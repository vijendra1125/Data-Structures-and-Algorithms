#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int get_majority_element_using_sorting(vector<int> &a)
{
  sort(a.begin(), a.end());

  int current_count = 1;
  int previous_count = 0;
  for (size_t i = 1; i < a.size(); ++i)
  {
    if ((a[i] > a[i - 1]) && (current_count > previous_count))
    {
      previous_count = current_count;
      current_count = 1;
    }
    else
    {
      current_count++;
    }
  }
  if (current_count > previous_count)
  {
    previous_count = current_count;
  }
  return (int)(previous_count > (a.size() / 2));
}

int get_majority_element_using_moore(const vector<int> a)
{
  int candidate_id = 0;
  int count = 1;
  for (size_t i = 1; i < a.size(); ++i)
  {
    if (a[i] == a[candidate_id])
    {
      count++;
    }
    else
    {
      count--;
    }
    if (count == 0)
    {
      candidate_id = i;
      count = 1;
    }
  }
  int candidate_count = 0;
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == a[candidate_id])
    {
      candidate_count++;
    }
    if (candidate_count > (a.size() / 2))
    {
      return 1;
    }
  }
  return 0;
}

int get_majority_element_divide_conquer(vector<int> &a, int left, int right)
{
  if (left == right)
    return a[left];
  if (((left + 1) == right) && (a.size() != 2))
    return a[left];

  int middle = (left + right) / 2;
  int majority_candidate1 = get_majority_element_divide_conquer(a, left, middle);
  int majority_candidate2 = get_majority_element_divide_conquer(a, middle + 1, right);

  int majority_count1 = 0;
  int majority_count2 = 0;
  if (majority_candidate1 != -1)
  {
    for (size_t i = left; i <= right; ++i)
    {
      if (a[i] == majority_candidate1)
      {
        majority_count1++;
      }
    }
  }
  if (majority_candidate2 != -1)
  {
    for (size_t i = left; i <= right; ++i)
    {
      if (a[i] == majority_candidate2)
      {
        majority_count2++;
      }
    }
  }

  int min_count = (int)(ceil((right - left) / 2.0));
  if ((majority_count1 > min_count) && (majority_candidate2 > min_count))
  {
    if (majority_count1 >= majority_candidate2)
    {
      return majority_candidate1;
    }
    else
    {
      return majority_candidate2;
    }
  }
  else if (majority_count1 > min_count)
  {
    return majority_candidate1;
  }
  else if (majority_count2 > min_count)
  {
    return majority_candidate2;
  }
  else
  {
    return -1;
  }
}

int get_majority_element_coursera_template(vector<int> &a, int left, int right)
{
  if (left == right)
    return -1;
  if ((left + 1) == right)
    return a[left];
  // your code here
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  // std::cout << (int)(get_majority_element_divide_conquer(a, 0, a.size() - 1) != -1) << '\n';
  // std::cout << get_majority_element_using_sorting(a) << '\n';
  std::cout << get_majority_element_using_moore(a) << '\n';
}
