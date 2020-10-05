#include <bits/stdc++.h>
using namespace std;

// Author: Swoyam S Sahoo
//diagonal view of a binary tree means the nodes of the tree we encounter when we mode from one courner to other diagonally
//example - let our tree be       1
 //                            /     \
//                            2        3
//                          /   \    /   \
//                         4    5   6     7
//                                    \
//                                     8           
//let we are moving from left left most cornor to rightmost diagonally
// in this cast the output should be     -      4
//                                              2 5 6 8
//                                              1 3 7

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
void diagonalview(struct Node *root)
{
    int k;
    queue<struct Node *> q1;//for temporarily storing the nodes
    queue<int> q2;//to store temporary numbers corresponding to the nodes stord in q1
    map<int, list<struct Node *>> mp; //to store all the nodes according to the number in q2
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
            q2.push(k - 1);
        }
        if (temp->right != NULL)
        {
            q1.push(temp->right);
            q2.push(k);
        }
        mp[k].push_back(temp);
    }
    cout << "the diagonal view of the tree is:\n";
    int i;
    for (auto i : mp)
    {
        while (!i.second.empty())
        {
            cout << i.second.front()->data << " ";//we are moving from front to back and eliminating simultaniously
            i.second.pop_front();
        }
        cout << endl;
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
    diagonalview(root);
    return 0;
}
