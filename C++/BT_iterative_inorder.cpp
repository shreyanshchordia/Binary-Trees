//Given a binary tree find it's inorder traversal that is (left,node,right) but in iterative fasion without recursion.
//Here,stack is used to store values of nodes
//Time complexity is O(n) as you are visiting every node once
#include<bits/stdc++.h>
using namespace std;

struct node                                 //structure of tree defined
{
    int val;
    struct node * left,*right;
}*p,*q;

node * getnode(int x)                       //this fn takes value and returns node of tree containing that value
{
    q=new node();
    q->val=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}

stack<node *>s1;
void iterativeinorder(struct node *p)
{
    while(p!=NULL)
    {
        s1.push(p);                           //push current node in stack without printing
        p=p->left;                            //go to it's left until it becomes NULL
    }

    while(!s1.empty())                        //repeat the process until stack becomes empty
    {
        node *p=s1.top();
        s1.pop();                             //every time pop one element from stack
        cout<<p->val<<" ";
        p=p->right;                           //print current node and go to it's right
        while(p!=NULL)
        {
             s1.push(p);                      //push current node and go to it's left until becomes NULL
             p=p->left;
        }

    }
}

int main()
{
    struct node * root=getnode(1);            // defines tree manually
    root->left=getnode(2);
    root->right=getnode(3);
    root->left->left=getnode(4);
    root->left->right=getnode(5);
    root->right->left=getnode(6);
    root->right->right=getnode(7);
    cout<<"Iterative inorder traversal of given tree is:\n";
    iterativeinorder(root);                 // fn is called to traverse iteratively in inorder
}

