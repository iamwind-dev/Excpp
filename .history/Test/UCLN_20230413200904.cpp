#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        for (int i = 1; i <= b; i++)
        {
            if ((a % i == 0) && (b % i == 0))
                cout << i;
        }
    }
    else if (a < b)
    {
        for (int i = 1; i <= b; i++)
        {
            if ((a % i == 0) && (b % i == 0))
                cout << i;
        }
    }
    else
        (a = b) cout << a;
    return 0;
}