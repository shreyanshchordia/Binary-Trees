#include <bits/stdc++.h>
//we are given a number we need to find and print the continous set of nodes in the tree whose sum will be same as the given number 
using namespace std;
int s = 0;//for storing the sum of the nodes we visit
stack<struct Node*> st;// for temporarily storing the nodes we visit
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
int sum(struct Node* root,int k)
{
    if(root==NULL)//if the root node is null either we exit or return to parent node
    {
        return 0;
    }
    s+=root->data;//adding the data of the node we cross
    st.push(root);//storing the node whose data is added in previous step
    if(s==k)//compares the given number and sum
    {
        while(!st.empty())//if previous condition satisfies we print the stack and empty it
        {
            struct Node* temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
    sum(root->left,k);//for recursively traversing to left child nodes
    sum(root->right,k);//for recursively traversing to right child nodes
    s-=root->data;//once we add the data of left and right child nodes we need to return from the node , so the data is subtracted from the computed sum
    st.pop();//the node whose data is subtracted in previous step is removed from stack
    return 0;
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
    root->right = create(3);
    root->right->left = create(6);
    root->right->left->left = create(10);
    root->right->left->right = create(11);

    root->right->right = create(7);
    root->right->right->right = create(12);
    int k;
    cout<<"enter the sum\n";
    cin>>k;
    sum(root,k);

    return 0;
}
