#include <iostream>
using namespace std;
//-------------------
struct SV
{
	string name;
	int day;
	int month;
	int year;
	double math;
	double physic;
	double language;
	SV *next;
};	   // dinh nghia cau truc SV
SV *L; // khai bao bien L la 1 con tro toi dau ds lien ket
//----------------
void Inp(SV *&L)
{					  // dinh nghia ham Inp de nhap thong tin sinh vien va luu tru no trong ds lien ket
	SV *P, *C = NULL; // dinh nghia con tro P va C de them 1 SV moi vao dslk
	int n;			  // khai bao bien n de nhap so luong Sv
	int count = 1;	  // khai bao bien dem SV
	cout << "Nhap so luong sinh vien: ";
	cin >> n; // nhap so luong SV
	while (count <= n)
	{				// su dung while de thuc hien viec nhap tt sv cho den so luong sv dat den gia tri n
		P = new SV; // cap phat bo nho dong cho con tro P
		cout << "Thong tin sinh vien:\n";
		cout << "Nhap ten: ";
		cin >> P->name;
		cout << "Nhap ngay sinh: ";
		cin >> P->day;
		cout << "Nhap thang sinh: ";
		cin >> P->month;
		cout << "Nhap nam sinh: ";
		cin >> P->year;
		cout << "Nhap diem toan: ";
		cin >> P->math;
		cout << "Nhap diem ly: ";
		cin >> P->physic;
		cout << "Nhap diem van: ";
		cin >> P->language;
		P->next = NULL; // thiep lap con tro P tiep theo de tro den NULL
		if (L == NULL)
		{		   // neu ds trong
			L = P; // them du lieu cua P vao L
			C = P;
		}
		else
		{				 // neu ds k rong
			C->next = P; // them du lieu cua P vao nut tiep theo cua L
			C = P;
		}
		count++; // tang bien dem
	}
}
//
void Outp(SV *L)
{		   // Dinh nghia ham Outp de xuat thong tin SV
	SV *P; // khai bao mot con tro P de duyet qua dslk
	int count = 0;
	P = L; // bat dau ds
	cout << "STT\t\t"
		 << "Ten\t\t"
		 << "Ngay sinh\t\t"
		 << "Toan\t\t"
		 << "Vat Li\t\t"
		 << "Ngu Van" << endl;
	while (P != NULL)
	{ // su dung while de duyet qua ds lien ket va in ra mh
		count++;
		cout << count << "\t\t" << P->name << "\t\t" << P->day << "/" << P->month << "/" << P->year << "\t" << P->math << "\t\t" << P->physic << "\t\t" << P->language << endl;
		P = P->next; //
	}
}
//
void Add(SV *&L)
{
	SV *P, *Q;
	P = new SV; // cap phat bo nho dong cho P
	if (P == NULL)
	{
		cout << "Khong du bo nho." << endl;
		return;
	}
	// nhap du lieu cho nut moi
	cout << "Thong tin sinh vien:\n";
	cout << "Nhap ten: ";
	cin >> P->name;
	cout << "Nhap ngay sinh: ";
	cin >> P->day;
	cout << "Nhap thang sinh: ";
	cin >> P->month;
	cout << "Nhap nam sinh: ";
	cin >> P->year;
	cout << "Nhap diem toan: ";
	cin >> P->math;
	cout << "Nhap diem ly: ";
	cin >> P->physic;
	cout << "Nhap diem van: ";
	cin >> P->language;
	P->next = NULL;
	// Th�m n�t m?i v�o cu?i danh s�ch li�n k?t
	if (L == NULL)
	{		   // neu ds rong
		L = P; // them du lieu cua P vao L
	}
	else
	{		   // neu ds k rong
		Q = L; // bat dau danh sach
		// chuyen den nut cuoi cua ds
		while (Q->next != NULL)
		{
			Q = Q->next;
		}
		Q->next = P; // them du lieu vao nut cuoi cua ds
	}
}

//
int count_student_in_year(SV *&L, int year)
{
	SV *Q;		   // Khai bao 1 con tro Q tro den danh sach sinh vi�n L
	int count = 0; // khoi tao bien dem so sv
	Q = L;		   // gan con tro Q = dau ds L
	while (Q != NULL)
	{ // dung while de duyet ds sv
		if (Q->year == year)
		{			 // kt nam sinh cua sv co bang voi nam yeu cau k
			count++; // tang count
		}
		Q = Q->next; // di chuyen con tro Q den sv tiep theo
	}
	return count;
}
//
bool has_student(SV *&L, string name)
{
	SV *Q; // Khai b�o 1 con tro Q tro den danh sach sinh vi�n L
	Q = L; // gan con tro Q = dau ds L
	while (Q != NULL)
	{ // dung while de duyet ds sv
		if (Q->name == name)
		{ // kt nam sinh cua sv co giong voi nam yeu cau k
			return true;
		}
		Q = Q->next; // di chuyen con tro Q den sv tiep theo
	}
	return false;
}
//
void delete_student(SV *&L, string name)
{
	SV *Q; // khai bao con tro Q de duyet ds SV
	SV *P; // khai bao con tro P de luu tru node truoc node can xoa
	if (L == NULL)
	{			// kiem tra truong hop ds rong
		return; // ket thuc ham
	}
	if (L->name == name)
	{				 // kt ten sinh cua sv co bang voi ten yeu cau k
		Q = L;		 // gan con tro Q = con tro dau tien trong ds L
		L = L->next; // Cap nhat dau danh s�ch lien ket de tro den nut thu hai
		delete (Q);	 // giai phong vung nho
		return;
	}
	P = L; // gan con tro P = con tro dau tien trong ds L
	while (P->next != NULL)
	{ // duyet ds
		if (P->next->name == name)
		{					   // Neu ten cua node ke tiep cua node hien tai (P->next->name) trung voi name
			Q = P->next;	   // Luu con tro den nut can xoa
			P->next = Q->next; // Cap nhat nut truoc de tro den nut tiep theo
			delete (Q);		   // giai phong vung nho
			return;
		}
		P = P->next; // di chuyen den nut tiep theo
	}
}
//
void print_students_with_math_less_than_5()
{
	SV *Q; // khai bao con tro Q tro den dssv
	int count = 0;
	Q = L; // gan con tro Q = dau ds L
	while (Q != NULL)
	{ // duyet ds
		if (Q->math < 5)
		{					 // kiem tra co dieu kien can
			cout << Q->name; // xuat ra mh
			count++;
		}
		Q = Q->next; // di chuyen con tro den node tiep theo
	}
	if (count == 0)
		cout << "0";
}
int main()
{
	L = NULL; // tro con tro L toi NULL
	string name;
	Inp(L);
	cout << "\nDanh sach:\n";
	Outp(L);
	char choice;
	do
	{
		cout << "\n1. Add a new student.\n";
		cout << "2. Count student in year.\n";
		cout << "3. Has student.\n";
		cout << "4. Print students with math less than 5.\n";
		cout << "5. Delete students.\n";
		cout << "6. Exit.\n";
		cout << "Enter your choice (1-6): ";
		cin >> choice;
		switch (choice)
		{ // tao menu
		case '1':
			Add(L);
			Outp(L);
			break;
		case '2':
			int year;
			cout << "Enter year: ";
			cin >> year;
			cout << count_student_in_year(L, year);
			break;
		case '3':
			cout << "Enter name: ";
			cin >> name;
			if (has_student(L, name))
			{
				cout << "yes";
			}
			else
				cout << "no";
			break;
		case '4':
			print_students_with_math_less_than_5();
			break;
		case '5':
			cout << "Enter name: ";
			cin >> name;
			delete_student(L, name);
			Outp(L);
			break;
		case '6':
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice.\n";
		}
		cout << endl;
	} while (choice != '6');
	delete (L); // giai phong bo nho L
	return 0;
}
