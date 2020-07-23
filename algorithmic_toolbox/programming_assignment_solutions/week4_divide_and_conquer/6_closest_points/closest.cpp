#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::min;
using std::pair;
using std::string;
using std::vector;

struct Point
{
  int x, y;
};

bool comparator_x(Point a, Point b)
{
  return a.x < b.x;
}
bool comparator_y(Point a, Point b)
{
  return a.y < b.y;
}

double dist(Point p1, Point p2)
{
  return sqrt((pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2)));
}

double minimal_dist_naive(vector<Point> p)
{
  double min_dist = dist(p[0], p[1]);
  for (size_t i = 0; i < p.size(); ++i)
  {
    for (size_t j = i + 1; j < p.size(); ++j)
    {
      min_dist = min(min_dist, dist(p[i], p[j]));
    }
  }
  return min_dist;
}

double minimal_distance_fast(vector<Point> a, int l, int r)
{
  if (r - l <= 2)
  {
    double min_dist = dist(a[l], a[r]);
    for (int i = l; i <= r; ++i)
    {
      for (int j = i + 1; j <= r; ++j)
      {
        min_dist = min(min_dist, dist(a[i], a[j]));
      }
    }
    return min_dist;
  }

  int mid = (l + r) / 2;
  double min_dl = minimal_distance_fast(a, l, mid);
  double min_dr = minimal_distance_fast(a, mid + 1, r);
  double min_d = min(min_dl, min_dr);

  vector<Point> p_strip;
  for (int i = l; i <= r; ++i)
  {
    if (abs(a[i].x - a[mid].x) <= min_d)
    {
      p_strip.push_back(a[i]);
    }
  }
  sort(p_strip.begin(), p_strip.end(), comparator_y);
  for (int i = 0; i < p_strip.size(); ++i)
  {
    for (int j = i + 1; j < p_strip.size(); ++j)
    {
      if (abs(i - j) <= 7)
      {
        min_d = min(min_d, dist(a[i], a[j]));
      }
    }
  }

  return min_d;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }

  vector<Point> p;
  for (size_t i = 0; i < x.size(); ++i)
  {
    Point pt;
    pt.x = x[i];
    pt.y = y[i];
    p.push_back(pt);
  }

  std::cout << std::fixed;
  // std::cout << std::setprecision(9) << minimal_distance_naive(p) << "\n";
  sort(p.begin(), p.end(), comparator_x);
  std::cout << std::setprecision(9)
            << minimal_distance_fast(p, 0, p.size() - 1) << "\n";
}
