#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

bool sort_comp(Segment a, Segment b)
{
  return (a.end - a.start) < (b.end - b.start);
}

vector<int> optimal_points(vector<Segment> &segments)
{
  sort(segments.begin(), segments.end(), sort_comp);

  vector<int> points;
  size_t start = 0;
  while (start < segments.size())
  {
    if (start == (segments.size() - 1))
    {
      points.push_back(segments[start].end);
      start++;
    }
    else
    {
      Segment current_seg = segments[start];
      bool take_start = false;
      bool take_end = false;
      bool take_either = false;
      vector<int> indexes_for_removal;
      for (auto it = (segments.begin() + start + 1); it != segments.end(); ++it)
      {
        bool on_right = (*it).start > current_seg.end;
        bool on_left = (*it).end < current_seg.start;
        if (!(on_left || on_right))
        {
          if (!(take_start && take_end))
          {
            bool temp_take_start = ((*it).end >= current_seg.start) && (*it).start <= current_seg.start;
            bool temp_take_end = (*it).start <= current_seg.end && (*it).end >= current_seg.end;
            if (temp_take_start && temp_take_end)
            {
              take_either = true;
            }
            else
            {
              take_start = take_start || temp_take_start;
              take_end = take_end || temp_take_end;
            }
          }
          indexes_for_removal.push_back(distance(segments.begin(), it));
        }
      }
      if (take_start)
      {
        points.push_back(current_seg.start);
      }
      if (take_end)
      {
        points.push_back(current_seg.end);
      }
      if (take_either && (!(take_start || take_end)))
      {
        points.push_back(current_seg.end);
      }
      int index_reduction = 0;
      for (auto i = indexes_for_removal.begin(); i != indexes_for_removal.end(); ++i)
      {
        segments.erase(segments.begin() + (*i) - index_reduction);
        index_reduction++;
      }
      start++;
    }
  }
  return points;
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
