#include <iostream>
using namespace std;
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
    cin >> p.so;
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
    cout << p.so << "\t";
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
    cout << "Stack: \n";
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