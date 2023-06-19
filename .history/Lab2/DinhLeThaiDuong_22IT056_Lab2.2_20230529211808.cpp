#include <iostream>
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

//
struct node *input_poly()
{
    // Khoi tao con tro dau danh sach va con tro cuoi danh sach == NULL
    struct node *poly = NULL;
    struct node *last_term = NULL;
    // Nhap so luong cac hang tu trong da thuc
    int n;

    cout << "Enter the number of terms in the polynomial: ";
    cin >> n;
    // Lap qua tung hang tu v� nhap he so v� so mu cua no tu ban phim
    for (int i = 1; i <= n; i++)
    {
        int num, coeff;
        cout << "Enter the coefficient and exponent of term " << i << ": ";
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

//
struct node *add_poly(struct node *poly1, struct node *poly2)
{
    // Khoi tao con tro dau danh sach va con tro cuoi danh sach == NULL
    struct node *result = NULL;
    struct node *last_term = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        struct node *new_term = new node; // tao 1 moi

        if (poly1->coeff == poly2->coeff) // neu so mu == nhau thi cong he so
        {
            new_term->num = poly1->num + poly2->num; // cong he so
            new_term->coeff = poly1->coeff;          // gan so mu
            poly1 = poly1->next;                     // chuyen node tiep theo cua da thuc 1
            poly2 = poly2->next;                     // chueyn node tiep theo cua da thuc 2
        }
        else if (poly1->coeff > poly2->coeff) // neu so mu cua da thuc 1 > so mu cau da thuc 2
        {
            new_term->coeff = poly1->coeff; // gan so mu cua da thuc 1 vao node cua da thuc moi
            new_term->num = poly1->num;     // gan he so cua da thuc 1 vao da thuc moi

            poly1 = poly1->next; // chuyen den node tiep theo
        }
        else // neu so mu cua da thuc 2 > so mu cau da thuc 1
        {
            new_term->coeff = poly2->coeff; // gan so mu cua da thuc 2 vao node cua da thuc moi
            new_term->num = poly2->num;     // gan he so cua da thuc 1 vao da thuc moi

            poly2 = poly2->next; // chuyen den node tiep theo
        }

        new_term->next = NULL; // dat con tro next cau node dc tao moi == NULL
        if (result == NULL)    // neu ds dang rong
        {
            result = new_term;    // gan node dc tao moi thanh node dau tien trong ds
            last_term = new_term; // thiet lap node dc tao moi la node cuoi cung hien tai trong ds
        }
        else // neu ds dang k rong
        {
            last_term->next = new_term; // lien ket node dc tao moi voi node cuoi cung hien tai trong ds kq
            last_term = new_term;       // thiet lap node dc tao moi la node cuoi cung hien tai trong ds kq
        }
    }

    // them ca node con lai trong cac da thuc vao dskq
    while (poly1 != NULL)
    {
        struct node *new_term = new node; // tao 1 node moi de them vao ds kq
        new_term->coeff = poly1->coeff;   // sao chep he so cua node dang xet
        new_term->num = poly1->num;       // sao chep so mu cua node dang xet
        new_term->next = NULL;            // dat conn tro next cua node do thanh null

        last_term->next = new_term; // lien ket node dc tao moi vs node cuoi cung hien tai cua dskq
        last_term = new_term;       // thiet lap node dc tao moi la node cuoi cung cua dskq
        poly1 = poly1->next;        // di chuye con tro cua da thuc 1 den node tiep theo de duyet ti�p
    }

    while (poly2 != NULL)
    {
        struct node *new_term = new node; // tao 1 node moi de them vao ds kq
        new_term->coeff = poly2->coeff;   // sao chep he so cua node dang xet
        new_term->num = poly2->num;       // sao chep so mu cua node dang xet
        new_term->next = NULL;            // dat con tro next cua node do thanh null

        last_term->next = new_term; // lien ket node dc tao moi vs node cuoi cung hien tai cua dskq
        last_term = new_term;       // thiet lap node dc tao moi la node cuoi cung cua dskq
        poly2 = poly2->next;        // di chuyen con tro cua da thuc 1 den node tiep theo de duyet ti�p
    }

    return result;
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

// phep tru 2 da thuc
struct node *subtract_poly(struct node *poly1, struct node *poly2)
{
    // Khoi tao con tro dskq == NULL
    struct node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->coeff == poly2->coeff) // neu so mu == nhau thi tru he so
        {
            int num = poly1->num - poly2->num;
            if (num != 0)
            {
                struct node *newnode = new node;
                newnode->coeff = poly1->coeff;
                newnode->num = num;
                newnode->next = result;
                result = newnode;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->coeff > poly2->coeff) // neu so mu da thuc 1 > da thuc 2
        {
            struct node *newnode = new node;
            newnode->num = poly1->num;
            newnode->coeff = poly1->coeff; // them da thuc 1 vao dskq
            newnode->next = result;
            result = newnode;

            poly1 = poly1->next;
        }
        else // neu so mu da thuc 2 > da thuc 1
        {

            struct node *newnode = new node;
            newnode->coeff = poly2->coeff;
            newnode->num = -poly2->num; // doi dau he so da thuc 2 them vao ds kq
            newnode->next = result;
            result = newnode;

            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) // lap lai cac nut chua dc them o da thuc 1 de them vao da thuc kq
    {
        struct node *newnode = new node;
        newnode->num = poly1->num;
        newnode->coeff = poly1->coeff;
        newnode->next = result;
        result = newnode;
        poly1 = poly1->next;
    }
    while (poly2 != NULL) // lap lai cac nut chua dc them o da thuc 2 de them vao da thuc kq
    {
        struct node *newnode = new node;
        newnode->num = poly2->num;
        newnode->coeff = -poly2->coeff;
        newnode->next = result;
        result = newnode;
        poly2 = poly2->next;
    }

    // dao nguoc danh sach ket qua
    struct node *prev = NULL;
    struct node *current = result;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    result = prev;
    return result;
}
int main()
{
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    // Nhap da thuc 1
    cout << "Enter the first polynomial:" << endl;
    poly1 = input_poly();
    cout << "The first polynomial is:" << endl;
    print_poly(poly1);

    // Nhap da thuc 2
    cout << "Enter the second polynomial:" << endl;
    poly2 = input_poly();
    cout << "The second polynomial is:" << endl;
    print_poly(poly2);

    // Phep cong 2 da thuc
    struct node *sum = add_poly(poly1, poly2);
    cout << "The sum of the two polynomials is:" << endl;
    print_poly(sum);

    // Phep tru 2 da thuc
    struct node *diff = subtract_poly(poly1, poly2);
    cout << "The difference of the two polynomials is:" << endl;
    print_poly(diff);
    float x, result;
    cout << "Nhap x= ";
    cin >> x;
    result = calculate_poly(poly1, x);
    cout << "f(" << x << ") = " << result;
    delete (poly1);
    delete (poly2);
    system("pause");
    return 0;
}
