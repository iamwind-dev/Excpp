#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

int precedence(char op)
{
    // Return the precedence of an operator
    // Higher number means higher precedence
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string infix)
{
    stack<char> s;                          // Stack to hold operators
    string postfix;                         // Output string to hold postfix notation
    unordered_map<char, int> op_precedence; // Map to store operator precedence

    op_precedence['+'] = 1;
    op_precedence['-'] = 1;
    op_precedence['*'] = 2;
    op_precedence['/'] = 2;

    for (char c : infix)
    {
        if (isdigit(c))
        {
            postfix += c; // If character is a digit, add it to the output string
        }
        else if (c == '(')
        {
            s.push(c); // If character is a left parenthesis, push it onto the stack
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top(); // Pop operators off the stack and add them to the output string until a left parenthesis is found
                s.pop();
            }
            s.pop(); // Pop and discard the left parenthesis
        }
        else
        {
            while (!s.empty() && op_precedence[s.top()] >= op_precedence[c])
            {
                postfix += s.top(); // Pop operators off the stack and add them to the output string until an operator with lower precedence is found
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    while (!s.empty())
    {
        postfix += s.top(); // Pop any remaining operators off the stack and add them to the output string
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix = "4 + 3 * (2 - 1)";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl; // Output should be "4 3 2 1 - * +"
    system("pause");
    return 0;
}
