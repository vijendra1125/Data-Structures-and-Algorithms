#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

struct Point
{
  int position = 0;
  char type = ' ';
};

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

void push_data(vector<Point> &to, vector<int> &from, char type)
{
  for (auto it = from.begin(); it != from.end(); ++it)
  {
    Point p;
    p.position = *it;
    p.type = type;
    to.push_back(p);
  }
}

void merge(vector<Point> &n, vector<Point> &l_vec, vector<Point> &r_vec, int l, int r)
{
  while ((l_vec.size() != 0) && (r_vec.size() != 0))
  {
    if (l_vec[0].position < r_vec[0].position)
    {
      n[l] = l_vec[0];
      l++;
      l_vec.erase(l_vec.begin() + 0);
    }
    else if (l_vec[0].position > r_vec[0].position)
    {
      n[l] = r_vec[0];
      l++;
      r_vec.erase(r_vec.begin() + 0);
    }
    else
    {
      char priority = std::max(l_vec[0].type, r_vec[0].type);
      if (priority == l_vec[0].type)
      {
        n[l] = l_vec[0];
        l_vec.erase(l_vec.begin() + 0);
      }
      else
      {
        n[l] = r_vec[0];
        r_vec.erase(r_vec.begin() + 0);
      }
      l++;
    }
  }
  if (l_vec.size() != 0)
  {
    for (auto it = l_vec.begin(); it != l_vec.end(); ++it)
    {
      n[l] = *it;
      l++;
    }
  }
  if (r_vec.size() != 0)
  {
    for (auto it = r_vec.begin(); it != r_vec.end(); ++it)
    {
      n[l] = *it;
      l++;
    }
  }
}

void merge_sort(vector<Point> &n, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int mid = (r + l) / 2;
  merge_sort(n, l, mid);
  merge_sort(n, mid + 1, r);
  vector<Point> left_vec(std::make_move_iterator(n.begin() + l),
                         std::make_move_iterator(n.begin() + mid + 1));
  vector<Point> right_vec(std::make_move_iterator(n.begin() + mid + 1),
                          std::make_move_iterator(n.begin() + r + 1));
  merge(n, left_vec, right_vec, l, r);
}

vector<int> get_counts(vector<Point> &n)
{
  vector<int> cnt;
  int count = 0;
  for (auto it = n.begin(); it != n.end(); ++it)
  {
    if ((*it).type == 's')
    {
      count++;
    }
    else if ((*it).type == 'e')
    {
      count--;
    }
    else
    {
      cnt.push_back(count);
    }
  }
  return cnt;
}

vector<int> fast_count_segments(vector<int> &starts, vector<int> &ends, vector<int> points)
{
  vector<Point> n;
  push_data(n, starts, 's');
  push_data(n, ends, 'e');
  push_data(n, points, 'p');
  merge_sort(n, 0, n.size() - 1);
  return get_counts(n);
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }

  // vector<int> cnt = naive_count_segments(starts, ends, points);
  // for (size_t i = 0; i < cnt.size(); i++)
  // {
  //   std::cout << cnt[i] << ' ';
  // }
  // std::cout << '\n';

  vector<int> cnt2 = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt2.size(); i++)
  {
    std::cout << cnt2[i] << ' ';
  }
}
