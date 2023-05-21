#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkParentheses(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string expression;
    cout << "Nhap bieu thuc";
    cin >> expression;

    if (checkParentheses(expression))
    {
        cout << "The parentheses are balanced" << endl;
    }
    else
    {
        cout << "The parentheses are not balanced" << endl;
    }
    system("pause");
    return 0;
}
