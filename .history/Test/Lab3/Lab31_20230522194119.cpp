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

int peek()
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
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    cout << "Top element is: " << peek() << endl;
    pop();
    display();
    cout << "Top element is: " << peek() << endl;
    system("pause");
    return 0;
}