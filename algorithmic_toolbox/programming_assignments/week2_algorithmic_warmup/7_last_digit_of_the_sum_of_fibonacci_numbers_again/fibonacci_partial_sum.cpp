#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to)
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

    long long from_by_pisano_length = from / pisano_length;
    int from_mod_pisano_length = from % pisano_length;
    long long to_by_pisano_length = to / pisano_length;
    int to_mod_pisano_length = to % pisano_length;
    int to_mod_pisano_length_sum = 0;
    for (int i = 0; i <= to_mod_pisano_length; ++i)
    {
        to_mod_pisano_length_sum += pisano_period[i];
    }
    int from_mod_pisano_length_sum = 0;
    for (int i = 0; i < from_mod_pisano_length; ++i)
    {
        from_mod_pisano_length_sum += pisano_period[i];
    }

    return (((to_by_pisano_length - from_by_pisano_length) * pisano_sum) +
            to_mod_pisano_length_sum - from_mod_pisano_length_sum) %
           m;
}

void stress_test()
{
    int stress_iteration = 75;
    int max_number = 75;

    for (int i = 0; i < stress_iteration; ++i)
    {
        int to = rand() % max_number;
        int from = rand() % to;

        int naive = get_fibonacci_partial_sum_naive(from, to);
        int fast = get_fibonacci_partial_sum_fast(from, to);
        if (naive == fast)
        {
            cout << "from = " << from << "; "
                 << "to = " << to << " "
                 << "OK" << '\n';
        }
        else
        {
            cout << "from = " << from << "; "
                 << "to = " << to << " "
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

    long long from, to;
    cin >> from >> to;

    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';

    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
