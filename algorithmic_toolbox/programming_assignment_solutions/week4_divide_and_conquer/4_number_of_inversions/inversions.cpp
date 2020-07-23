#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &main_vec, vector<int> &left_vec, vector<int> &right_vec, int r)
{
  long long inv = 0;
  while ((left_vec.size() > 0) && (right_vec.size() > 0))
  {
    if (left_vec.back() <= right_vec.back())
    {
      main_vec[r] = left_vec.back();
      r--;
      left_vec.erase(left_vec.end() - 1);
    }
    else
    {
      inv += left_vec.size();
      main_vec[r] = right_vec.back();
      r--;
      right_vec.erase(right_vec.end() - 1);
    }
  }

  if (left_vec.size() != 0)
  {
    for (int i = left_vec.size() - 1; i >= 0; --i)
    {
      main_vec[r] = left_vec[i];
      r--;
    }
  }
  if (right_vec.size() != 0)
  {
    for (int i = right_vec.size() - 1; i >= 0; --i)
    {
      main_vec[r] = right_vec[i];
      r--;
    }
  }
  return inv;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (right <= left)
    return number_of_inversions;

  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave + 1, right);

  vector<int> left_vec(std::make_move_iterator(a.begin() + left), std::make_move_iterator(a.begin() + ave + 1));
  vector<int> right_vec(std::make_move_iterator(a.begin() + ave + 1), std::make_move_iterator(a.begin() + right + 1));
  number_of_inversions += merge(a, left_vec, right_vec, right);

  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  long long inversions = get_number_of_inversions(a, 0, a.size() - 1);
  std::cout << inversions << '\n';
}
