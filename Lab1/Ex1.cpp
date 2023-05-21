#include <iostream>
#include <cstdlib> // thu vien nay de su dung ham rand	
using namespace std;

void nhapMang(int* A, int n) {
    for (int i = 0; i < n; i++) {
        *(A + i) = rand() % 100; // nhap gia tri ngau nhien tu 0 den 99
    }
}

void inMang(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(A + i) << " ";
    }
    cout << endl;
}

void xoaSoLe(int* A, int n) {
    int* p = A;
    while (p < A + n) {
        if (*p % 2 != 0) { // neu phan tu la so le
            for (int* q = p; q < A + n - 1; q++) {
                *q = *(q + 1); // dich trai tat ca cac phan tu ben phai cua so le
            }
            n--; // giam kich thuoc mang di 1
        }
        else {
            p++; // neu khong phai sô le thì tiêp tuc kiem tra phan tu tiep theo
        }
    }
}

int main() {
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;
    int A[n];
    nhapMang(A, n);
    cout << "Mang sau khi nhap:\n";
    inMang(A, n);
    xoaSoLe(A, n);
    cout << "Mang sau khi xoa cac so le:\n";
    inMang(A, n);
    return 0;
}
