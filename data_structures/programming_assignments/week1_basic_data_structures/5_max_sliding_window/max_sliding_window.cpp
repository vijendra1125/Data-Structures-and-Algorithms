#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using std::cin;
using std::cout;
using std::deque;
using std::max;
using std::vector;

void max_sliding_window_naive(vector<int> const &A, int w)
{
    for (size_t i = 0; i < A.size() - w + 1; ++i)
    {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

class StackWithMax
{
    vector<int> stack;
    std::stack<int> max_idx;

public:
    void Push(int value)
    {
        stack.push_back(value);
        if (stack.size() == 1)
            max_idx.push(0);
        else if (value > stack[max_idx.top()])
        {
            max_idx.push(stack.size() - 1);
        }
    }

    void Pop()
    {
        assert(stack.size());
        if (stack.size() - 1 == max_idx.top())
            max_idx.pop();
        stack.pop_back();
    }

    int Max() const
    {
        assert(stack.size());
        return stack[max_idx.top()];
    }

    int size() const
    {
        return stack.size();
    }

    int back() const
    {
        return stack.back();
    }
};

void max_sliding_window_using_two_stack(vector<int> const &A, int w)
{
    StackWithMax s1;
    StackWithMax s2;

    for (int i = 0; i < A.size(); ++i)
    {
        s2.Push(A[i]);
        if (s2.size() == w)
        {
            while (!(s2.size() == 0))
            {
                s1.Push(s2.back());
                s2.Pop();
            }
        }

        if (i >= w - 1)
        {
            if (s2.size() == 0)
                cout << s1.Max() << " ";
            else
                cout << max(s1.Max(), s2.Max()) << " ";
            s1.Pop();
        }
    }
}

void max_sliding_window_using_deque(vector<int> const &A, int w)
{
    deque<int> useful_idx;
    for (int i = 0; i < w; ++i)
    {
        while ((!useful_idx.empty()) && (A[i] > A[useful_idx.back()]))
        {
            useful_idx.pop_back();
        }
        useful_idx.push_back(i);
    }
    cout << A[useful_idx.front()] << " ";
    for (int i = w; i < A.size(); ++i)
    {
        if (useful_idx.front() == i - w)
            useful_idx.pop_front();
        while ((!useful_idx.empty()) && (A[i] > A[useful_idx.back()]))
        {
            useful_idx.pop_back();
        }
        useful_idx.push_back(i);
        cout << A[useful_idx.front()] << " ";
    }
    return;
}

int main()
{
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    // max_sliding_window_naive(A, w);
    // max_sliding_window_using_two_stack(A, w);
    max_sliding_window_using_deque(A, w);

    return 0;
}
