#include <iostream>
#include <string.h>
using namespace std;
//-------------------
struct HD{
	char mahd[10];
	char makh[10];
	string ht;
	int sokw;
	HD *next;
};
HD *L;

void Out(HD *&L){
	HD *P;
	int count=1;
	P=L;
	cout << "STT\t\t" << "MHD\t\t" << "MKH\t\t" << "HT\t\t" << "So kw\t\t" << endl;
	while(P!=NULL){
		cout << count << "\t\t" <<  P->mahd << "\t\t" << P->makh << "\t\t" << P->ht << "\t\t" << P->sokw << endl;
		P=P->next;
		count++;
	}
	
}

void Inp(HD *&L){
	HD *P;
	char ch;
	do{
		P = new HD;
		cout << "Thong tin KH :\n";
		cout << "Nhap ma KH: ";
		cin >> P->makh;
		cout << "Nhap ma HD: ";
		cin >> P->mahd;
		cout << "Nhap Ho ten: ";
		cin >> P->ht;
		cout << "Nhap so KW: ";
		cin >> P->sokw;
		P->next=NULL;
		if(L==NULL){
			L=P;
		}else{
			L->next=P;
		}
		cout << "Tiep tuc?(y)";
		cin >> ch;
	}while(ch=='y'||ch=='Y');
}

void Ins(HD *&L){
	HD *P,*Q;
	P=new HD; //cap phat bo nho con tro p
	cout << "Thong tin KH :\n";
		cout << "Nhap ma KH: ";
		cin >> P->makh;
		cout << "Nhap ma HD: ";
		cin >> P->mahd;
		cout << "Nhap Ho ten: ";
		cin >> P->ht;
		cout << "Nhap so KW: ";
		cin >> P->sokw;
	Q=L;
	while(Q->next!=NULL){
		Q = Q->next;
	}
		P->next=Q->next;
		Q->next=P;
}

void Del(HD *&L) {
    HD *P, *Q;  // Khai báo hai con tr? d?n các c?u trúc nút
    char makh[10];  // Khai báo m?t m?ng ký t? d? luu giá tr? makh c?n xóa
    cout << "Nhap ma KH can xoa: ";  // Nh?c ngu?i dùng nh?p giá tr? makh c?n xóa
    cin >> makh;  // Ð?c giá tr? makh
    if (L == NULL) {  // N?u danh sách r?ng, không có gì d? xóa
        return;
    }
    if (strcmp(L->makh, makh) == 0) {  // N?u nút d?u tiên kh?p v?i giá tr? makh c?n xóa
        Q = L;  // Luu con tr? d?n nút d?u tiên
        L = L->next;  // C?p nh?t d?u danh sách liên k?t d? tr? d?n nút th? hai
        delete Q;  // Xóa nút d?u tiên
        return;
    }
    P = L;  // B?t d?u t? d?u danh sách
    while (P->next != NULL) {  // Duy?t danh sách cho d?n cu?i
        if (strcmp(P->next->makh, makh) == 0) {  // N?u nút k? ti?p kh?p v?i giá tr? makh c?n xóa
            Q = P->next;  // Luu con tr? d?n nút c?n xóa
            P->next = Q->next;  // C?p nh?t nút tru?c d? tr? d?n nút ti?p theo
            delete Q;  // Xóa nút
            return;
        }
        P = P->next;  // Di chuy?n d?n nút k? ti?p
    }
}

//void DelKH(HD *&L){
//	HD *P;
//	HD *Q=L;
//	int maKH;
//	cout << "Nhap ma kh: ";
//	cin >> maKH;
//	while(Q!= NULL){
//		if(Q->makh == maKH){
//			if(P=NULL){
//				L=Q->next;
//			}else{
//				P->next = Q->next;
//			}
//			delete(Q);
//			cout <<"xoa thanh cong";
//			return;
//		}
//		P=Q;
//		Q=Q->next;
//}
//	
//		
//	
//}
int main(){
	L= NULL;
	Inp(L);
	Out(L);
	Inp(L);
	Out(L);
	delete(L);
	return 0;
}
