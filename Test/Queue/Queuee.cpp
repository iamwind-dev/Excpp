#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue
{
private:
    int front;
    int rear;
    int data[MAX_SIZE];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int item)
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "Queue overflow!" << endl;
            return;
        }
        data[++rear] = item;
        if (front == -1)
        {
            front = 0;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue underflow!" << endl;
            return;
        }
        ++front;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[front];
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }
};

int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front element after dequeue: " << queue.peek() << endl;
    system("pause");
    return 0;
}
