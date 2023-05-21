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
    // else if (a < b)
    // {
    //     for (int i = 1; i <= a; i++)
    //     {
    //         if ((a % i == 0) && (b % i == 0))
    //             cout << i;
    //     }
    // }
    // else
    //     cout << a;
    system("pause");
    return 0;
}