#include <iostream>
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
    int index = hashFunction1(key, capacity); // Vị trí ban đầu dựa trên hàm băm 1
    int step = hashFunction2(key, capacity);  // Bước nhảy dựa trên hàm băm 2

    int i = 0;
    while (table[index] != -1)
    {
        index = (index + i * step) % capacity; // Áp dụng double hashing
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
    int hashtable[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1; // Khởi tạo tất cả các ô băm là -1 (để biểu thị ô trống)
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
    system("pause") return 0;
}
