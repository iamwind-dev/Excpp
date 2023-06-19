#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node *front, *rear;
int _size = 0;

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

int josephus(int n, int k)
{

    for (int i = 1; i <= n; ++i)
    {
        enqueue(i);
    }

    while (size() > 1)
    {
        for (int count = 0; count < k - 1; ++count)
        {
            enqueue(getFront());
            dequeue();
        }
        dequeue();
    }
    return getFront();
}

int main()
{
    int n = 7;
    int k = 3;
    cout << "Vị trí an toàn là " << josephus(n, k) << endl;
    system("pause");
    return 0;
}
