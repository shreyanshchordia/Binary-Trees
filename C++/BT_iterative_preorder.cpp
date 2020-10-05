//Given a binary tree find it's preorder traversal that is (node,left,right) but in iterative fasion without recursion.
//Here,stack is used to store values of nodes
//Time complexity is O(n) as you are visiting every node once
//Space complexity is O(log n) that is height of tree

#include<bits/stdc++.h>
using namespace std;

struct node                                             //structure of tree defined
{
    int val;
    struct node * left,*right;
}*p,*q;

node * getnode(int x)                                   //this fn takes value and returns node of tree containing that value
{
    q=new node();
    q->val=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}

stack<node*>s;
void iterativepreorder(struct node * p)
{
    while(p!=NULL)                                      //print current value and go to it's left until it becomes NULL
    {
        cout<<p->val<<" ";
        if(p->right!=NULL)
            s.push(p->right);                           //if current node has right child, push into stack
        p=p->left;
    }
    while(!s.empty())                                   //repeat the process until stack becomes empty
    {
        node *p=s.top();                                //every time pop one element from stack and follow same steps
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
    struct node * root=getnode(1);                           // defines tree manually
    root->left=getnode(2);
    root->right=getnode(3);
    root->left->left=getnode(4);
    root->left->right=getnode(5);
    root->right->left=getnode(6);
    root->right->right=getnode(7);
    cout<<"Iterative preorder traversal of given tree is:\n";
    iterativepreorder(root);                               // fn is called to traverse iteratively in preorder                              
}

