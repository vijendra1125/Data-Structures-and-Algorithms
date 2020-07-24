#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

long long max_pairwise_product_naive(const vector<int> &numbers)
{
    long long max_product = 0;
    int n = numbers.size();
    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product,
                                   ((long long)numbers[first]) * numbers[second]);
        }
    }
    return max_product;
}

long long max_pairwise_product_fast(const vector<int> &number)
{
    int n = number.size();
    int max_index1 = -1;
    int max_index2 = -1;
    for (int idx1 = 0; idx1 < n; ++idx1)
    {
        if ((max_index1 == -1) || (number[idx1] > number[max_index1]))
        {
            max_index1 = idx1;
        }
    }
    for (int idx2 = 0; idx2 < n; ++idx2)
    {
        if (((max_index2 == -1) || (number[idx2] > number[max_index2])) && (idx2 != max_index1))
        {
            max_index2 = idx2;
        }
    }
    return ((long long)number[max_index1]) * number[max_index2];
}

void stress_test()
{
    int stress_iteration = 50000;
    int number_count = 100;
    int max_number = 100000;

    for (int i = 0; i < stress_iteration; ++i)
    {
        int n = rand() % number_count + 2;
        cout << "number of entry: " << n << "\n";
        cout << "numbers: ";
        vector<int> numbers;
        for (int i = 0; i < n; ++i)
        {
            int number = rand() % max_number;
            numbers.push_back(number);
            cout << number << ' ';
        }
        cout << '\n';

        long long result = max_pairwise_product_naive(numbers);
        long long result_fast = max_pairwise_product_fast(numbers);
        if (result == result_fast)
        {
            cout << "OK" << '\n';
        }
        else
        {
            cout << "FAILED: "
                 << "\nNaive: " << result
                 << "\nFast: " << result_fast << '\n';
            break;
        }
    }
}

int main()
{
    //stress_test();

    int n;
    std::cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    // long long result = max_pairwise_product_naive(numbers);
    //cout << result << '\n';

    long long result_fast = max_pairwise_product_fast(numbers);
    cout << result_fast << '\n';
}
