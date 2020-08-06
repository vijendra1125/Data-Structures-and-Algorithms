#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

class HeapBuilder
{
private:
  vector<int> data_;
  vector<pair<int, int>> swaps_;

  void WriteResponse() const
  {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i)
    {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData()
  {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwapsNaive()
  {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j)
      {
        if (data_[i] > data_[j])
        {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }

  void SiftDown(int i)
  {
    int max_index = i;
    int left_index = ((2 * i) + 1);
    int right_index = ((2 * i) + 2);
    if ((left_index < data_.size()) && (data_[max_index] > data_[left_index]))
      max_index = left_index;
    if ((right_index < data_.size()) && (data_[max_index] > data_[right_index]))
      max_index = right_index;
    if (max_index != i)
    {
      swap(data_[max_index], data_[i]);
      swaps_.push_back(make_pair(i, max_index));
      SiftDown(max_index);
    }
  }

  void GenerateSwapsFast()
  {
    for (int i = ((data_.size() - 1) / 2); i >= 0; --i)
    {
      SiftDown(i);
    }
  }

public:
  void Solve()
  {
    ReadData();
    // GenerateSwapsNaive();
    GenerateSwapsFast();
    WriteResponse();

    for (int i = 0; i < data_.size(); ++i)
    {
      std::cout << data_[i] << " ";
    }
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
