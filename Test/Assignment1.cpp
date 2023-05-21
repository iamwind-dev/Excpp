#include <iostream>
using namespace std;
void nhapMang(double* A, int n) {
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
}
double TBC1(double* A,int n){
	double sum=0;
	for (int i = 0; i < n; i++) {
			sum += A[i];  
	}
	double avg = sum/n;
	return avg; 
}
void TBC2(double* A, int n) {
	double sum1 = 0;
	double sum2 = 0;
	double count = 0;
	double count2 = 0;
	for(int i = 0; i < n; i++){
		if(A[i] > 0.01){
			sum1+=A[i];
			count++;
		} else if (A[i] < 0.01){
			sum2+=A[i];
			count2++;
		}
	}
	cout << "average 1 = " << sum1/count << endl;
	cout << "average 2 = " << sum2/count2 ;
	
}
int main(){
	int n;
	double A[1000];
	do{
		cout << "Nhap n = ";
		cin >> n;
		if(n>1000) cout << "Vui long nhap lai!\n";
	} while(n>1000);
	nhapMang(A,n);
	//a
	cout << "\nTBC: " << TBC1(A,n) << endl;
	//b
	TBC2(A,n);
	return 0;
}
