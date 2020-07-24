#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
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

  return first;
}

void stress_test()
{
  int stress_iteration = 20;
  int max_number = 2 * 1000000000;

  for (int i = 0; i < stress_iteration; ++i)
  {
    int a = rand() % max_number;
    int b = rand() % max_number;

    int naive = gcd_naive(a, b);
    int fast = gcd_fast(a, b);
    if (naive == fast)
    {
      cout << "a = " << a << "; "
           << "b = " << b << " "
           << "OK" << '\n';
    }
    else
    {
      cout << "a = " << a << "; "
           << "b = " << b << "; "
           << "FAILED "
           << "\nNaive: " << naive
           << "\nFast: " << fast << '\n';
      break;
    }
  }
}

int main()
{
  // stress_test();

  int a, b;
  cin >> a >> b;

  //std::cout << gcd_naive(a, b) << '\n';

  cout << gcd_fast(a, b) << '\n';
}
