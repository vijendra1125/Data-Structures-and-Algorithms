#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    int remaining_dist = dist;
    int current_stop = 0;
    int refill_stop_count = 0;
    while (remaining_dist > tank)
    {
        for (int i = (current_stop + 1); i < stops.size(); ++i)
        {
            if (stops[i] - stops[current_stop] > tank)
            {
                if (i - 1 == current_stop)
                {
                    return -1;
                }
                else
                {
                    current_stop = i - 1;
                    refill_stop_count++;
                    remaining_dist = dist - stops[i - 1];
                    break;
                }
            }
        }
    }
    return refill_stop_count;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
