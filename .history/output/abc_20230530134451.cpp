#include <bits/stdc++.h>
using namespace std;

// Khai b?o c?u tr?c node
struct node
{
    int num;
    int coeff;
    node *next;
};

// H?m nh?p da th?c
node *nhapDaThuc()
{
    node *head = NULL, *tail = NULL;
    int n, num, coeff;
    cout << "Nhap so luong phan tu cua da thuc: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap he so va so mu cua phan tu " << i << ": ";
        cin >> coeff >> num;
        node *p = new node;
        p->coeff = coeff;
        p->num = num;
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

void print_poly(struct node *poly)
{
    if (poly == NULL) // kiem tra co da thuc nao khong
    {
        cout << "0\n";
        return;
    }

    while (poly != NULL)
    {
        if (poly->num == 0) // neu he so = 0 thi bo qa
        {
            poly = poly->next;
            continue;
        }

        else if (poly->num == 1) // neu he so == 1
        {
            if (poly->coeff == 0)
                cout << "1";
            else if (poly->coeff == 1)
                cout << "x";
            else
                cout << "x^" << poly->coeff;
        }
        else // neu he so != 1
        {
            if (poly->coeff == 0)
            {
                poly->num = 1;
                cout << "1";
            }
            else if (poly->coeff == 1)
            {
                cout << poly->num << "x";
            }
            else
            {
                cout << poly->num << "x^" << poly->coeff;
            }
        }

        poly = poly->next;
        if (poly != NULL && poly->num > 0) // neu chua phai node cuoi cung thi in ra
        {
            cout << " + ";
        }
    }
    cout << endl;
}

void inDaThuc(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        if (p->num == 0)
        {
            p = p->next;
            continue;
        }
        else
        {
            cout << p->coeff << "x^" << p->num;
        }
        node *q = p->next;
        if (q != NULL && q->coeff >= 0)
        {
            cout << " + ";
        }
        p = p->next;
    }
    cout << endl;
}

// H?m c?ng hai da th?c
node *congDaThuc(node *p1, node *p2)
{
    node *head = NULL, *tail = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        node *p = new node;
        if (p1->num > p2->num)
        {
            p->num = p1->num;
            p->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p1->num < p2->num)
        {
            p->num = p2->num;
            p->coeff = p2->coeff;
            p2 = p2->next;
        }
        else
        {
            p->num = p1->num;
            p->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    while (p1 != NULL)
    {
        node *p = new node;
        p->num = p1->num;
        p->coeff = p1->coeff;
        p1 = p1->next;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    while (p2 != NULL)
    {
        node *p = new node;
        p->num = p2->num;
        p->coeff = p2->coeff;
        p2 = p2->next;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return head;
}

// H?m tr? 2 da th?c
node *truDaThuc(node *p1, node *p2)
{
    node *head = NULL, *tail = NULL;
    while (p1 != NULL && p2 != NULL)
    {
        node *p = new node;
        if (p1->num > p2->num)
        {
            p->num = p1->num;
            p->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p1->num < p2->num)
        {
            p->num = p2->num;
            p->coeff = -p2->coeff;
            p2 = p2->next;
        }
        else
        {
            p->num = p1->num;
            p->coeff = p1->coeff - p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    while (p1 != NULL)
    {
        node *p = new node;
        p->num = p1->num;
        p->coeff = p1->coeff;
        p1 = p1->next;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    while (p2 != NULL)
    {
        node *p = new node;
        p->num = p2->num;
        p->coeff = -p2->coeff;
        p2 = p2->next;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return head;
}

int tinhGiaTri(node *p)
{
    int x, tinh, tong;
    cout << "Nhap x : ";
    cin >> x;
    while (p != NULL)
    {
        tinh = p->coeff * pow(x, p->num);
        tong += tinh;
        p = p->next;
    }
    cout << tong;
}

int main()
{
    node *p1 = nhapDaThuc();
    cout << "Da thuc 1: ";
    print_poly(p1);
    node *p2 = nhapDaThuc();
    cout << "Da thuc 2: ";
    print_poly(p2);
    node *p3 = congDaThuc(p1, p2);
    cout << "Tong hai da thuc: ";
    print_poly(p3);
    node *p4 = truDaThuc(p1, p2);
    cout << "Hieu hai da thuc: ";
    print_poly(p4);
    tinhGiaTri(p4);
    return 0;
}