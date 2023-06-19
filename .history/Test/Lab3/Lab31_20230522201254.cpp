#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int x)
    {
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next = NULL;
        if (rear == NULL)
        {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
    }

    int getFront()
    {
        if (front != NULL)
        {
            return front->data;
        }
        return -1;
    }

    bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }
};

int josephus(int n, int k)
{
    Queue q;

    for (int i = 1; i <= n; ++i)
    {
        q.enqueue(i);
    }

    while (!q.isEmpty())
    {
        for (int count = 0; count < k - 1; ++count)
        {
            q.enqueue(q.getFront());
            q.dequeue();
        }
        q.dequeue();
        if (q.getFront() == -1)
        {
            if (!q.isEmpty())
            {
                return q.getFront();
            }
        }
    }
    return -1;
}

int main()
{
    int n = 7;
    int k = 3;
    std::cout << "The chosen place is " << josephus(n, k) << std::endl;
    system("pause");
    return 0;
}
