#include <iostream>
using namespace std;
const int ARRAY_SIZE = 100;
const int MAX_VALUE = 100;
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

// hàm sắp xếp nổi bọt (bubble sort)

void BubbleSort(int array[], int n)
{
    int i, j;
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

void SelectionSort(int array[], int n)
{
    {
        int i, j, minIndex, tmp;
        for (i = 0; i < n - 1; i++)
        {
            minIndex = i;
            for (j = i + 1; j < n; j++)
            {
                if (array[j] < array[minIndex])
                {
                    minIndex = j;
                }
            }
            tmp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = tmp;
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

int COMPARE(int a, int b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int binSearch(int array[], int SearchNum, int n)
{
    int left = 0, right = n - 1, middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        switch (COMPARE(array[middle], SearchNum))
        {
        case -1:
            left = middle + 1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle - 1;
        }
    }
    return -1;
}

int main()
{
    int array[ARRAY_SIZE];
    int n;
    srand(time(NULL)); // khoi tao trinh tao so ngau nhien
    fillarray(array, ARRAY_SIZE);
    cout << "Array: " << endl;
    printarray(array, ARRAY_SIZE);
    BubbleSort(array, ARRAY_SIZE);
    cout << "Sap xep noi bot: " << endl;
    printarray(array, ARRAY_SIZE);
    cout << "Linear Search: " << endl;
    cin >> n;
    cout << linearsearch(array, n, ARRAY_SIZE) << endl; // tim  kiem tuyen tinh
    cout << "Binary Search: " << endl;
    cin >> n;
    cout << binSearch(array, n, ARRAY_SIZE) << endl; // tim kiem tuyen;
    fillarray(array, ARRAY_SIZE);
    cout << "Array: " << endl;
    printarray(array, ARRAY_SIZE);
    SelectionSort(array, ARRAY_SIZE);
    cout << "Sap xep chon: " << endl;
    printarray(array, ARRAY_SIZE);
    system("pause");
    return 0;
}