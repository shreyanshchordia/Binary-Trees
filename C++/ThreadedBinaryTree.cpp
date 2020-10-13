#include <iostream>
#include<algorithm>
#include<cstdlib>
#include <math.h>
#define COUNT 10
using namespace std;

typedef struct  Node
{
  int data;
  int leftflag,rightflag; // 1 for address of child, 0 address of parent
  struct Node *left,*right;

}Node;
void add(Node **p, int v)
{
    Node * newnode=(Node*)malloc(sizeof(Node));
    newnode->data=v;
    newnode->leftflag =0;
    newnode->rightflag=0;
    if(*p==NULL)
    {
        newnode->left=NULL;
        newnode->right=NULL;
        *p=newnode;
    }
    else
    {
        Node* temp=*p;
        while(1){
            if(temp->data > v && temp->leftflag == 1)
                temp = temp->left;
            else if(temp->data < v && temp->rightflag == 1)
                temp = temp->right;
            else
                break;
        }
        if(temp->data < v){
            newnode->right = temp->right;
            temp->right = newnode;
            temp->rightflag=1;
            newnode->left = temp;
        }else{
            newnode->left = temp->left;
            temp->left = newnode;
            temp->leftflag=1;
            newnode->right = temp;
        }
    }
}
void inorder(Node *p){
    while(1){
        while(p->leftflag)
            p=p->left;
        cout<<p->data<<" ";
        while(!p->rightflag){
            p=p->right;
            if(p== NULL)
                return;
            cout<<p->data<<" ";
        }
        p=p->right;
    }
}

int TBTsearch(Node*p,int value){ // returns 1 if present else 0
    while(1){
        if(p->data>value && p->leftflag){
            p=p->left;
        }
        else if(p->data<value && p->rightflag){
            p=p->right;
        }
        else{
            break;
        }
    }
    if(p->data==value){
        return 1;
    }
    return 0;
}


int main()
{
    Node *root=NULL;
    add(&root,50);
    add(&root,70);
    add(&root,80);
    add(&root,40);
    add(&root,60);
    inorder(root);
    cout<<endl;
    cout<<TBTsearch(root,10)<<endl;
    cout<<TBTsearch(root,80)<<endl;
    return 0;
}
