/*Problem Statement-- Given a Binary Search Tree (with all values unique) and two node values.
Find the Lowest Common Ancestors of the two nodes in the BST 

 Example-
     2
   /   \
  1     3
n1 = 1, n2 = 3
Output: 2

*/

//Solution- 

Node* LCA(Node *root, int n1, int n2)
{
 if(root==NULL)
 return NULL;
 
 if(n1<root->data&&n2<root->data){
   return LCA(root->left,n1,n2);  
 }
  if(n1>root->data&&n2>root->data){
    return LCA(root->right,n1,n2);
 }

 return root;
}