//Given a binary tree find it's diagonal order traversal
//Here, queue is used to store node value
//Time complexity is O(n) as you are visiting every node once
//Space complexity is O(n) for one queue
#include<bits/stdc++.h>
using namespace std;

struct node                                     //structure of tree defined
{
    int val;
    struct node * left,*right;
}*p,*q;

node * getnode(int x)                           //this fn takes value and returns node of tree containing that value
{
    q=new node();
    q->val=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}

void diagonaltraversal(struct node* root)
{
	queue<node *>q;
	q.push(root);
	q.push(NULL);                                       //to detect end of diagonal
	while(!q.empty())
    {
        node * p=q.front();
        q.pop();

        if(p==NULL)
        {
            if(q.empty())                               //done with traversal
                return;
            else                                        //end of respective diagonal
            {
                cout<<"\n";
                q.push(NULL);
            }
        }

        else
        {
            while(p!=NULL)
            {
                cout<<p->val<<" ";                     // print value of node and go to its right
                if(p->left!=NULL)                      // if it has left child, store in queue
                    q.push(p->left);
                p=p->right;
            }
        }
    }
}

int main()
{
    struct node * root=getnode(1);                      // defines tree manually
    root->left=getnode(2);
    root->right=getnode(3);
    root->left->left=getnode(4);
    root->left->right=getnode(5);
    root->right->left=getnode(6);
    root->right->right=getnode(7);
    cout<<"Diagonal order traversal of given tree is:\n";
    diagonaltraversal(root);                            // fn is called to traverse tree in diagonal order
}

