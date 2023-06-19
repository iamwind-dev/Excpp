#include <iostream>

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

    std::cout << "Number " << key << " added to the hash table." << std::endl;
}

void printTable(Node *const table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        std::cout << "[" << i << "]: ";

        Node *current = table[i];
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
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
            std::cout << "Number " << key << " removed from the hash table." << std::endl;
            return;
        }

        previous = current;
        current = current->next;
    }

    std::cout << "Number " << key << " not found in the hash table." << std::endl;
}

int main()
{
    Node *table[TABLE_SIZE] = {nullptr};

    int n;
    std::cout << "Enter the number of integers to store: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        insert(table, num);
    }

    std::cout << "Hash Table:" << std::endl;
    printTable(table);

    int searchNum;
    std::cout << "Enter a number to search: ";
    std::cin >> searchNum;
    if (search(table, searchNum))
    {
        std::cout << "Number " << searchNum << " found in the hash table." << std::endl;
    }
    else
    {
        std::cout << "Number " << searchNum << " not found in the hash table." << std::endl;
    }

    int removeNum;
    std::cout << "Enter a number to remove: ";
    std::cin >> removeNum;
    remove(table, removeNum);

    std::cout << "Updated Hash Table:" << std::endl;
    printTable(table);
    sys
    return 0;
}
