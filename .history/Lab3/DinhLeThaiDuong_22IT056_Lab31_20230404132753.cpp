#include <iostream>

using namespace std;

// Node struct for singly linked list
struct Node
{
    double value;
    Node *next;

    Node(double value)
    {
        this->value = value;
        next = nullptr;
    }
};

// Stack class using singly linked list
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(double value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    double pop()
    {
        if (isEmpty())
        {
            cerr << "Error: stack underflow" << endl;
            return;
        }
        else
        {
            Node *temp = top;
            double value = temp->value;
            top = temp->next;
            delete temp;
            return value;
        }
    }

    double peek()
    {
        if (isEmpty())
        {
            cerr << "Error: stack underflow" << endl;
            return;
        }
        else
        {
            return top->value;
        }
    }
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.pop() << endl;  // prints 3
    cout << stack.pop() << endl;  // prints 2
    cout << stack.peek() << endl; // prints 1

    return 0;
}
