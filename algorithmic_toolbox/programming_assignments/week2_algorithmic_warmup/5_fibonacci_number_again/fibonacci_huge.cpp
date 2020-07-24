#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int get_pisano_period_length(int m)
{
    int previous = 0;
    int current = 1;
    int pisano_period_length = 0;
    do
    {
        int temp = (previous + current) % m;
        previous = current;
        current = temp;
        pisano_period_length++;
    } while (!((previous == 0) && (current == 1)));

    return pisano_period_length;
}

int fibonacci_mod(int n, int m)
{
    int previous = 0;
    int current = 1;
    for (int i = 2; i <= n; ++i)
    {
        int temp = (previous + current) % m;
        previous = current;
        current = temp;
    }
    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    int pisano_length = get_pisano_period_length(m);
    int n_mod_pisano_length = n % pisano_length;
    return fibonacci_mod(n_mod_pisano_length, m);
}

int main()
{
    long long n;
    int m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
