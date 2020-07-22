#include <iostream>
#include <vector>

using std::vector;

int merge(vector<int> &e, vector<int> &c, vector<int> &d, int idx)
{
  int inv = 0;
  while ((c.size() > 0) && (d.size() > 0))
  {
    if (c.back() <= d.back())
    {
      e[idx] = c.back();
      idx--;
      c.erase(c.end() - 1);
    }
    else
    {
      inv += c.size();
      e[idx] = d.back();
      idx--;
      d.erase(d.end() - 1);
    }

    if (c.size() != 0)
    {
      for (int i = 0; i < c.size(); ++i)
      {
        e[i] = c[i];
      }
    }
    if (d.size() != 0)
    {
      for (int i = 0; i < d.size(); ++i)
      {
        e[i] = d[i];
      }
    }
  }
  return inv;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (right <= left)
    return number_of_inversions;

  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);

  vector<int> left_vec(ave - left + 1);
  std::move(a.begin() + left, a.begin() + ave + 1, left_vec.begin());
  vector<int> right_vec(right - ave);
  std::move(a.begin() + ave + 1, a.begin() + right + 1, right_vec.begin());
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
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
