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

stack<node*>s;
void preorder(struct node * p)
{
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        if(p->right!=NULL)
            s.push(p->right);
        p=p->left;
    }
    while(!s.empty())
    {
        node *p=s.top();
        s.pop();
        while(p!=NULL)
        {
            cout<<p->val<<" ";

            if(p->right!=NULL)
            {
                s.push(p->right);
            }

                p=p->left;
        }

    }
    cout<<endl;
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
    cout<<"Iterative preorder traversal of given tree is:\n";
    preorder(root);
}

