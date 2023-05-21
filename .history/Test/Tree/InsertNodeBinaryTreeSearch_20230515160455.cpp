#include <bits/stdc++.h>
#include <conio.h>
#include <stdio.h>
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
    }
}