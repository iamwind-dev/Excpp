#include <iostream>
#define SIZE 17

using namespace std;

int hashFunction(int key, int capacity)
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

int main()
{
    int a ;
    int hashtable[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1; 
    }
    for (int i = 0; i < SIZE; i++){}
    // Chèn các giá trị vào bảng băm
    
    insert(hashtable, SIZE, 21);
    

    // Hiển thị bảng băm
    display(hashtable, SIZE);
    system("pause");
    return 0;
}
