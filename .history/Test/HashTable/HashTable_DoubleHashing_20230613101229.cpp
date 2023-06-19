#include <iostream>
#include <fstream>
#include <string>
#define SIZE 10

using namespace std;

int hashFunction1(const string &key, int capacity)
{
    int sum = 0;
    for (char ch : key)
    {
        sum += static_cast<int>(ch);
    }
    return sum % capacity;
}

int hashFunction2(const string &key, int capacity)
{
    int sum = 0;
    for (char ch : key)
    {
        sum += static_cast<int>(ch);
    }
    return (sum % (capacity - 2)) + 1;
}

void insert(string table[], int capacity, const string &key)
{
    int index = hashFunction1(key, capacity);
    int step = hashFunction2(key, capacity);

    int i = 0;
    while (!table[index].empty())
    {
        index = (index + i * step) % capacity;
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

    string inputFilename;
    

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
        cout << "Unable to open input file: " << inputFilename << endl;
        return 1;
    }

    display(hashtable, SIZE);

    string outputFilename="output.txt";
    

    saveToFile(hashtable, SIZE, outputFilename);

    return 0;
}
