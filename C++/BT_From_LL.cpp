/* 
-------------------------------------------------------------PROBLEM STATEMENT(GFG)-------------------------------------------------------------------------
Make Binary Tree From Linked List 
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
 
Example 1:

Input:
N = 5
K = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
 */

//-------------------------------------------------------------------------SOLUTION-----------------------------------------------------------------
/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

void convert(Node *head, TreeNode *&root)
{
    vector<TreeNode *> v;
    Node *temp = head;
    while (temp)
    {
        TreeNode *node = new TreeNode(temp->data);
        v.push_back(node);
        temp = temp->next;
    }
    int n = v.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (2 * i + 1 < n)
            v[i]->left = v[2 * i + 1];
        if (2 * i + 2 < n)
            v[i]->right = v[2 * i + 2];
    }
    root = v[0];
}
