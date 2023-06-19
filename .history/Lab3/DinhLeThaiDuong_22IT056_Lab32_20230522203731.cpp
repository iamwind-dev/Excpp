#include <iostream>
#include <stack>
#include <string>

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
bool checkParentheses(string expression)
{

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{')
        {
            push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (isEmpty())
            {
                return false;
            }
            char top = topp();
            pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return isEmpty();
}

int main()
{
    string expression;
    cout << "Nhap bieu thuc: ";
    cin >> expression;

    if (checkParentheses(expression))
    {
        cout << "Hop le!" << endl;
    }
    else
    {
        cout << "Khong hop le!" << endl;
    }
    system("pause");
    return 0;
}
