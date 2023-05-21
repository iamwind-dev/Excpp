#include <bits/stdc++.h>
using namespace std;

struct Student
{
    char id[12];
    char name[30];
    char clas[10];
    float mMath;
    float mPhysical;
};

void inputList(Student arr[], int n)
{
    cout << "Enter information of students:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter student #" << i + 1 << ":\n";
        cout << "ID: ";
        cin >> arr[i].id;
        cout << "Name: ";
        cin >> arr[i].name;
        cout << "Class: ";
        cin >> arr[i].clas;
        cout << "Math score: ";
        cin >> arr[i].mMath;
        cout << "Physical score: ";
        cin >> arr[i].mPhysical;
    }
}

void outputList(Student arr[], int n)
{
    cout << "List of students:" << endl;
    cout << "ID"
         << "\t\t"
         << "Name"
         << "\t\t"
         << "Class"
         << "\t\t"
         << "Math score"
         << "\t\t"
         << "Physical score";
    ;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id
             << "\t\t"
             << arr[i].name
             << "\t\t"
             << arr[i].clas
             << "\t\t"
             << arr[i].mMath
             << "\t\t"
             << arr[i].mPhysical;
        ;
        cout << "ID: " << arr[i].id << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Class: " << arr[i].clas << endl;
        cout << "Math score: " << arr[i].mMath << endl;
        cout << "Physical score: " << arr[i].mPhysical << endl;
        cout << "------------------------" << endl;
    }
}

int searchByID(Student arr[], int n, char id[])
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid].id, id);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

bool compareAvg(Student a, Student b)
{
    float avg_a = (a.mMath + a.mPhysical) / 2;
    float avg_b = (b.mMath + b.mPhysical) / 2;
    return avg_a > avg_b;
}

void sortList(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            float avg_j = (arr[j].mMath + arr[j].mPhysical) / 2;
            float avg_max = (arr[maxIndex].mMath + arr[maxIndex].mPhysical) / 2;
            if (avg_j > avg_max)
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            Student temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student arr[n];
    inputList(arr, n);

    outputList(arr, n);

    char search_id[12];
    cout << "Enter ID to search: ";
    cin >> search_id;
    int result = searchByID(arr, n, search_id);
    if (result == -1)
        cout << "Student not found" << endl;
    else
    {
        cout << "ID: " << arr[result].id << endl;
        cout << "Name: " << arr[result].name << endl;
        cout << "Class: " << arr[result].clas << endl;
        cout << "Math score: " << arr[result].mMath << endl;
        cout << "Physical score: " << arr[result].mPhysical << endl;
    }

    sortList(arr, n);
    outputList(arr, n);

    return 0;
}
