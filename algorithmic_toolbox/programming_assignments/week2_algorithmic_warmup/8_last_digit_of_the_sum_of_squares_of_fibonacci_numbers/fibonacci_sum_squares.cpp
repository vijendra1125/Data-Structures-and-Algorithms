#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int fibonacci_sum_squares_naive(long long n)
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
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n)
{
    int m = 10;

    int pisano_previous = 0;
    int pisano_current = 1;

    int square_pisano_previous = 0;
    int square_pisano_current = 1;
    int square_pisano_sum = 0;
    vector<int> square_pisano_period;
    square_pisano_period.push_back(0);
    square_pisano_period.push_back(1);

    do
    {
        int temp = (pisano_previous + pisano_current) % m;
        pisano_previous = pisano_current;
        pisano_current = temp;

        int temp_square = (temp * temp) % m;
        square_pisano_previous = square_pisano_current;
        square_pisano_current = temp_square;
        square_pisano_period.push_back(square_pisano_current);
        square_pisano_sum += square_pisano_current;
    } while (!((square_pisano_previous == 0) && (square_pisano_current == 1)));

    int square_pisano_lenght = square_pisano_period.size() - 2;

    int n_mod_square_pisano_length = n % square_pisano_lenght;
    int n_mod_square_pisano_length_sum = 0;
    for (int i = 0; i <= n_mod_square_pisano_length; ++i)
    {
        n_mod_square_pisano_length_sum += square_pisano_period[i];
    }
    return (((n / square_pisano_lenght) * square_pisano_sum) +
            n_mod_square_pisano_length_sum) %
           m;
}

void stress_test()
{
    int stress_iteration = 10;
    int max_number = 10;

    for (int i = 0; i < stress_iteration; ++i)
    {
        int n = rand() % max_number + 2;

        int naive = fibonacci_sum_squares_naive(n);
        int fast = fibonacci_sum_squares_fast(n);
        if (naive == fast)
        {
            cout << "n = " << n << "; "
                 << "OK" << '\n';
        }
        else
        {
            cout << "n = " << n << "; "
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

    long long n = 0;
    std::cin >> n;

    // std::cout << fibonacci_sum_squares_naive(n) << "\n";

    std::cout << fibonacci_sum_squares_fast(n) << "\n";
}
