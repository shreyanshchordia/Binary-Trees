//Problem Statement: Given a binary tree, check whether it is a complete binary tree or not.
//Note: A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.


/*
  Eg.            20                                     20             
                /   \                                  /   \
               4     6                                4     6
              / \   / \                              / \   / \
             10  2  1  5                            10  2  1  5
            / \                                    / \      \
            3  8                                  3   8      9
               
This is a complete Binary Tree.                 This is not a complete Binary Tree.
*/   


/*
Approach: The approach is to do a level order traversal starting from the root.
In the traversal, once a node is found which is NOT a Full Node, all the following nodes must be leaf nodes.
A Full Node is basically a node which has both left and right children.
Also, one more thing needs to be checked: If a node has an empty left child, then the right child must be empty.
*/

//This is the main function which returns true if the tree is complete and false otherwise.
bool isCompleteBT(node* root) 
{ 
    if (root == NULL) 
        return true; 
  
    queue<node *> q; 
    q.push(root); 
    
    //A flag variable which will be set true when a non-full node is seen 
    bool flag = false; 
  
    while(!q.empty()) 
    { 
        node *temp =q.front(); 
        q.pop(); 
  
        if(temp->left) 
        { 
            // If we have seen a non full node, 
            // and we see a node with non-empty left child, 
            // then the given tree is not a complete Biary Tree 
            if (flag == true) 
                return false; 
      
            q.push(temp->left);
        } 
        else 
            flag = true; 
  
        if(temp->right) 
        { 
            // If we have seen a non full node, 
            // and we see a node with non-empty right child,
            // then the given tree is not a complete Binary Tree 
            if(flag == true) 
                return false; 
  
            q.push(temp->right);
        } 
        else 
            flag = true; 
    } 
  
    return true; 
}