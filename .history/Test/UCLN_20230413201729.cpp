#include <iostream>
using namespace std;
int main()
{
    int a, b;
    int count = 0;
    cin >> a >> b;
    if (a > b)
    {
        for (int i = 1; i <= a; i++)
        {
            if ((a % i == 0) && (b % i == 0))
                if (i > count)
                    count = i;
        }
    }
    else if (a < b)
    {
        for (int i = 1; i <= a; i++)
        {
            if ((a % i == 0) && (b % i == 0))
                if (i > count)
                    count = i;
        }
    }
    else
        cout << a;
    cout << count;
    system("pause");
    return 0;
}