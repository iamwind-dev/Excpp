#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    // Trả về độ ưu tiên của toán tử
    // Số cao hơn có độ ưu tiên cao hơn
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
    stack<char> s;  // Ngăn xếp để chứa các toán tử
    string postfix; // Chuỗi đầu ra chứa biểu thức hậu tố

    for (char c : infix)
    {
        if (isdigit(c))
        {
            postfix += c; // Nếu ký tự là một chữ số, thêm vào chuỗi đầu ra
        }
        else if (c == '(')
        {
            s.push(c); // Nếu ký tự là dấu ngoặc trái, đẩy vào ngăn xếp
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top(); // Lấy ra toán tử từ ngăn xếp và thêm vào chuỗi đầu ra đến khi gặp dấu ngoặc trái
                s.pop();
            }
            s.pop(); // Bỏ qua dấu ngoặc trái
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c))
            {
                postfix += s.top(); // Lấy ra toán tử từ ngăn xếp và thêm vào chuỗi đầu ra đến khi gặp toán tử có độ ưu tiên thấp hơn
                s.pop();
            }
            s.push(c); // Đẩy toán tử hiện tại vào ngăn xếp
        }
    }

    while (!s.empty())
    {
        postfix += s.top(); // Lấy ra các toán tử còn lại từ ngăn xếp và thêm vào chuỗi đầu ra
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix = "4 + 3 * (2 - 1)";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl; // Đầu ra sẽ là "4 3 2 1 - * +"
    return 0;
}
