#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node * left,*right;
}*p,*q;

node * getnode(int x)
{
    q=new node();
    q->val=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}

stack<node *>s1;
void inorder(struct node *p)
{
    while(p!=NULL)
    {
        s1.push(p);
        p=p->left;
    }

    while(!s1.empty())
    {
        node *p=s1.top();
        s1.pop();
        cout<<p->val<<" ";
        p=p->right;
        while(p!=NULL)
        {
             s1.push(p);
             p=p->left;
        }

    }
}

int main()
{
    struct node * root=getnode(1);
    root->left=getnode(2);
    root->right=getnode(3);
    root->left->left=getnode(4);
    root->left->right=getnode(5);
    root->right->left=getnode(6);
    root->right->right=getnode(7);
    cout<<"Iterative inorder traversal of given tree is:\n";
    inorder(root);
}

