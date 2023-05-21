#include <iostream>
using namespace std;

struct node
{
	float heso;
	int somu;
	struct node *next;
};
node *L;

void Input(node *&L)
{
	node *C = NULL;
	node *P;
	int n;
	cout << "Nhap so luong hang tu: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		float heso;
		int somu;
		cout << "Nhap he so va so mu cua hang tu " << i << ": \n";
		cin >> heso;
		cin >> somu;
		P = new node;
		P->heso = heso;
		P->somu = somu;
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
	}
}

void Output(struct node *poly)
{
	if (poly == NULL) // kiem tra co da thuc nao khong
	{
		cout << "0\n";
		return;
	}

	while (poly != NULL)
	{
		if (poly->heso == 0) // neu he so = 0 thi bo qa
		{
			poly = poly->next;
			continue;
		}

		if (poly->somu == 1) // neu he so == 1
		{
			if (poly->heso == 1)
			{
				cout << "x";
			}
			else
				cout << poly->heso << "x";
		}
		else if (poly->somu == 0)
		{
			cout << poly->heso;
		}
		else if (poly->somu != 1) // neu so mu != 1
		{
			if (poly->heso == 1)
			{
				cout << "x^" << poly->somu;
			}
			else
				cout << poly->heso << "x^" << poly->somu;
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
void Insert(struct node *poly)
{
	node *P, *Q;
	char ch;
	do
	{
		P = new node; // cap phat bo nho con tro p
		cout << "Them hang tu:\n";
		cin >> P->heso;
		cin >> P->somu;
		P->next = NULL;
		if (poly == NULL)
		{
			poly = P;
		}
		Q = poly;
		while (Q->next != 0)
		{
			Q = Q->next;
		}
		Q->next = P;

		cout << "Tiep tuc?(y)";
		cin >> ch;

	} while (ch == 'y' || ch == 'Y');
}
//
struct node *Add(struct node *poly1, struct node *poly2)
{
	struct node *ketqua = NULL;
	struct node *cuoi = NULL;

	while (poly1 != NULL && poly2 != NULL)
	{
		struct node *moi = new node;

		if (poly1->somu == poly2->somu)
		{
			moi->heso = poly1->heso + poly2->heso;
			moi->somu = poly1->somu;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		else if (poly1->somu > poly2->somu)
		{
			moi->heso = poly1->heso;
			moi->somu = poly1->somu;

			poly1 = poly1->next;
		}
		else
		{
			moi->heso = poly2->heso;
			moi->somu = poly2->somu;

			poly2 = poly2->next;
		}

		moi->next = NULL;
		if (ketqua == NULL)
		{
			ketqua = moi;
			cuoi = moi;
		}
		else
		{
			cuoi->next = moi;
			cuoi = moi;
		}
	}

	while (poly1 != NULL)
	{
		struct node *moi = new node;
		moi->heso = poly1->heso;
		moi->somu = poly1->somu;
		moi->next = NULL;

		cuoi->next = moi;
		cuoi = moi;
		poly1 = poly1->next;
	}

	while (poly2 != NULL)
	{
		struct node *moi = new node;
		moi->heso = poly2->heso;
		moi->somu = poly2->somu;
		moi->next = NULL;

		cuoi->next = moi;
		cuoi = moi;
		poly2 = poly2->next;
	}
	return ketqua;
}
//
struct node *multi(struct node *p1, struct node *p2)
{
	struct node *ketqua = NULL;
	struct node *cuoi = NULL;
	struct node *temp1 = p1;
	while (temp1 != NULL)
	{
		struct node *temp2 = p2;
		while (temp2 != NULL)
		{
			struct node *moi = new node;
			moi->heso = temp1->heso * temp2->heso;
			moi->somu = temp1->somu + temp2->somu;
			moi->next = NULL;
			if (ketqua == NULL)
			{
				ketqua = moi;
				cuoi = moi;
			}
			else
			{
				cuoi->next = moi;
				cuoi = moi;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return ketqua;
}
//
int main()
{
	struct node *dathuc1 = NULL;
	struct node *dathuc2 = NULL;
	cout << "Nhap da thuc 1:\n";
	Input(dathuc1);
	Output(dathuc1);
	cout << "Nhap da thuc 2:\n";
	Input(dathuc2);
	Output(dathuc2);
	cout << "Nhan 2 da thuc:\n";
	struct node *sum = multi(dathuc1, dathuc2);
	Output(sum);
	// cout << "Chen da thuc 1:\n";
	// Insert(dathuc1);
	// Output(dathuc1);
	// cout << "Chen da thuc 2:\n";
	// Insert(dathuc2);
	// Output(dathuc2);
	delete dathuc1, dathuc2, sum;
	system("pause");
	return 0;
}