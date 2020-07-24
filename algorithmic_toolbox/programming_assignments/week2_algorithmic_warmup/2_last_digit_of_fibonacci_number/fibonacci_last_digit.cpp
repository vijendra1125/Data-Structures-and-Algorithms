#include <iostream>

using std::cin;
using std::cout;

int fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_last_digit_fast(int n)
{
    int previous = 0;
    int current = 1;

    if (n == 0)
    {
        return previous;
    }
    else
    {
        for (int i = 2; i <= n; ++i)
        {
            int temp = previous + current;
            previous = current;
            current = temp % 10;
        }
        return current;
    }
}

void stress_test()
{
    int stress_iteration = 20;
    int max_number = 20;

    for (int i = 0; i < stress_iteration; ++i)
    {
        int n = rand() % max_number;
        int result_naive = fibonacci_last_digit_naive(n);
        int result_fast = fibonacci_last_digit_fast(n);
        if (result_naive == result_fast)
        {
            cout << "n = " << n << " OK" << '\n';
        }
        else
        {
            cout << "n = " << n << " FAILED"
                 << "\nNaive: " << result_naive
                 << "\nFast: " << result_fast << '\n';
            break;
        }
    }
}

int main()
{
    //stress_test();

    int n;
    cin >> n;

    // std::cout << get_fibonacci_last_digit_naive(n) << '\n';

    cout << fibonacci_last_digit_fast(n) << '\n';
}
