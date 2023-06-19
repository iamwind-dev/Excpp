#include <iostream>
#include <fstream>
#define SIZE 10

using namespace std;

int hashFunction1(int key, int capacity)
{
    return key % capacity;
}

int hashFunction2(int key, int capacity)
{
    return (key % (capacity - 2)) + 1;
}

void insert(int table[], int capacity, int key)
{
    int index = hashFunction1(key, capacity);
    int step = hashFunction2(key, capacity);

    int i = 0;
    while (table[index] != -1)
    {
        index = (index + i * step) % capacity;
        i++;
    }

    table[index] = key;
}

void display(int table[], int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        if (table[i] != -1)
        {
            cout << "[" << i << "]: " << table[i] << endl;
        }
    }
}

void saveToFile(int table[], int capacity, const string &filename)
{
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] != -1)
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
    int hashtable[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1;
    }

    string inputFilename="input.txt";
    

    ifstream inputFile(inputFilename);
    if (inputFile.is_open())
    {
        int key;
        while (inputFile >> key)
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
    system("pause");
    return 0;
}
