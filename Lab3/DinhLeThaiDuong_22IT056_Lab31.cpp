#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
struct ST
{
    int data;
    ST *next;
};
ST *top;
void push(int value)
{
    ST *newNode = new ST();
    if (!newNode)
    {
        cout << "Heap overflow" << endl;
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
bool isEmpty()
{
    return top == nullptr;
}

int topp()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        cout << "Stack is empty" << endl;
        exit(1);
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    else
    {
        ST *temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        ST *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
//============================================================================
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
string infixToPostfix(string infix)
{

    string postfix = ""; // Chuỗi đầu ra chứa biểu thức hậu tố

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
            push(c);
        }
        else if (c == ')')
        {
            // Nếu ký tự là dấu ngoặc phải, lấy ra toán tử từ ngăn xếp và thêm vào chuỗi đầu ra cho đến khi gặp dấu ngoặc trái
            while (!isEmpty() && topp() != '(')
            {
                postfix += topp();
                pop();
            }
            // Bỏ qua dấu ngoặc trái
            if (!isEmpty() && topp() == '(')
            {
                pop();
            }
        }
        else
        {
            // Nếu ký tự là toán tử, lấy ra các toán tử trong ngăn xếp có độ ưu tiên cao hơn hoặc bằng toán tử hiện tại và thêm vào chuỗi đầu ra
            while (!isEmpty() && precedence(topp()) >= precedence(c))
            {
                postfix += topp();
                pop();
            }
            // Đẩy toán tử hiện tại vào ngăn xếp
            push(c);
        }
    }

    // Lấy ra các toán tử còn lại trong ngăn xếp và thêm vào chuỗi đầu ra
    while (!isEmpty())
    {
        postfix += topp();
        pop();
    }

    return postfix;
}
double evaluatePostfix(string postfix)
{

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
                push(num);
                num = 0;
                i++;
            }
            i--;
        }
        else if (isOperator(postfix[i]))
        {
            double op2 = topp();
            pop();
            double op1 = topp();
            pop();
            switch (postfix[i])
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '^':
                push(pow(op1, op2));
                break;
            }
        }
        else
        {
            return NAN;
        }
    }
    return topp();
}
int main()
{
    string infix, postfix;
    cout << "Nhập biểu thức trung tố: ";
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    cout << "Biểu thức hậu tố: " << postfix << endl;
    double result = evaluatePostfix(postfix);
    if (isnan(result))
    {
        cout << "Error: invalid expression" << endl;
    }
    else
    {
        cout << "Kết quả: " << result << endl;
    }
    system("pause");
    return 0;
}