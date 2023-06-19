#include <iostream>
#define SIZE 17

using namespace std;

int hashFunction(string &key, int capacity)
{
    return key % capacity;
}

void insert(int table[], int capacity, int key)
{
    int index = hashFunction(key, capacity); // Vị trí ban đầu dựa trên hàm băm

    // Xử lý xung đột theo linear probing
    int i = 0;
    while (table[index] != -1)
    {
        index = (index + i) % capacity; // Áp dụng hàm băm với linear probing
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
    int hashtable[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1; 
    }
    
    // Chèn các giá trị vào bảng băm
    int key;
    char choice;
    do
    {
        cout << "Enter key to insert: ";
        cin >> key;

        insert(hashtable, SIZE, key);

        cout << "Do you want to insert another key? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // Hiển thị bảng băm
    display(hashtable, SIZE);
    system("pause");
    return 0;
}
