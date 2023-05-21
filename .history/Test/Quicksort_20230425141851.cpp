#include <bits/stdc++.h>
using namespace std;
const int ARRAY_SIZE = 10;
const int MAX_VALUE = 10;
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

void quickSort(int list[], int left, int right)
{
    int pivot, i, j;
    int temp;
    if (left < right)
    { /* divide */
        i = left;
        j = right;
        pivot = list[(left + right) / 2];
        do
        {
            do
                i++;
            while (list[i] < pivot);
            do
                j--;
            while (list[j] > pivot);
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        } while (i < j);
        temp = list[left];
        list[left] = list[j];
        list[j] = temp;
        quickSort(list, left, j); /* conquer */
        quickSort(list, j, right);
    }
}

int main()
{
    int array[ARRAY_SIZE];
    int n;
    srand(time(NULL)); // khoi tao trinh tao so ngau nhien
    fillarray(array, ARRAY_SIZE);
    cout << "Array: " << endl;
    printarray(array, ARRAY_SIZE);
    quickSort(array, 0, ARRAY_SIZE - 1);
    cout << "Sort Array: " << endl;
    printarray(array, ARRAY_SIZE);
    system("pause");
    return 0;
}