//Given a binary tree find it's zigzag traversal without recursion.
//Here, 2 stacks are used to store values of nodes alternatively
//Time complexity is O(n) as you are visiting every node once
//Space complexity is n+n=2n O(2n)=O(n) for 2 stacks
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

void zigzag(struct node* root)
{
	stack<node *>s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())       //continue until both stack becomes empty
	{
	    while(!s1.empty())                  //remove element from s1,print it until s1 becomes empty
	    {
	        node * p=s1.top();
    	    s1.pop();
    	    cout<<p->val<<" ";
    	    if(p->left!=NULL)               //if it has left or right child, push it into s2.
    	        s2.push(p->left);           //first left then right as we want right on top
            if(p->right!=NULL)
    	        s2.push(p->right);
	    }
	    while(!s2.empty())                  //remove element from s2,print it until s1 becomes empty
	    {
	        node * p=s2.top();
	        s2.pop();
	        cout<<p->val<<" ";
	        if(p->right!=NULL)              //if it has left or right child, push it into s1.
	            s1.push(p->right);          //first right then left as we want left on top
	       if(p->left!=NULL)
	            s1.push(p->left);
	    }
	}
}

int main()
{
    struct node * root=getnode(1);          // defines tree manually
    root->left=getnode(2);
    root->right=getnode(3);
    root->left->left=getnode(4);
    root->left->right=getnode(5);
    root->right->left=getnode(6);
    root->right->right=getnode(7);
    cout<<"Zigzag order traversal of given tree is:\n";
    zigzag(root);                           // fn is called to traverse tree in zigzag order
}
