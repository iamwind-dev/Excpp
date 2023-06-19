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
// a
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

void NLR(tree root)
{
    if (root != NULL)
    {
        cout << root->element << " ";
        LNR(root->left);
        LNR(root->right);
    }
}

void LRN(tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        LNR(root->right);
        cout << root->element << " ";
    }
}

int findMax(tree root)
{
    if (root == NULL)
    {
        cout << "Cây rỗng." << endl;
        return -1;
    }

    // Đi đến nút phải nhất trong cây
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->element;
}

int findMin(tree root)
{
    if (root == NULL)
    {
        cout << "Cay rong." << endl;
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->element;
}

int main()
{
    tree root;
    int a;
    int x;
    khoi_tao_cay(root);
    nhap_cay(root);

    cout << "Preorder traversal of the tree is: ";
    NLR(root);
    cout << "Inorder traversal of the tree is: ";
    LNR(root);
    cout << "Postorder traversal of the tree is: ";
    LRN(root);
    cout << endl;
    cout << "Nhap so can tim: ";
    cin >> a;

    if (tim(a, root))
        cout << "\ntim thay ";
    else
        cout << "\nkhong tim thay";
    cout << endl;
    cout << "Nhap so can xoa: ";
    cin >> x;
    xoa(x, root);
    cout << endl;
    cout << "Max: " << findMax(root) << endl;
    cout << "Min " << findMin(root) << endl;
    LNR(root);
    system("pause");
    return 0;
}
