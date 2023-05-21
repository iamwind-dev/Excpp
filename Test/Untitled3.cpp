#include <iostream>
using namespace std;
int giaiThua(int n)
{
    int giai_thua = 1;
    for (int i = 1; i <= n; i++)
        giai_thua *= i;
    return giai_thua;
}
int main()
{
    int n;
    cin >> n;
    cout << "Giai thua " << n << " la: " << giaiThua(n);
    return 0;
}
