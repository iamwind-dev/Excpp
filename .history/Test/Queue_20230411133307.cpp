#include <iostream>
using namespace std;
//----------------------------------------------------------------
#define Max 100
int Queue[Max];
//----------------------------------------------------------------
struct DT
{
    int so;
};
DT Stack[100];
int top;
//----------------------------------------------------------------
void Push(DT Stack[100], int &top, DT p)
{
    if (top == 99)
        cout << "ngan xep day";
    else
    {
        top++;
        Stack[top] = p;
    }
}
//----------------------------------------------------------------
void Pop(DT Stack[100], int &top)
{
    DT p;
    if (top == -1)
        cout << "ngan xep rong";
    else
    {
        p = Stack[top];
        top--;
    }
    cout << p.so << "\t";
}
//----------------------------------------------------------------
void Xuat(DT Stack[100], int &top)
{
    cout << "Stack: \n";
    while (top != -1)
    {
        Pop(Stack, top);
    }
}
//----------------------------------------------------------------
void remove(int Q[100], int &F, int &R)
{
    top = -1;
    DT p;
    for (int i = F; i <= R; i++)
    {
        p.so = Q[i];
        Push(Stack, top, p);
    }
}
//----------------------------------------------------------------
void add(int Q[100], int &F, int &R, int x)
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
    else if (R - F + 1 < Max) // hang day can doi hang
    {
        // for (int i = F; i <= R; i++)
        // {
        //     Q[i - F] = Q[i];
        // }
        // R = R - F + 1;
        // F = 0;
        // Q[++R] = x;
        for (int i = F; i <= R; i++)
        {
            Q[i - F] = Q[i];
            R = i - F + 1;
            F = 0;
            Q[R] = x;
        }
    }
    else // hang day
        cout
            << "hang day!";
}
//----------------------------------------------------------------
void deletee(int Q[100], int &F, int &R)
{
    int x;
    if (F == R == -1)
        cout << "hang rong!";
    else if (F == R && F != -1)
    {
        x = Q[F];
        F = R = -1;
    }
    else
    {
        x = Q[F];
        F++;
    }
    cout << x << "\t";
}
//----------------------------------------------------------------
void Inp(int Q[100], int &F, int &R)
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
//----------------------------------------------------------------
void Outp(int Q[100], int &F, int &R)
{
    for (int i = F; i <= R; i++)
    {
        deletee(Q, F, R);
    }
}
int main()
{
    int Q[Max], F = 0, R = -1;
    Inp(Q, F, R);
    Outp(Q, F, R);
    cout << endl;
    remove(Q, F, R);
    Xuat(Stack, top);
    cout << endl;
    system("pause");
    return 0;
}