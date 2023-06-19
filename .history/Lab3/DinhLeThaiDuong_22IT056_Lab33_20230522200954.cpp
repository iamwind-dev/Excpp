#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *front, *rear;
bool isEmpty()
{
    return front == nullptr;
}

void enqueue(int value)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Heap overflow" << endl;
        exit(1);
    }
    newNode->data = value;
    newNode->next = nullptr;

    if (rear)
    {
        rear->next = newNode;
    }
    rear = newNode;

    if (!front)
    {
        front = newNode;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        exit(1);
    }

    Node *temp = front;
    front = front->next;
    temp->next = nullptr;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    delete temp;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        exit(1);
    }
    return front->data;
}

int getFront()
{
    if (front != NULL)
    {
        return front->data;
    }
    return -1;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//================================================================
int josephusProblem(int n, int k)
{

    // initialize the queue
    for (int i = 1; i <= n; ++i)
        enqueue(i);

    while (!isEmpty())
    {
        // pop k-1 people and push them back to the queue
        for (int count = 0; count < k - 1; ++count)
        {
            enqueue(getfront());
            dequeue();
        }

        // the k-th person is removed
        dequeue();
        if (getFront() == -1)
        {
            if (!isEmpty())
            {
                return getFront();
            }
        }
    }
    return -1;
}

int main()
{
    int n = 7;
    int k = 3;
    cout << "The chosen place is " << josephusProblem(n, k) << endl;
    return 0;
}
