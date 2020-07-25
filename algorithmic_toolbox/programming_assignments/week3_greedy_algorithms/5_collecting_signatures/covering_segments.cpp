#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

struct Point
{
  int position;
  char type;
};

bool point_comparator(Point a, Point b)
{
  if (a.position < b.position)
  {
    return true;
  }
  else if (a.position == b.position)
  {
    return a.type >= b.type;
  }
  else
  {
    return false;
  }
}

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<Point> points;
  for (auto it = segments.begin(); it != segments.end(); ++it)
  {
    Point p;
    p.position = (*it).start;
    p.type = 's';
    points.push_back(p);
    p.position = (*it).end;
    p.type = 'e';
    points.push_back(p);
  }
  sort(points.begin(), points.end(), point_comparator);
  for (int i = 0; i < points.size(); ++i)
  {
    std::cout << points[i].position << "(" << points[i].type << "), ";
  }
  std::cout << "\n";

  vector<int> optimals;
  char previous = 's';
  for (auto it = points.begin(); it != points.end(); ++it)
  {
    if (((*it).type == 'e') && previous == 's')
    {
      optimals.push_back((*it).position);
      previous = 'e';
    }
    else
    {
      previous = 's';
    }
  }
  return optimals;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
  std::cout << "\n";
}
