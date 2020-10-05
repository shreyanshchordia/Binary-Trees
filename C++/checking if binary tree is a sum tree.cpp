#include<bits/stdc++.h>
using namespace std;
//sum of all child nodes is equal to parent node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newnode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
int add(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return add(root->left)+root->data+add(root->right);
}
int checksumtree(struct Node* root)
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    int l = add(root->left);
    int r = add(root->right);
    int t = l+r;
    if(root->data==t)
    {
        if(checksumtree(root->left)&&checksumtree(root->right))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    struct Node* root = NULL;
    root = newnode(56);
    root->left = newnode(13);
    root->left->left = newnode(5);
    root->left->right = newnode(3);
    root->left->left->left = newnode(3);
    root->left->left->right = newnode(2);
    root->right = newnode(15);
    root->right->left = newnode(9);
    root->right->right = newnode(3);
    root->right->right->left = newnode(2);
    root->right->right->right = newnode(1);
    int t = checksumtree(root);
    if(t==1)
    {
        cout<<"This Binary tree is a sum tree";
    }
    else
    {
        cout<<"This Binary tree is not a sum tree";
    }
    return 0;
}
