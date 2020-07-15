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

long long pisano_period(long long m)
{
    long long previous = 0;
    long long current = 1;
    long long pisano_period_length = 0;
    do
    {
        long long temp = (previous + current) % m;
        previous = current;
        current = temp;
        pisano_period_length++;
    } while (!((previous == 0) && (current == 1)));

    return pisano_period_length;
}

long long fibonacci_mod(long long n, long long m)
{
    long long previous = 0;
    long long current = 1;
    for (int i = 2; i <= n; ++i)
    {
        long long temp = (previous + current) % m;
        previous = current;
        current = temp;
    }
    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    long long pisano = pisano_period(m);
    long long reminder = n % pisano;
    return fibonacci_mod(reminder, m);
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
