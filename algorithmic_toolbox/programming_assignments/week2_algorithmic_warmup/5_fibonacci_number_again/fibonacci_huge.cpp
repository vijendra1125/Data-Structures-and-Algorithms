#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

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

void get_pisano_period(long long m, vector<long long> &pisano_period)
{
    long long previous = 0;
    long long current = 1;
    pisano_period.push_back(previous);
    pisano_period.push_back(current);

    do
    {
        long long temp = (previous + current) % m;
        previous = current;
        current = temp;
        pisano_period.push_back(current);
    } while (!((previous == 0) && (current == 1)));
    pisano_period.pop_back();
    pisano_period.pop_back();
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    vector<long long> pisano_period;
    get_pisano_period(m, pisano_period);
    long long n_mod_pisano_length = n % pisano_period.size();
    return pisano_period[n_mod_pisano_length];
}

void stress_test()
{
    int stress_iteration = 75;
    long long max_number = 75;

    for (int i = 0; i < stress_iteration; ++i)
    {
        long long a = rand() % max_number + 2;
        long long b = rand() % max_number + 2;

        long long naive = get_fibonacci_huge_naive(a, b);
        long long fast = get_fibonacci_huge_fast(a, b);
        if (naive == fast)
        {
            cout << "a = " << a << "; "
                 << "b = " << b << " "
                 << "OK" << '\n';
        }
        else
        {
            cout << "a = " << a << "; "
                 << "b = " << b << " "
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

    long long n;
    long long m;
    cin >> n >> m;

    // cout << get_fibonacci_huge_naive(n, m) << '\n';

    cout << get_fibonacci_huge_fast(n, m) << '\n';
}
