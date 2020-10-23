// Problem Statement : Given a binary tree, print all nodes will are full nodes. Full Nodes are nodes which has both left and right children as non-empty.
// Solution Approach : We traverse the tree in inorder fashion , and check if the nodes have a a full node.

// Traverses given tree in Inorder fashion and
// prints all nodes that have both children as
// non-empty.
void findFullNode(TreeNode *root)
{
    if (root != NULL)
    {
        findFullNode(root->left);
        if (root->left != NULL && root->right != NULL)
            cout << root->data << " ";
        findFullNode(root->right);
    }
}
