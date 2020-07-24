#include <iostream>

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
  for (int i = 0; i < 50; ++i)
  {
    int a = rand() % 1000;
    int b = rand() % 1000;
    long long naive = lcm_naive(a, b);
    long long fast = lcm_fast(a, b);
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
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
