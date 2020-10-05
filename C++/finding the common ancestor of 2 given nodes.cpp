#include <bits/stdc++.h>

using namespace std;
//Algorithm to find the common ancestor of 2 given nodes without using inorder traversal
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
struct Node* lca(struct Node* root,struct Node* p,struct Node* q)//root, 1st node and 2nd node
{
    //logic behind the code----
    //we will try to find the given nodes in the tree
    //let now we find one of the 2 nodes we will send the data in the node to it's parent 
    //and if we don't find any node we will send Null to the parent node
    //parent will contain 2 data at the same time
    //1 - if both data re null then the parent will save null
    //2 - if one of the data is null and other one is a given node ,the data of the given node is saved
    //3- if both of them are data of given nodes then we have found the ancesstor
     if(root==NULL)
     {
         return NULL;
     }
     else if(root==p||root==q)//here we are comparing nodes with all the nodes in the tree
     {
         return root;
     }
     struct Node* l = lca(root->left,p,q);
     struct Node* r = lca(root->right,p,q);
     if(l!=NULL&&r!=NULL)//checks condition for above mentioned conditioned 
     {
         return root;// this root is the ancestor
     }
     else
     {
         return (l!=NULL?l:r);// it excutes (2)  
     }
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
   struct Node* ans = lca(root,root->left->left->left->left = create(13),root->left->right = create(5));
   cout<<ans->data;
    return 0;
}
