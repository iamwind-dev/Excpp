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
        cout << "Đã lưu dữ liệu vào file " << filename << endl;
    }
    else
    {
        cout << "Không thể mở file: " << filename << endl;
    }
}

int main()
{
    string hashtable[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = "";
    }

    string inputFilename = "input.txt";

    ifstream inputFile(inputFilename);
    if (inputFile.is_open())
    {
        string key;
        while (getline(inputFile, key))
        {
            insert(hashtable, SIZE, key);
        }
        inputFile.close();
    }
    else
    {
        cout << "Không thể mở file " << inputFilename << endl;
        return 1;
    }

    display(hashtable, SIZE);

    string outputFilename = "output.txt";

    saveToFile(hashtable, SIZE, outputFilename);
    system("pause");
    return 0;
}
