#include <iostream>
#include <algorithm>
#include <string>
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
    for (int i = 0; i < n; i++)
    {
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
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].id, id) == 0)
            return i;
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
    sort(arr, arr + n, compareAvg);
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
