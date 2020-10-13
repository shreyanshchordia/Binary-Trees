//Problem Statement: Given a Binary Tree, find if a tree is a sum tree or not.
//Solution Approach: I have computed the sum of the root-node's left and right subtrees , and compared it with the root-node's value.They should be equal in a sum tree.
//                   If they are we recurse further or we return 0; We return 1 , if the root-node is a leaf node or a nullptr;

/* A utility function to get the sum of values in tree with root
  as root */
int sum(TreeNode* root)
{
   if(root == nullptr)
     return 0;
   return sum(root->left) + root->data + sum(root->right);
}



/* returns 1 if sum property holds for the given
    node and both of its children */

int issumtree(TreeNode* root)
{
    int ls, rs;

    /* If root is null or it's a leaf node then
       return true */
    if(root == nullptr ||
            (root->left == nullptr && root->right == nullptr))
        return 1;

   /* Get sum of nodes in left and right subtrees */
   ls = sum(root->left);
   rs = sum(root->right);

   /* if the node and both of its children satisfy the
       property return 1 else 0*/
    if((root->data == ls + rs)&&
            issumtree(root->left) &&
            issumtree(root->right))
        return 1;

   return 0;
}
