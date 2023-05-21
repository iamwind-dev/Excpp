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
void Inpf(SN *&L)
{
	SN *P;
	P = new SN;
	cout << "\nso= ";
	cin >> P->so;
	if (L == NULL)
	{
		L = P;
	}
	else
	{
		P->next = L;
		L = P;
	}
}
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
	P = new SN; // cap phat bo nho con tro p
	P->so = x;	// gan gia tri x vao truong so cua con tro p
	Q = L;
	while (Q->next != NULL)
	{
		Q = Q->next;
	}
	P->next = Q->next;
	Q->next = P;
}
//
void Del(SN *&L, int k)
{
	int dem = 0;
	SN *P, *Q;
	P = new SN;
	Q = L;
	while (dem < k && Q != NULL)
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
	Inpf(L);
	Outp(L);
	system("pause");
	return 0;
}
