#include <iostream>
#include <cstdlib>

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
  for (int i = 0; i < 50; ++i)
  {
    int a = rand();
    int b = rand();
    int naive = gcd_naive(a, b);
    int fast = gcd_fast(a, b);
    if (naive != fast)
    {
      std::cout << a << " " << b << " "
                << "wrong " << naive << " " << fast << "\n";
      break;
    }
    else
    {
      std::cout << a << " " << b << " "
                << "OK"
                << "\n";
    }
  }
}

int main()
{
  //stress_test();
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
