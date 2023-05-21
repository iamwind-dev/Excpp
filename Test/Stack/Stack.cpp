#include <iostream>
using namespace std;
//----------------------------------------------------------------
struct DT
{
    float heso;
    int bac;
};
DT Stack[100];
int top;
//----------------------------------------------------------------
void Push(DT Stack[100], int &top, DT p)
{
    cout << "He so = ";
    cin >> p.heso;
    cout << "Bac = ";
    cin >> p.bac;
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
    DT q;
    if (top == -1)
        cout << "ngan xep rong";
    else
    {
        p = Stack[top];
        top--;
    }
    // cout << p.heso << "      " << p.bac << "\n";
    if (p.heso == 0)
    {
        return;
    }
    else if (p.bac == 1)
    {
        if (p.heso == 1)
        {
            cout << "x";
        }
        else
            cout << p.heso << "x";
    }
    else if (p.bac == 0)
    {
        cout << p.heso;
    }
    else if (p.bac != 1)
    {
        if (p.heso == 1)
        {
            cout << "x^" << p.bac;
        }
        else
            cout << p.heso << "x^" << p.bac;
    }
    q = Stack[top];
    if (top >= 0 && q.heso != 0)
    {
        cout << " + ";
    }
}
//----------------------------------------------------------------
void Tao(DT Stack[100], int &top)
{
    DT p;
    char ch;
    top = -1;
    do
    {
        Push(Stack, top, p);
        cout << "tt?";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}
//----------------------------------------------------------------
void Xuat(DT Stack[100], int &top)
{
    cout << "Phuong trinh: \n";
    while (top != -1)
    {
        Pop(Stack, top);
    }
}
int main()
{
    Tao(Stack, top);
    Xuat(Stack, top);
    cout << "\n";
    system("pause");
    return 0;
}