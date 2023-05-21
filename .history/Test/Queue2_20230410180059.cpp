#include <iostream>
using namespace std;

#define Max 10

void add(int Q[], int &F, int &R, int x)
{
    if (F == R && F == -1) // Kiểm tra Queue rỗng
    {
        F = 0;
        R = 0;
        Q[R] = x;
    }
    else if (R < Max - 1) // Kiểm tra Queue chưa đầy
    {
        R++;
        Q[R] = x;
    }
    else if (R - F + 1 < Max) // Kiểm tra Queue đã đầy
    {
        for (int i = F; i <= R; i++)
        {
            Q[i - F] = Q[i];
        }
        R = R - F;
        F = 0;
        Q[++R] = x;
    }
    else // Queue đã đầy
    {
        cout << "Queue is full." << endl;
    }
}

void remove(int Q[], int &F, int &R)
{
    if (F == -1) // Kiểm tra Queue rỗng
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Removed element: " << Q[F] << endl;
    if (F == R) // Kiểm tra còn một phần tử trong Queue
    {
        F = -1;
        R = -1;
    }
    else
    {
        F++;
    }
}

void display(int Q[], int &F, int &R)
{
    if (F == -1) // Kiểm tra Queue rỗng
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = F; i <= R; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    int Q[Max], F = -1, R = -1;
    add(Q, F, R, 10);
    add(Q, F, R, 20);
    add(Q, F, R, 30);
    display(Q, F, R);
    remove(Q, F, R);
    display(Q, F, R);
    add(Q, F, R, 40);
    add(Q, F, R, 50);
    add(Q, F, R, 60);
    add(Q, F, R, 70);
    add(Q, F, R, 80);
    add(Q, F, R, 90);
    add(Q, F, R, 100);
    display(Q, F, R);
    add(Q, F, R, 110);
    remove(Q, F, R);
    display(Q, F, R);
    return 0;
}
