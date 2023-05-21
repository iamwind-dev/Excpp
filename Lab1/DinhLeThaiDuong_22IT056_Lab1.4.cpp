#include <iostream>
#include <cstdlib> 
using namespace std;

void nhapMang(int* A, int n) {
    for (int i = 0; i < n; i++) {
        *(A + i) = rand() % 100; 
    }
}

void inMang(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(A + i) << " ";
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;
    int* A = new int[n];
    nhapMang(A, n);
    cout << "Mang sau khi nhap:\n";
    inMang(A, n);
    delete[] A; 
    return 0;
}
