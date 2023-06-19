#include <iostream>
#include <string>

using namespace std;
const int MAX_SIZE = 100;
struct ST
{
    Node value;
    int data;
    ST *next;
};
ST *top;
void push(int value)
{
    ST *newNode = new ST();
    if (!newNode)
    {
        cout << "Heap overflow" << endl;
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
bool isEmpty()
{
    return top == nullptr;
}

int topp()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        cout << "Stack is empty" << endl;
        exit(1);
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    else
    {
        ST *temp = top;
        top = top->next;
        temp->next = nullptr;
        delete temp;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        ST *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
//================================================================
struct Node
{
    char value;
    Node *left;
    Node *right;
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Node *createNode(char value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *constructExpressionTree(const string &postfix)
{

    for (char c : postfix)
    {
        if (!isOperator(c))
        {
            Node *operand = createNode(c);
            push(operand);
        }
        else
        {
            Node *operatorNode = createNode(c);
            operatorNode->right = topp();
            pop();
            operatorNode->left = topp();
            pop();
            push(operatorNode);
        }
    }
    return topp();
}

void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    string postfix = "85-42+3/*";
    Node *root = constructExpressionTree(postfix);

    cout << "Inorder traversal of the expression tree: ";
    inorderTraversal(root);

    return 0;
}
