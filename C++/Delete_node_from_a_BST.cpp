/*
----------------------------------------------------------------PROBLEM STATEMENT(GFG)--------------------------------------------------------------------
Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.


Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).            
 */

//---------------------------------------------------------------------SOLUTION------------------------------------------------------------------------
/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

Node *findmin(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return root;
    if (root->left == NULL)
        return root;
    return findmin(root->left);
}
// Return the root of the modified BST after deleting the node with value X
Node *deleteNode(Node *root, int x)
{
    Node *node;

    if (root == NULL)
        return root;
    if (root->data != x)
    {
        if (x < root->data)
            root->left = deleteNode(root->left, x);
        else
            root->right = deleteNode(root->right, x);
    }
    else
    {
        // Target node is a leaf node then just delete the node

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Target node has one child

        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        //Target node has two child then find inorder successor of the node. Inorder successor can be obtained by finding the minimum value in right child of the node.

        Node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

        return root;
    }
}
