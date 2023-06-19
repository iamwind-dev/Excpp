#include <iostream>
using namespace std;
const int TABLE_SIZE = 9;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node *table[], int key)
{
    int index = key % TABLE_SIZE;
    Node *newNode = createNode(key);

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        Node *current = table[index];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    cout << "Number " << key << " added to the hash table." << std::endl;
}

void printTable(Node *const table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "[" << i << "]: ";

        Node *current = table[i];
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
}

bool search(const Node *const table[], int key)
{
    int index = key % TABLE_SIZE;
    const Node *current = table[index];

    while (current != nullptr)
    {
        if (current->data == key)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

void remove(Node *table[], int key)
{
    int index = key % TABLE_SIZE;
    Node *current = table[index];
    Node *previous = nullptr;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            if (previous == nullptr)
            {
                table[index] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            cout << "Number " << key << " removed from the hash table." << endl;
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "Number " << key << " not found in the hash table." << endl;
}

int main()
{
    Node *table[TABLE_SIZE] = {nullptr};

    int n;
    cout << "Nhap so luong so can nhap: ";
    cin >> n;

    cout << "Nhap " << n << " so:" << endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        insert(table, num);
    }

    cout << "ban bam:" << endl;
    printTable(table);

    int searchNum;
    cout << "Nhap so can tim: ";
    cin >> searchNum;
    if (search(table, searchNum))
    {
        cout << "So " << searchNum << " da dc tim thay" << endl;
    }
    else
    {
        cout << "So " << searchNum << " khong dc tim thay" << endl;
    }

    int removeNum;
    cout << "Nhap so can xoa: ";
    cin >> removeNum;
    remove(table, removeNum);

    cout << "Cap nhat ban bam:" << endl;
    printTable(table);
    system("pause");
    return 0;
}
