#include <iostream>
#define SIZE 10

using namespace std;


    int *table;
    int capacity;


    HashTable(int size)
    {
        capacity = size;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = -1; // Khởi tạo tất cả các ô băm là -1 (để biểu thị ô trống)
        }
    }

    int hashFunction(int key)
    {
        return key % capacity;
    }

    void insert(int key)
    {
        int index = hashFunction(key); // Vị trí ban đầu dựa trên hàm băm

        // Xử lý xung đột theo linear probing
        int i = 0;
        while (table[index] != -1)
        {
            index = (index + i) % capacity; // Áp dụng hàm băm với linear probing
            i++;
        }

        table[index] = key;
    }

    void display()
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
    HashTable hashtable(SIZE);

    // Chèn các giá trị vào bảng băm
    hashtable.insert(21);
    hashtable.insert(11);
    hashtable.insert(7);
    hashtable.insert(30);

    // Hiển thị bảng băm
    hashtable.display();

    return 0;
}
