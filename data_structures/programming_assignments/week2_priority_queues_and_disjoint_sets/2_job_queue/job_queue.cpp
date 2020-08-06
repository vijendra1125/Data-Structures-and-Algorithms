#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::vector;

class JobQueue
{
private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const
  {
    for (int i = 0; i < jobs_.size(); ++i)
    {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData()
  {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for (int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobsNaive()
  {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i)
    {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j)
      {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
  }

  void AssignJobsFast()
  {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    pair<int, long long> thread_finish_time[num_workers_];
    for (int i = 0; i < num_workers_; ++i)
    {
      assigned_workers_[i] = i;
      start_times_[i] = 0;
      thread_finish_time[i] = make_pair(i, jobs_[i]);
    }

    int priority_job_id = num_workers_;
    while (priority_job_id < jobs_.size())
    {
      int parent_id = 0;
      while (((2 * parent_id) + 1) < num_workers_)
      {
        int child_id = (2 * parent_id) + 1;
        if (((2 * parent_id) + 2) < num_workers_)
        {
          if (thread_finish_time[child_id].second > thread_finish_time[(2 * parent_id) + 2].second)
          {
            child_id = (2 * parent_id) + 2;
          }
        }
        if (thread_finish_time[parent_id].second > thread_finish_time[child_id].second)
        {
          std::swap(thread_finish_time[parent_id], thread_finish_time[child_id]);
          parent_id = child_id;
        }
        else if (thread_finish_time[parent_id].second == thread_finish_time[child_id].second)
        {
          if (thread_finish_time[parent_id].first > thread_finish_time[child_id].first)
          {
            std::swap(thread_finish_time[parent_id], thread_finish_time[child_id]);
            parent_id = child_id;
          }
          else
            break;
        }
        else
          break;
      }
      start_times_[priority_job_id] = thread_finish_time[0].second;
      assigned_workers_[priority_job_id] = thread_finish_time[0].first;
      thread_finish_time[0].second += jobs_[priority_job_id];
      priority_job_id++;
    }
  }

public:
  void Solve()
  {
    ReadData();
    // AssignJobsNaive();
    AssignJobsFast();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
