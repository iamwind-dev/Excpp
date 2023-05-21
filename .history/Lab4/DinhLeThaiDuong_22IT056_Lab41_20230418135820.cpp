#include <iostream>
using namespace std;
const int ARRAY_SIZE = 1000;
const int MAX_VALUE = 10000;
const int MIN_VALUE = 1;

int randominit(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void fillarray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = randominit(MIN_VALUE, MAX_VALUE);
    }
}

void printarray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void SortArray(int array[], int n)
{
    int i, j, min;
    int tmp;
    for (i = 0; i <= n - 2; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int linearsearch(int array[], int SearchNum, int n)
{
    array[n] = SearchNum;
    int i = 0;
    while (array[i] != SearchNum)
        i++;
    return (i < n) ? i : -1;
}

int main()
{
    int array[ARRAY_SIZE];
    int n;
    srand(time(NULL)); // khoi tao trinh tao so ngau nhien
    fillarray(array, ARRAY_SIZE);
    cout << "Array: " << endl;
    printarray(array, ARRAY_SIZE);
    SortArray(array, ARRAY_SIZE);
    cout << "Sort Array: " << endl;
    printarray(array, ARRAY_SIZE);
    cout << "Search: " << endl;
    cin >> n;
    cout << linearsearch(array, n, ARRAY_SIZE);
    system("pause");
    return 0;
}