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
    //
    // TODO: replace by a more efficient implementation
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

  void GenerateSwapsFast()
  {
    for (int i = data_.size() - 1; i > 0; --i)
    {
      int idx = i;
      int parent_idx = (i - 1) / 2;
      while (data_[idx] <= data_[parent_idx])
      {
        int temp = data_[idx];
        data_[idx] = data_[parent_idx];
        data_[parent_idx] = temp;
        swaps_.push_back(make_pair(parent_idx, idx));
        idx = parent_idx;
        parent_idx = (idx - 1) / 2;
        if (idx == 0)
          break;
      }
    }
  }

public:
  void Solve()
  {
    ReadData();
    // GenerateSwapsNaive();
    GenerateSwapsFast();
    WriteResponse();

    // for (int i = 0; i < data_.size(); ++i)
    // {
    //   std::cout << data_[i] << " ";
    // }
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
