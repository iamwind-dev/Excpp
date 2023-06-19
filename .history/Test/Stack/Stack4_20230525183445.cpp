#include <iostream>
#include <string>
using namespace std;
struct Node
{
    char data;
    Node *next;
};

Node *top;

void push(char value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop()
{

    Node *temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;

    return poppedValue;
}

string reverseString(const string &inputString)
{

    for (char c : inputString)
    {
        push(c);
    }
    string reversedString;
    reversedString += pop();

    return reverseString;
}

int main()
{
    string input;
    cout << "Nhap chuoi: ";
    getline(cin, input);

    string reversed = reverseString(input);
    cout << "Chuoi dao nguoc: " << reversed << endl;

    return 0;
}