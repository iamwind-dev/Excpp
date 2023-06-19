#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;
const int MAX_PRODUCTS = 100;

struct Product
{
    int code;
    string name;
    float price;
};

void insert(Product products[], int size, int code, const string &name, float price)
{
    int index = code % size;
    int i = 1;

    while (products[index].code != -1)
    {
        index = (index + i) % size;
        i++;
    }

    products[index].code = code;
    products[index].name = name;
    products[index].price = price;

    cout << "Product inserted successfully." << endl;
}

void printList(const Product products[], int size)
{
    bool isEmpty = true;

    cout << setw(10) << "Code"
         << setw(20) << "Name"
         << setw(10) << "Price" << endl;

    for (int i = 0; i < size; i++)
    {
        if (products[i].code != -1)
        {
            cout << setw(10) << products[i].code
                 << setw(20) << products[i].name
                 << setw(10) << products[i].price << endl;
            isEmpty = false;
        }
    }

    if (isEmpty)
    {
        cout << "Product list is empty." << endl;
    }
}

void search(const Product products[], int size, int code)
{
    int index = code % size;
    int i = 1;

    while (products[index].code != -1 && products[index].code != code)
    {
        index = (index + i) % size;
        i++;
    }

    if (products[index].code == code)
    {
        cout << "Product found:" << endl;
        cout << "Code: " << products[index].code << endl;
        cout << "Name: " << products[index].name << endl;
        cout << "Price: " << products[index].price << endl;
    }
    else
    {
        cout << "Product with code " << code << " not found." << endl;
    }
}

void remove(Product products[], int size, int code)
{
    int index = code % size;
    int i = 1;

    while (products[index].code != -1 && products[index].code != code)
    {
        index = (index + i) % size;
        i++;
    }

    if (products[index].code == code)
    {
        products[index].code = -1;
        products[index].name = "";
        products[index].price = 0.0;
        cout << "Product removed successfully." << endl;
    }
    else
    {
        cout << "Product with code " << code << " not found." << endl;
    }
}

int main()
{
    Product products[MAX_PRODUCTS];
    int size = MAX_PRODUCTS;

    for (int i = 0; i < size; i++)
    {
        products[i].code = -1; // Set default code as -1 to indicate empty slot
    }

    char choice;
    int code;
    string name;
    float price;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Print the product list" << endl;
        cout << "3. Search for a product" << endl;
        cout << "4. Remove a product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter the product code: ";
            cin >> code;
            cout << "Enter the product name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Enter the product price: ";
            cin >> price;
            insert(products, size, code, name, price);
            break;
        case '2':
            printList(products, size);
            break;
        case '3':
            cout << "Enter the product code to search: ";
            cin >> code;
            search(products, size, code);
            break;
        case '4':
            cout << "Enter the product code to remove: ";
            cin >> code;
            remove(products, size, code);
            break;
        case '5':
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
    system("pause");
    return 0;
}
