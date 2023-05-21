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

void LNR(tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->element << " ";
        LNR(root->right);
    }
}

int main()
{
    tree root;
    khoi_tao_cay(root);
    chen(15, root);
    chen(20, root);
    chen(8, root);
    chen(40, root);
    chen(12, root);
    chen(90, root);

    cout << "\nPreorder traversal of the tree is: ";
    LNR(root);
    cout << endl;
    if (tim(90, root))
        cout << "tim thay ";
    else
        cout << "khong tim thay";
    cout << endl;
    xoa(20, root);
    LNR(root);
    system("pause");
    return 0;
}
