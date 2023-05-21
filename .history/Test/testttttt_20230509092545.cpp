#include <iostream>
using namespace std;
//
struct SN
{
	int so;
	SN *next;
};
SN *L;
//
void Inp(SN *&L)
{
	SN *P, *C;
	char ch;
	do
	{
		P = new SN;
		cout << "so= ";
		cin >> P->so;
		P->next = NULL;
		if (L == NULL)
		{
			L = P;
			C = P;
		}
		else
		{
			C->next = P;
			C = P;
		}
		cout << "Tiep tuc?(y)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
//
void Outp(SN *L)
{
	SN *P;
	P = L;
	while (P != NULL)
	{
		cout << P->so << " ";
		P = P->next;
	}
}
//
void Insert(SN *&L, int x, int k)
{
	SN *P, *Q;
	int dem = 1;
	P = new SN; // cap phat bo nho con tro p
	P->so = x;	// gan gia tri x vao truong so cua con tro p
	Q = L;
	while (dem < k && Q != NULL)
	{
		dem++;
		Q = Q->next;
	}
	P->next = Q->next;
	Q->next = P;
}
//
void Del(SN *&L, int k)
{
	int dem = 1;
	SN *P, *Q;
	P = new SN;
	Q = L;
	while (dem = k && Q != NULL)
	{
		dem++;
		Q = Q->next;
	}
	if (Q != NULL)
	{
		P = Q->next;
		Q->next = P->next;
		delete (P);
	}
	else
	{
		cout << "error";
	}
}
//
int main()
{
	int x, k;
	L = NULL;
	Inp(L);
	cout << "\nDanh sach:\n";
	Outp(L);
	cin >> x >> k;
	Insert(L, x, k);
	cout << "\nDanh sach sau xoa:\n";
	Outp(L);
	cin >> x >> k;
	Del(L, k);
	delete (L);
	system("pause");
	return 0;
}
