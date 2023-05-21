#include <bits/stdc++.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
typedef int element_type;
typedef struct node
{
    element_type element;
    struct node *left, *right;
} NODE;

typedef NODE *tree;
NODE *root;

void khoi_tao_cay(NODE **root)
{
    *root = NULL;
}

void chen(int e, NODE **root)
{
    NODE *tam;
    tam = new NODE;
    tam->element = e;
    tam->left = NULL;
    tam->right = NULL;
    if (*root == NULL)
        *root = tam;
    else if (tam->element < (*root)->element)
        if ((*root)->left)
            chen(e, &(*root)->left);
        else
            (*root)->left = tam;
    else if (tam->element > (*root)->element)
        if ((*root)->right)
            chen(e, &(*root)->right);
        else
            (*root)->right = tam;
    else
        cout << "trung";
}

void nhap_cay(NODE **root)
{
    element_type e;
    do
    {
        cout << "\nNhap element (-1 de ket thuc) : ";
        cin >> e;
        if (e != -1)
            chen(e, root);
    } while (e != -1);
    int timedequy(int x, NODE *root)
    {
        int timthay = 0;
    }
}