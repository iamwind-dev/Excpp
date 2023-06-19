#include <iostream>
#include <fstream>
#define SIZE 17

using namespace std;

int hashFunction(const string &key, int capacity)
{
    int sum = 0;
    for (char c : key)
    {
        sum += c;
    }
    return sum % capacity;
}

void insert(string table[], int capacity, const string &key)
{
    int index = hashFunction(key, capacity);

    int i = 0;
    while (!table[index].empty())
    {
        index = (index + i) % capacity;
        i++;
    }

    table[index] = key;
}

void display(string table[], int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        if (!table[i].empty())
        {
            cout << "[" << i << "]: " << table[i] << endl;
        }
    }
}

void saveToFile(string table[], int capacity, const string &filename)
{
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        for (int i = 0; i < capacity; i++)
        {
            if (!table[i].empty())
            {
                outputFile << "[" << i << "]: " << table[i] << endl;
            }
        }
        outputFile.close();
        cout << "Data saved to file: " << filename << endl;
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main()
{
    string hashtable[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = "";
    }

    string key;
    char choice;
    do
    {
        cout << "Enter student name to insert: ";
        cin >> key;

        insert(hashtable, SIZE, key);

        cout << "Do you want to insert another student? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    display(hashtable, SIZE);
    system("pause");
    return 0;
}
