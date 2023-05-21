#include <iostream>
using namespace std;
//----------------------------------------------------------------
#define Max 100
int Queue[Max];
//----------------------------------------------------------------
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
//----------------------------------------------------------------
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
                num = 0;
                i++;
            }
            i--;
        }
        else if (isOperator(postfix[i]))
        {
            double op2 = s.top();
            s.pop();
            double op1 = s.top();
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
//----------------------------------------------------------------
struct DT
{
    char so;
};
DT Stack[100];
int top;
//----------------------------------------------------------------
void Push(DT Stack[100], int &top, DT p)
{
    if (top == 99)
        cout << "ngan xep day";
    else
    {
        top++;
        Stack[top] = p;
    }
}
//----------------------------------------------------------------
int Pop(DT Stack[100], int &top)
{
    DT p;
    if (top == -1)
        cout << "ngan xep rong";
    else
    {
        p = Stack[top];
        top--;
    }
    return p.so;
}
//----------------------------------------------------------------
void Xuat(DT Stack[100], int &top)
{
    cout << "Stack: \n";
    while (top != -1)
    {
        Pop(Stack, top);
    }
}
//----------------------------------------------------------------
void remove(int Q[100], int &F, int &R, int k)
{
    DT p;
    top = -1;
    for (int i = F; i < k; i++)
    {
        p.so = Q[i];
        Push(Stack, top, p);
    }
    for (int i = k; i > 0; i--)
    {
        Q[i] = Pop(Stack, top);
    }
    for (int i = F; i<=R; i++){
        for (int j = 1; j <= R; j++){
            Q[j] = Q[i];
        }
    }
}
//----------------------------------------------------------------
void add(int Q[100], int &F, int &R, int x)
{
    if (F == -1 && R == -1)
    { // hang rong
        F = 0;
        R = 0;
        Q[R] = x;
    }
    else if (R < Max - 1)
    { // hang chua day
        R++;
        Q[R] = x;
    }
    else if (R - F + 1 < Max) // hang day can doi hang
    {
        // for (int i = F; i <= R; i++)
        // {
        //     Q[i - F] = Q[i];
        // }
        // R = R - F + 1;
        // F = 0;
        // Q[++R] = x;
        for (int i = F; i <= R; i++)
        {
            Q[i - F] = Q[i];
            R = i - F + 1;
            F = 0;
            Q[R] = x;
        }
    }
    else // hang day
        cout
            << "hang day!";
}
//----------------------------------------------------------------
void deletee(int Q[100], int &F, int &R)
{
    int x;
    if (F == R == -1)
        cout << "hang rong!";
    else if (F == R && F != -1)
    {
        x = Q[F];
        F = R = -1;
    }
    else
    {
        x = Q[F];
        F++;
    }
    cout << x << "\t";
}
//----------------------------------------------------------------
void Inp(int Q[100], int &F, int &R)
{
    int x;
    char ch;
    F = -1;
    R = -1;
    do
    {
        cout << "x=";
        cin >> x;
        add(Q, F, R, x);
        cout << "tt?";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
//----------------------------------------------------------------
void Outp(int Q[100], int &F, int &R)
{
    for (int i = F; i <= R; i++)
    {
        deletee(Q, F, R);
    }
}
int main()
{
    int Q[Max], F = -1, R = -1;
    Inp(Q, F, R);
    remove(Q, F, R, 2);
    cout << endl;
    Xuat(Stack, top);
    cout << endl;
    Outp(Q, F, R);
    cout << endl;
    system("pause");
    return 0;
}