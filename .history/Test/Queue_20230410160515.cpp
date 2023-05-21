#include <iostream>
using namespace std;
//----------------------------------------------------------------
#define Max 100
int Queue[Max];
//----------------------------------------------------------------
void add(int Q[100], int &F, int &R, int x)
{
    if (F == R == -1)
    { // hang rong
        F = 0;
        R = 0;
        Q[R] = x;
    }
    else if (R < Max - 1)
    { // hang chua day
        R++;
        Q[R] = x;
    }
    else if (R - F + 1 < Max) // hang day can doi hang
    {
        for (int i = F; i <= R; i++)
        {
            Q[i - F] = Q[i];
        }
        R = R - F + 1;
        F = 0;
        Q[R] = x;
    }
    else // hang day
        cout
            << "hang day!";
}
//----------------------------------------------------------------
void remove()
{
}
//----------------------------------------------------------------
void Inp()
{
}
//----------------------------------------------------------------
void Outp()
{
}
int main()
{
    int Q[Max], F = -1, R = -1;

    add(Q, F, R, 10);
    add(Q, F, R, 20);
    add(Q, F, R, 30);
    add(Q, F, R, 40);
    add(Q, F, R, 50);

    for (int i = F; i <= R; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}