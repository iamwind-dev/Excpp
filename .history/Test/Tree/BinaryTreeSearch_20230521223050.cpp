#include <iostream>
using namespace std;

typedef int element_type;
typedef struct node
{
    element_type element;
    struct node *left, *right;
} NODE;

typedef NODE *tree;

void khoi_tao_cay(tree &root)
{
    root = NULL;
}

void chen(int e, tree &root)
{
    if (root == NULL)
    {
        root = new NODE;
        root->element = e;
        root->left = NULL;
        root->right = NULL;
    }
    else if (e < root->element)
    {
        chen(e, root->left);
    }
    else if (e > root->element)
    {
        chen(e, root->right);
    }
    else
    {
        cout << "Element already exists in the tree.";
    }
}

void nhap_cay(tree &root)
{
    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e;
        cout << "Enter element " << i + 1 << " : ";
        cin >> e;
        chen(e, root);
    }
}

NODE *tim(int x, tree root)
{
    while (root != NULL)
    {
        if (x < root->element)
            root = root->left;
        else if (x > root->element)
            root = root->right;
        else
            return root; // Found
    }
    return NULL; // Not found
}

int xoacuctrai(tree &root)
{
    int k;
    if (root->left == NULL)
    {
        k = root->element;
        root = root->right;
        return k;
    }
    else
    {
        return xoacuctrai(root->left);
    }
}

void xoa(int x, tree &root)
{
    if (root != NULL)
    {
        if (x < root->element)
            xoa(x, root->left);
        else if (x > root->element)
            xoa(x, root->right);
        else if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        else
            root->element = xoacuctrai(root->right);
    }
}

void NLR(tree root)
{
    if (root != NULL)
    {
        cout << root->element << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

int main()
{
    tree root;
    khoi_tao_cay(root);
    nhap_cay(root);

    cout << "\nPreorder traversal of the tree is: ";
    NLR(root);

    int x;
    cout << "\n\nEnter element to search: ";
    cin >> x;
    if (tim(x, root) != NULL)
        cout << "Element found in tree.\n";
    else
        cout << "Element not found in tree.\n";

    cout << "Enter element to delete: ";
    cin >> x;
    xoa(x, root);
    cout << "\nPreorder traversal of the tree after deletion: ";
    NLR(root);

    return 0;
}
