/* 
---------------------------------------------------------------------PROBLEM STATEMENT(GFG)-------------------------------------------------------------
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/

// -------------------------------------------------------------------------SOLUTION-------------------------------------------------------------------

int sum(Node *root)
{
    if (root == NULL)
        return 0;
    int x = root->data;
    //leaf nodes must be 0
    if (root->left == NULL && root->right == NULL)
    {
        root->data = 0;
        return x;
    }
    //non-leaf nodes
    root->data = sum(root->left) + sum(root->right);
    return x + root->data;
}

void toSumTree(Node *node)
{
    sum(node);
}