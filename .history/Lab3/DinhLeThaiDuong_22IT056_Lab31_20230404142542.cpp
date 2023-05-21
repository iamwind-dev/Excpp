#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// Hàm trả về độ ưu tiên của toán tử
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int precedence(char op)
{
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

// Hàm chuyển đổi biểu thức trung tố sang biểu thức hậu tố
string infixToPostfix(string infix)
{
    stack<char> operatorStack; // Ngăn xếp để chứa các toán tử
    string postfix = "";       // Chuỗi đầu ra chứa biểu thức hậu tố

    // Duyệt từng ký tự trong biểu thức trung tố
    for (char c : infix)
    {
        if (c == ' ')
        {
            continue; // Bỏ qua dấu cách
        }
        else if (isdigit(c))
        {
            // Nếu ký tự là một chữ số, thêm vào chuỗi đầu ra
            postfix += c;
        }
        else if (c == '(')
        {
            // Nếu ký tự là dấu ngoặc trái, đẩy vào ngăn xếp
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            // Nếu ký tự là dấu ngoặc phải, lấy ra toán tử từ ngăn xếp và thêm vào chuỗi đầu ra cho đến khi gặp dấu ngoặc trái
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Bỏ qua dấu ngoặc trái
            if (!operatorStack.empty() && operatorStack.top() == '(')
            {
                operatorStack.pop();
            }
        }
        else
        {
            // Nếu ký tự là toán tử, lấy ra các toán tử trong ngăn xếp có độ ưu tiên cao hơn hoặc bằng toán tử hiện tại và thêm vào chuỗi đầu ra
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Đẩy toán tử hiện tại vào ngăn xếp
            operatorStack.push(c);
        }
    }

    // Lấy ra các toán tử còn lại trong ngăn xếp và thêm vào chuỗi đầu ra
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

double evaluatePostfix(string postfix)
{
    stack<double> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ' ' || postfix[i] == '\t')
        {
            continue;
        }
        else if (isdigit(postfix[i]))
        {
            double num = 0;
            while (isdigit(postfix[i]))
            {
                num = num * 10 + postfix[i] - '0';
                s.push(num);
                i++;
            }
            i--;
                }
        else if (isOperator(postfix[i]))
        {
            double op1 = s.top();
            s.pop();
            double op2 = s.top();
            s.pop();
            switch (postfix[i])
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '^':
                s.push(pow(op1, op2));
                break;
            }
        }
        else
        {
            return NAN;
        }
    }
    return s.top();
}
// int main()
// {
//     // Ví dụ biểu thức trung tố
//     string infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
//     // Chuyển đổi thành biểu thức hậu tố
//     string postfix = infixToPostfix(infix);
//     cout << "Infix expression: " << infix << endl;
//     cout << "Postfix expression: " << postfix << endl;
//     system("pause");
//     return 0;
// }
int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    double result = evaluatePostfix(postfix);
    if (isnan(result))
    {
        cout << "Error: invalid expression" << endl;
    }
    else
    {
        cout << "Result: " << result << endl;
    }
    system("pause");
    return 0;
}
