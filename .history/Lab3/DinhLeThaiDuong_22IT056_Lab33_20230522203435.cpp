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
    int _size;

public:
    Queue()
    {
        front = rear = NULL;
        _size = 0;
    }

    void enqueue(int x)
    {
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next = NULL;
        if (rear == NULL)
        {
            front = rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
        _size++;
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
        _size--;
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

    int size()
    {
        return _size;
    }
};

int josephus(int n, int k)
{
    Queue q;

    for (int i = 1; i <= n; ++i)
    {
        q.enqueue(i);
    }

    while (q.size() > 1)
    {
        for (int count = 0; count < k - 1; ++count)
        {
            q.enqueue(q.getFront());
            q.dequeue();
        }
        q.dequeue();
    }
    return q.getFront();
}

int main()
{
    int n = 7;
    int k = 3;
    std::cout << "The safe position is " << josephus(n, k) << std::endl;
    return 0;
}
