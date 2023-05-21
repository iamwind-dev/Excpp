#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Structure of a node in the linked list
struct node
{
    int num;
    int coeff;
    struct node *next;
}; // dinh nghia cau truc node

// Function to print the polynomial
void print_poly(struct node *poly)
{
    if (poly == NULL) // kiem tra co da thuc nao khong
    {
        cout << "0\n";
        return;
    }

    while (poly != NULL)
    {
        if (poly->coeff == 0) // neu he so = 0 thi bo qa
        {
            cout << poly->num;
        }

        else if (poly->coeff == 1) // neu he so == 1
        {
            cout << poly->num << "x";
        }
        else // neu he so != 1
        {
            cout << poly->num << "x^" << poly->coeff;
        }

        poly = poly->next;
        if (poly != NULL) // neu chua phai node cuoi cung thi in ra
        {
            cout << " + ";
        }
    }
    cout << endl;
}

//
struct node *input_poly()
{
    // Khoi tao con tro dau danh sach va con tro cuoi danh sach == NULL
    struct node *poly = NULL;
    struct node *last_term = NULL;
    // Nhap so luong cac hang tu trong da thuc
    int n;

    cout << "Nhap so luong phan tu cua da thuc: ";
    cin >> n;
    // Lap qua tung hang tu v� nhap he so v� so mu cua no tu ban phim
    for (int i = 1; i <= n; i++)
    {
        int num, coeff;
        cout << "Nhap he so va so mu cua phan tu: " << i << ": ";
        cin >> num >> coeff;
        // Tao 1 nut moi va gan gia tri cho no
        struct node *new_term = new node;
        new_term->num = num;
        new_term->coeff = coeff;
        new_term->next = NULL;
        // Neu danh sach lien ket dang rong, thi nut moi se tro thanh dau danh sach va cung la cuoi danh sach
        if (poly == NULL)
        {
            poly = new_term;
            last_term = new_term;
        }
        else
        {
            // Neu dslk khong rong, nut moi se duoc them vao cuoi danh sach
            last_term->next = new_term;
            last_term = new_term;
        }
    }
    return poly;
}

float calculate_poly(struct node *poly, float x)
{
    float result = 0.0;
    while (poly != NULL)
    {
        result += poly->num * pow(x, poly->coeff);
        poly = poly->next;
    }
    return result;
}

int main()
{
    float x;
    struct node *poly1 = NULL;
    // Nhap da thuc 1
    cout << "Nhap da thuc:" << endl;
    poly1 = input_poly();
    cout << "f(x)= ";
    print_poly(poly1);
    cout << "Nhap x:" << endl;
    cin >> x;
    float result = calculate_poly(poly1, x);
    cout << "f(" << x << ")= " << result << endl;
    delete (poly1);
    system("pause");
    return 0;
}
