#include <iostream>

using namespace std;

struct Node
{
    char value;
    Node *left;
    Node *right;
};

struct Stack
{
    int top;
    int capacity;
    Node **array;
};
//============================================================================

//============================================================================
Stack *createStack(int capacity)
{
    Stack *stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new Node *[capacity];
    return stack;
}

bool isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, Node *item)
{
    if (isFull(stack))
    {
        cout << "Stack overflow\n";
        return;
    }
    stack->array[++stack->top] = item;
}

Node *pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack underflow\n";
        return nullptr;
    }
    return stack->array[stack->top--];
}

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
    int length = postfix.length();
    Stack *stack = createStack(length);

    for (int i = 0; i < length; i++)
    {
        char c = postfix[i];

        if (!isOperator(c))
        {
            Node *operand = createNode(c);
            push(stack, operand);
        }
        else
        {
            Node *operatorNode = createNode(c);
            operatorNode->right = pop(stack);
            operatorNode->left = pop(stack);
            push(stack, operatorNode);
        }
    }

    return pop(stack);
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
void preorderTraversal(Node *root)
{
    if (root)
    {
        cout << root->value;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value;
    }
}

bool isOperand(char c)
{
    return isalpha(c) || isdigit(c);
}

int getPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string &infix)
{
    string postfix;
    char operatorStack[100];
    int top = -1;

    for (char c : infix)
    {
        if (isOperand(c))
        {
            postfix += c;
        }
        else if (isOperator(c))
        {
            while (top != -1 && operatorStack[top] != '(' &&
                   getPrecedence(c) <= getPrecedence(operatorStack[top]))
            {
                postfix += operatorStack[top];
                top--;
            }
            top++;
            operatorStack[top] = c;
        }
        else if (c == '(')
        {
            top++;
            operatorStack[top] = c;
        }
        else if (c == ')')
        {
            while (top != -1 && operatorStack[top] != '(')
            {
                postfix += operatorStack[top];
                top--;
            }
            top--; // Pop '('
        }
    }

    while (top != -1)
    {
        postfix += operatorStack[top];
        top--;
    }

    return postfix;
}

int main()
{
    string postfix = "85-42+3/*";
    Node *root = constructExpressionTree(postfix);

    cout << "Inorder traversal of the expression tree: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Preorder traversal of the expression tree: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Posorder traversal of the expression tree: ";
    postorderTraversal(root);
    system("pause");
    return 0;
}
