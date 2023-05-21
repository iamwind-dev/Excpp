#include <iostream>
using namespace std;

bool checkEvenDigits(int n)
{
    while (n > 0)
    {
        int digit = n % 10;
        if (digit % 2 != 0)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    if (checkEvenDigits(n))
    {
        cout << n << " co cac chu so deu la so chan." << endl;
    }
    else
    {
        cout << n << " khong co cac chu so deu la so chan." << endl;
    }
    return 0;
}
