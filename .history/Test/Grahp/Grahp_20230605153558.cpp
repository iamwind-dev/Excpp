#include <iostream>
#include <iomanip>
using namespace std;
//----------------------------------------------------------------Khai báo cấu trúc dữ liệu
int A[20][20];
int n;
int X[20],S[20];
//----------------------------------------------------------------Viết hàm nhập xuất đồ thị
void INP(int M[20][20],int &n){
    for (int d = 1;d<=n;d++){
        for(int c = 1;c<=n;c++){
            cout << "A[" << d << "," << c << "]=";
            cin >> M[d][c];
        }
    }
}
//----------------------------------------------------------------Viết hàm xuất đồ thị
void OUT(int M[20][20],int &n){
    for(int d = 1;d<=n;d++){
        for (int c = 1; c <= n;c++){
            cout << setw(4) << M[d][c];
        }
        cout << endl;
    }
}
//----------------------------------------------------------------Viết hàm đánh dấu
void DD(int X[20],int n){
    for(int i = 1;i<=n;i++){
        X[i] = 1;
    }
}
//----------------------------------------------------------------
void Push(int S[20],int &dinh,int k){
    if(dinh<19){
        dinh++;
        S[dinh] = k;
    }
}
//----------------------------------------------------------------
void Pop(int S[20],int &dinh){
    int k;
    if(dinh>0){
        k=S[dinh];
        dinh--;
    }
    cout << setw(4) << k;
}
//----------------------------------------------------------------
void DS(int M[20][20],int n){
    for(int i=1)
}
//================================================================
int main()
{
    cout << "Số đỉnh= ";
    cin >> n;
    INP(A,n);
    cout << "\nDo thị vừa nhập:\n";
    OUT(A, n);
    system("pause");
    return 0;
}
