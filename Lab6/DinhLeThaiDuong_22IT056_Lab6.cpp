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

int countNodes(tree root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Đệ quy đếm số lượng nút trong cây con bên trái và cây con bên phải
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);

        // Cộng 1 cho nút hiện tại
        return 1 + leftCount + rightCount;
    }
}

int countInternalNodes(tree root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    else
    {
        // Đệ quy đếm số lượng nút nội tại trong cây con bên trái và cây con bên phải
        int leftCount = countInternalNodes(root->left);
        int rightCount = countInternalNodes(root->right);

        // Cộng thêm 1 nếu nút hiện tại không phải là lá
        return 1 + leftCount + rightCount;
    }
}

int calculateHeight(tree root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        // Return the maximum height between the left and right subtrees, plus 1 for the current node
        return std::max(leftHeight, rightHeight) + 1;
    }
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
    cout << endl;
    cout << "Inorder traversal of the tree is: ";
    LNR(root);
    cout << endl;
    cout << "Postorder traversal of the tree is: ";
    LRN(root);
    cout << endl;
    int nodeCount = countNodes(root);
    cout << "So luong nut trong cay nhi phan tim kiem: " << nodeCount << endl;
    int internalNodeCount = countInternalNodes(root);
    cout << "So luong nut noi tai trong cay nhi phan: " << internalNodeCount << endl;
    int treeHeight = calculateHeight(root);
    cout << "Chieu cao cua cay nhi phan: " << treeHeight << endl;

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
    LNR(root);
    cout << "Max: " << findMax(root) << endl;
    cout << "Min: " << findMin(root) << endl;
    system("pause");
    return 0;
}
