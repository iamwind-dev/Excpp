#include <iostream>
using namespace std;
const int ARRAY_SIZE = 10;
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
// sap xep chen
void InsertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp nhanh (Quick Sort)
void QuickSort(int array[], int low, int high)
{
    if (low >= high)
        return;

    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);

    QuickSort(array, low, i);
    QuickSort(array, i + 2, high);
}
// tim kiem tuyen tinh
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
// Tim kiem nhi phan
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
    cout << "Mang: " << endl;
    printarray(array, ARRAY_SIZE);
    BubbleSort(array, ARRAY_SIZE);
    cout << "Sap xep noi bot: " << endl;
    printarray(array, ARRAY_SIZE);
    cout << "Tim kiem tuyen tinh: " << endl;
    cin >> n;
    cout << linearsearch(array, n, ARRAY_SIZE) << endl; // tim  kiem tuyen tinh
    cout << "Tim kiem nhi phan: " << endl;
    cin >> n;
    cout << binSearch(array, n, ARRAY_SIZE) << endl; // tim kiem tuyen;
    fillarray(array, ARRAY_SIZE);
    cout << "Mang: " << endl;
    printarray(array, ARRAY_SIZE);
    SelectionSort(array, ARRAY_SIZE);
    cout << "Sap xep chon: " << endl;
    printarray(array, ARRAY_SIZE);
    cout << endl;
    fillarray(array, ARRAY_SIZE);
    cout << "Array: " << endl;
    printarray(array, ARRAY_SIZE);
    SelectionSort(array, ARRAY_SIZE);
    cout << "Sap xep chen: " << endl;
    printarray(array, ARRAY_SIZE);
    cout << endl;
    fillarray(array, ARRAY_SIZE);
    cout << "Mang: " << endl;
    printarray(array, ARRAY_SIZE);
    QuickSort(array, 0, ARRAY_SIZE - 1);
    cout << "Sap xep nhanh: " << endl;
    printarray(array, ARRAY_SIZE);
    system("pause");
    return 0;
}