#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using std::cin;
using std::cout;
using std::max_element;
using std::string;
using std::vector;

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
        // return *max_element(stack.begin(), stack.end());
        return stack[max_idx.top()];
    }
};

int main()
{
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i)
    {
        cin >> query;
        if (query == "push")
        {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop")
        {
            stack.Pop();
        }
        else if (query == "max")
        {
            cout << stack.Max() << "\n";
        }
        else
        {
            assert(0);
        }
    }
    return 0;
}