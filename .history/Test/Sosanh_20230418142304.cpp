#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Function prototypes
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);

int main()
{
    const int N = 10000;
    int arr[N];

    // Generate N random integers between 1 and 10000
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10000);
    for (int i = 0; i < N; i++)
    {
        arr[i] = dist(gen);
    }

    // Measure the execution time of each sorting algorithm
    auto start = high_resolution_clock::now();
    selectionSort(arr, N);
    auto stop = high_resolution_clock::now();
    auto selectionSortTime = duration_cast<milliseconds>(stop - start).count();

    start = high_resolution_clock::now();
    insertionSort(arr, N);
    stop = high_resolution_clock::now();
    auto insertionSortTime = duration_cast<milliseconds>(stop - start).count();

    start = high_resolution_clock::now();
    bubbleSort(arr, N);
    stop = high_resolution_clock::now();
    auto bubbleSortTime = duration_cast<milliseconds>(stop - start).count();

    // Write the results to a file
    ofstream outfile("SortingTime.txt");
    if (outfile)
    {
        outfile << "Selection Sort: " << selectionSortTime << " ms" << endl;
        outfile << "Insertion Sort: " << insertionSortTime << " ms" << endl;
        outfile << "Bubble Sort: " << bubbleSortTime << " ms" << endl;
        outfile.close();
        cout << "Results written to SortingTime.txt." << endl;
    }
    else
    {
        cout << "Error: Unable to open SortingTime.txt." << endl;
    }

    return 0;
}

// Selection Sort algorithm
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
