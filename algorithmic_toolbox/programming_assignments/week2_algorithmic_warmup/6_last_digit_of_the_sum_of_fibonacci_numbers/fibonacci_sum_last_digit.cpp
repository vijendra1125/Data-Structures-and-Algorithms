#include <iostream>
#include <vector>

using std::vector;

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
    int m = 10;

    int pisano_previous = 0;
    int pisano_current = 1;
    int pisano_sum = 0;
    vector<int> pisano_period;
    pisano_period.push_back(0);
    pisano_period.push_back(1);
    do
    {
        int temp = (pisano_previous + pisano_current) % m;
        pisano_previous = pisano_current;
        pisano_current = temp;
        pisano_period.push_back(pisano_current);
        pisano_sum += pisano_current;
    } while (!((pisano_previous == 0) && (pisano_current == 1)));

    int pisano_length = pisano_period.size() - 2;

    int n_mod_pisano_length = n % pisano_length;
    int n_mod_pisano_length_sum = 0;
    for (int i = 0; i <= n_mod_pisano_length; ++i)
    {
        n_mod_pisano_length_sum += pisano_period[i];
    }
    return (((n / pisano_length) * pisano_sum) + n_mod_pisano_length_sum) % m;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << "\n";
    std::cout << fibonacci_sum_fast(n) << "\n";
}
