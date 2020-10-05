#include <bits/stdc++.h>
using namespace std;

//Author : Swoyam S Sahoo
// Density of a binay tree means the ratio of size of binary tree to height of binary tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newnode(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
float heightofb(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(heightofb(root->left), heightofb(root->right)) + 1;//  1 is added to represent the root node
}
float sizeofb(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = sizeofb(root->left);
    int right = sizeofb(root->right);
    return left + right + 1; // ti gives the overall size of binary tree
}
int main()
{
    struct Node *root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    float height = heightofb(root);
    float size = sizeofb(root);
    float density = size / height;
    cout << density;
    return 0;
}
