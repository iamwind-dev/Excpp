#include <iostream>
using namespace std;
//---Khai bao CTDL-----
struct SV{
	char MSV[12];
	char HT[30];
	float DToan;
	float DLy;
	SV *next;
};SV *L;
//--------------------
void Inp(SV *&L){
	SV *P, *C;
	char ch;
	do{
		P = new SV;
		cout << "Thong tin sinh vien:\n";
		cout << "Nhap ho ten: ";
		cin >> P->HT;
		cout << "Nhap msv: ";
		cin >> P->MSV;
		cout << "Nhap Diem Toan: ";
		cin >> P->DToan;
		cout << "Nhap Diem Ly: ";
		cin >> P->DLy;
		P->next=NULL;
		if(L==NULL){
			L=P;
			C=P;
		}else{
			C->next=P;
			C=P;
		}	
		cout << "Tiep tuc?(y)";
		cin >> ch;
	}while(ch=='y'||ch=='Y');
}
//---------------------
void Out(SV *&L){
	SV *P;
	int dem=1;
	P=L;
	cout << "STT\t\t" << "MSV\t\t" << "HO TEN\t\t" << "TOAN\t\t" << "LY\t\t" << endl;
	while(P!=NULL){
		cout << dem << "\t\t" <<  P->MSV << "\t\t" << P->HT << "\t\t" << P->DToan << "\t\t" << P->DLy << endl;
		P=P->next;
		dem++;
	}
}
//
void Add(SV *&L){
	SV *P,*Q;
	char ch;
	do{
	P=new SV; //cap phat bo nho con tro p
	 cout << "Them sinh vien:\n";
		cout << "Nhap ten: ";
		cin >> P->HT;
		cout << "Nhap MSV: ";
		cin >> P->MSV;
		cout << "Nhap diem toan: ";
		cin >> P->DToan;
		cout << "Nhap diem ly: ";
		cin >> P->DLy;
	Q=L;
	while(Q->next!=NULL){
		Q = Q->next;
	}
		P->next=Q->next;
		Q->next=P;
		cout << "Tiep tuc?(y)";
		cin >> ch;
	}while(ch=='y'||ch=='Y');
}
//
void Del(SV *&L,string name){
	SV *Q;
	SV *P;
	if(L == NULL){
		return;
	}
	if(L->HT == name){
		Q = L;
		L = L->next;
		delete(Q);
		return;
	}
	P = L;
	while(P->next != NULL){
		if(P->next->HT == name){
			Q = L->next;
			P->next = Q->next;
			delete(Q);
			return;
		}
		P=P->next;
	}
}
//---------------------
int main(){
	L=NULL;
	Inp(L);
	cout << "Thong tin:\n";
	Out(L);
	Add(L);
	cout << "Sau khi them:\n";
	Out(L);
	delete(L);
	return 0;
}
