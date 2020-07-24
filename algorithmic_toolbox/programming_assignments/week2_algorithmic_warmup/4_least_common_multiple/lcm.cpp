#include <iostream>

using std::cin;
using std::cout;

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

long long lcm_fast(int a, int b)
{
  int first = a;
  int second = b;

  if (a < b)
  {
    first = b;
    second = a;
  }

  while (second != 0)
  {
    int temp = first % second;
    first = second;
    second = temp;
  }
  long long lcm = (long long)a * (b / first);
  return lcm;
}

void stress_test()
{
  int stress_iteration = 50;
  int max_number = 10000;

  for (int i = 0; i < stress_iteration; ++i)
  {
    int a = rand() % max_number;
    int b = rand() % max_number;

    long long naive = lcm_naive(a, b);
    long long fast = lcm_fast(a, b);
    if (naive == fast)
    {
      cout << "a = " << a << "; "
           << "b = " << b << " "
           << "OK"
           << "\n";
    }
    else
    {
      cout << "a = " << a << "; "
           << "b = " << b << " "
           << "FAILED "
           << "\nNaive: " << naive
           << "\nFast: " << fast << "\n";
      break;
    }
  }
}

int main()
{
  // stress_test();

  int a, b;
  cin >> a >> b;

  // cout << lcm_naive(a, b) << '\n';

  cout << lcm_fast(a, b) << '\n';
}
