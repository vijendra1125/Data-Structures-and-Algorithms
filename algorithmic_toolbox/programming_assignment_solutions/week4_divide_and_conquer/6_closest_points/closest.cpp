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

double minimal_distance_fast(vector<Point> &px, vector<Point> &py, int l, int r)
{
  if (r - l <= 2)
  {
    vector<Point> mini_vec(std::make_move_iterator(px.begin() + l), std::make_move_iterator(px.begin() + r + 1));
    return minimal_dist_naive(mini_vec);
  }

  int mid = (l + r) / 2;
  vector<Point> pyl;
  vector<Point> pyr;
  for (int i = 0; i < py.size(); ++i)
  {
    if (py[i].x <= px[mid].x)
    {
      pyl.push_back(py[i]);
    }
    else
    {
      pyr.push_back(py[i]);
    }
  }
  double min_dl = minimal_distance_fast(px, pyl, l, mid);
  double min_dr = minimal_distance_fast(px, pyr, mid + 1, r);
  double min_d = min(min_dl, min_dr);

  vector<Point> p_strip;
  for (int i = 0; i < py.size(); ++i)
  {
    if (abs(py[i].x - px[mid].x) <= min_d)
    {
      p_strip.push_back(py[i]);
    }
  }
  for (int i = 0; i < p_strip.size(); ++i)
  {
    for (int j = i + 1; j < p_strip.size(); ++j)
    {
      if (abs(i - j) <= 7)
      {
        min_d = min(min_d, dist(p_strip[i], p_strip[j]));
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

  vector<Point> px;
  vector<Point> py;
  for (size_t i = 0; i < x.size(); ++i)
  {
    Point pt;
    pt.x = x[i];
    pt.y = y[i];
    px.push_back(pt);
    py.push_back(pt);
  }

  std::cout << std::fixed;
  // std::cout << std::setprecision(9) << minimal_distance_naive(p) << "\n";
  sort(px.begin(), px.end(), comparator_x);
  sort(py.begin(), py.end(), comparator_y);
  std::cout << std::setprecision(9)
            << minimal_distance_fast(px, py, 0, px.size() - 1) << "\n";
}
