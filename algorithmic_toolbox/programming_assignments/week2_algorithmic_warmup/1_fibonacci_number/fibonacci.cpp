#include <iostream>
#include <vector>

using std::cin;
using std::cout;

long long fibonacci_naive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n)
{
    long long previous = 0;
    long long current = 1;

    if (n == 0)
    {
        return previous;
    }
    else
    {
        for (int i = 2; i <= n; ++i)
        {
            long long temp = previous + current;
            previous = current;
            current = temp;
        }
        return current;
    }
}

void stress_test()
{
    int stress_iteration = 20;
    for (int n = 0; n < stress_iteration; ++n)
    {
        long long naive = fibonacci_fast(n);
        long long fast = fibonacci_naive(n);
        if (naive == fast)
        {
            cout << "n = " << n << " OK" << '\n';
        }
        else
        {
            cout << "n = " << n << " FAILED"
                 << "\nNaive: " << naive
                 << "\nFast: " << fast << '\n';
            break;
        }
    }
}

int main()
{
    // stress_test();

    int n = 0;
    cin >> n;

    // std::cout << fibonacci_naive(n) << '\n';

    cout << fibonacci_fast(n) << '\n';
}
