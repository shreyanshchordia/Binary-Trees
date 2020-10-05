#include<bits/stdc++.h>
using namespace std;
//A TREE is called sum tree if sum of all the child nodes is equal to the parent node
//(here child nodes includes directly connected child nodes and and granchild child nodes and all further nodes when we go down the tree)
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
    if(root==NULL)// if root is null then the tree is considered sum tree
    {
        return 1;
    }
    if(root->left==NULL&&root->right==NULL)//leaf nodes are excluded here
    {
        return 1;
    }
    int l = add(root->left);//here all the left child nodes are added
    int r = add(root->right);//here all the right child nodes are added
    int t = l+r;
    if(root->data==t)//here the sum of all left and right child nodes is compared with the parent node
    {
        if(checksumtree(root->left)&&checksumtree(root->right))//if the previous codition satisfies we go for individually checking the chils nodes for sum tree
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
