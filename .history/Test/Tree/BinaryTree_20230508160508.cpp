#include <bits/stdc++.h>
using namespace std;
typedef char TData;
typedef struct TNode
{
    TData Data;
    TNode *left;
    TNode *right;
};
typedef TNode TTree;
TTree *p, *q, *T;
//================================================================
void TaoNut(char c)
{
    p = new TTree;
    p->Data = c;
    p->left = NULL;
    p->right = NULL;
}
//================================================================
void InOrder(TTree *T)
{
    TTree *p;
    p = T;
    if (p != NULL)
    {
        InOrder(p->left);
        cout << p->Data;
        InOrder(p->right);
    }
}
//================================================================
void PostOrder(TTree *T)
{
    TTree *p;
    p = T;
    if (p != NULL)
    {
        InOrder(p->left);
        InOrder(p->right);
        cout << p->Data;
    }
}
//================================================================================================
void PreOrder(TTree *T)
{
    TTree *p;
    p = T;
    if (p != NULL)
    {
        cout << p->Data;
        InOrder(p->left);
        InOrder(p->right);
    }
}
//==================================================================================================
int main()
{
    T = NULL;
    TaoNut('A');
    T = p;
    TaoNut('B');
    T->left = p;
    q = p;
    TaoNut('E');
    q->left = p;
    TaoNut('F');
    q->right = p;
    TaoNut('D');
    T->right = p;
    q = p;
    TaoNut('G');
    q->left = p;
    TaoNut('H');
    q->right = p;
    q = p;
    TaoNut('I');
    q->left = p;
    TaoNut('J');
    q->right = p;
    cout << "\nDuyet tien to: ";
    PreOrder(T);
    cout << "\nDuyet trung to: ";
    InOrder(T);
    cout << "\nDuyet hau to: ";
    PostOrder(T);
    cout << endl;
    system("pause");
    return 0;
}
