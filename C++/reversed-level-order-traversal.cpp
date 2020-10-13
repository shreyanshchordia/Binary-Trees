//Problem description  : Given a binary tree print the reverse level order traversal i.e. the level order traversal of the tree starting from the bottommost level of tree, going up.
//Solution Approach : I used a Queue and a Stack from standard template library of C++. Here, we do a normal level order traversal , but instead of printing a node we push it in a stack , and later print it
//Time Complexity : O(n) ,Space Complexitiy O(n) where n is the number of nodes in the tree
void reverseLevelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    
    //Base case : if root is nullptr, return
    if(root==nullptr)
    {
        return;
    }
    
    //else push the root node into the queue
    q.push(root);
    
    while(!q.empty())
    {
        //pop a node from the queue and make it the roor
        root = q.front();
        q.pop();
        s.push(root);
        
        //pushing the right child into the queue
        if (root->right)
            q.push(root->right); 
 
        //pushing the left child into the queue
        if (root->left)
            q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    
    }
}
