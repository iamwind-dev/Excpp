#include <iostream>
using namespace std;

#define Max 10
int Queue[Max];

void add(int Q[], int &F, int &R, int x)
{
    if (F == -1 && R == -1)
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
    else if (R - F + 1 < Max)
    { // hang day can doi hang
        for (int i = F; i <= R; i++)
        {
            Q[i - F] = Q[i];
        }
        R = R - F;
        F = 0;
        Q[++R] = x;
    }
    else
    { // hang day
        cout << "hang day!";
    }
}

void remove(int Q[], int &F, int &R)
{
    if (F == -1 && R == -1)
    {
        cout << "hang rong!";
        return;
    }
    cout << Q[F] << "\t";
    if (F == R)
    { // hang con 1 ptu
        F = -1;
        R = -1;
    }
    else
    {
        F++;
    }
}

void Inp(int Q[], int &F, int &R)
{
    int x;
    char ch;
    F = -1;
    R = -1;
    do
    {
        cout << "x=";
        cin >> x;
        add(Q, F, R, x);
        cout << "tt?";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void Outp(int Q[], int &F, int &R)
{
    while (F != -1 && R != -1)
    {
        remove(Q, F, R);
    }
    F = -1; // reset F and R to -1
    R = -1;
}
//----------------------------------------------------------------
void remove(int Q[], int &F, int &R, int k)
{
    for (int i = F; i <= R; i++)
    {
    }
}

int main()
{
    int Q[Max], F = -1, R = -1;

    Inp(Q, F, R);
    Outp(Q, F, R);
    cout << endl;
    system("pause");
    return 0;
}
