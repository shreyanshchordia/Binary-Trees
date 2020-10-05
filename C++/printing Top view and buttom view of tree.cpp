#include <bits/stdc++.h>
using namespace std;

// Author: Swoyam S Sahoo
///
//example - let our tree be       1
 //                            /     \
//                            2        3
//                          /   \    /   \
//                         4    5   6     7
//                                    \
//                                     8           
//
// in this cast the output should be     
//    top view ---4 2 1 3 7
//    buttom view  --- 4 2 6 8 7

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newnode(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
void printtopbuttom(struct Node *root)
{
    int k;
    queue<struct Node *> q1;//for storing nodes
    queue<int> q2;//for storing corresponding numbers for the nodes in q1
    map<int, list<struct Node *>> mp;//for storing all the nodes as well as their corresponding numbers in q2
    q1.push(root);
    q2.push(0);
    while (!q1.empty())
    {
        struct Node *temp = q1.front();
        k = q2.front();
        q1.pop();
        q2.pop();
        if (temp->left != NULL)
        {
            q1.push(temp->left);
            q2.push(k - 1);//left child node is given a number less than the parent node(i.e.. k-1)
        }
        if (temp->right != NULL)
        {
            q1.push(temp->right);
            q2.push(k + 1);//right child is given a number more then the parent node(i.e.. k+1)
        }
        mp[k].push_back(temp);
    }
    cout << "the top view of the tree is:\n";
    int i;
    for (auto i : mp)
    {
        cout << i.second.front()->data << " ";//the front of each list gives the top view(in this case)
    }
    cout << endl;
    cout << "the buttom view of the tree is:\n";
    for (auto i : mp)
    {
        cout << i.second.back()->data << " ";//the back of the lists give the buttom view(in this case)
    }
}
int main()
{
    struct Node *root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right = newnode(3);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    printtopbuttom(root);
    return 0;
}
