//Problem Statement : Given a binary tree , print the nodes at odd levels.
//Solution Approach : I chose a Recursive approach for this. The isOdd value is toggled on level change.

//function to print odd level node  values
void printOddNodes(TreeNode *root, bool isOdd = true)
{
    //root is nullptr
    if (root == nullptr)
      return;

    //if the level is an odd one , we print it
    if (isOdd)
       cout << root->data << " " ;


    //we change the isOdd value after every level
    printOddNodes(root->left, !isOdd);
    printOddNodes(root->right, !isOdd);
}
