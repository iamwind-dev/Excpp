#include <iostream>
using namespace std;
int gcd(int x,int y);

int main (){
	int num1,num2,GCD,LCM;
	cout << "Enter two integer values:\n";
	cin >> num1;
	cin >> num2;
	GCD = gcd(num1,num2);
	cout << "GCD: " << GCD;
	cout << "\nLCM: " << (num1 * num2) / GCD;
	return 0;
}

int gcd(int x,int y){
	if(y==0) 
	{
	return x;
	}
	else 
	{
	return gcd(y , x % y);  //call itselt
	} 
}

