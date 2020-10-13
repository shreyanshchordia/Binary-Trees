void reverseLevelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    q.push(root);
    
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);
        
        if (root->right)
            q.push(root->right); 
 
       
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