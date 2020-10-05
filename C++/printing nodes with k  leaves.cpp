#include <bits/stdc++.h>

using namespace std;
//we are given a value k and we need to find and print all the nodes with k leaf nodes
//(leaf nodes are the nodes which no child nodes)
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(int n)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = n;
 temp->left = NULL;
 temp->right = NULL;

 return temp;
}
int leaves(struct Node* root,int k)
{
    if(root==NULL)//if the node is null we will return back to it's parent
    {
        return 0;
    }
    else if(root->left==NULL&&root->right==NULL)//this is the condition for leaf node
    {
        return 1;
    }

    int lc = leaves(root->left,k);//counts the leaf nodes in left child
    int rc = leaves(root->right,k);//count he leaf nodes in right child
    int tc = lc+rc;
    if(tc==k)//compares the total leaf nodes with given k
    {
        cout<<root->data<<" ";
    }
    return tc;
}

int main()
{
    struct Node* root = NULL;
    root = create(1);
    root->left = create(2);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->left->left = create(8);
    root->left->left->right = create(9);
    root->left->left->left->left = create(13);
    root->right = create(3);
    root->right->left = create(6);
    root->right->left->left = create(10);
    root->right->left->right = create(11);
    root->right->left->left->left = create(14);
    root->right->left->left->right = create(15);
    root->right->right = create(7);
    root->right->right->right = create(12);
    root->right->right->right->left = create(16);
    root->right->right->right->right = create(17);
    int k;
    cin>>k;
    leaves(root,k);

    return 0;
}
