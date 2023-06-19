#include <iostream>
using namespace std;
// 
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// 
void insertElement(int arr[], int &n, int key)
{
    n++;
    int i = n - 1;
    arr[i] = key;

    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 
void deleteElement(int arr[], int &n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            break;
        }
    }

    if (i == n)
    {
        std::cout << "Element not found in the heap.\n";
        return;
    }

    swap(arr[i], arr[n - 1]);
    n--;
    heapify(arr, n, i);
}

// 
void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to display the elements of the heap
void displayHeap(int arr[], int n)
{
    std::cout << "Heap: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {45, 36, 54, 27, 63, 72, 61, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);
    displayHeap(arr, n);

    // Insert a new element
    int newElement = 50;
    insertElement(arr, n, newElement);
    displayHeap(arr, n);

    // Delete an element
    int elementToDelete = 27;
    deleteElement(arr, n, elementToDelete);
    displayHeap(arr, n);

    // Sort the numbers in descending order
    heapSort(arr, n);
    cout << "Sorted numbers in descending order: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
