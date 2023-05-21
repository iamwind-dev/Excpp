#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
private:
    int top;
    int data[MAX_SIZE];

public:
    Stack()
    {
        top = -1;
    }

    void push(int item)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = item;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        --top;
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element after popping: " << stack.peek() << endl;

    return 0;
}
