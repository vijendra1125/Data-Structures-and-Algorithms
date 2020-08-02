#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
    Bracket(char type, int position) : type(type),
                                       position(position)
    {
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            Bracket next_bracket(next, position);
            opening_brackets_stack.push(next_bracket);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            Bracket stack_top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!stack_top.Matchc(next))
            {
                std::cout << position + 1 << '\n';
                exit(0);
            }
        }
    }

    if (opening_brackets_stack.empty())
    {
        std::cout << "Success" << '\n';
    }
    else
    {
        std::cout << opening_brackets_stack.top().position + 1 << '\n';
    }

    return 0;
}
