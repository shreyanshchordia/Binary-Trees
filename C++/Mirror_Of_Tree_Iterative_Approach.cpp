// Iterative CPP program to convert a Binary Tree to its mirror 
#include<bits/stdc++.h> 
using namespace std; 
  
// A binary tree node has data, pointer to left child and a pointer to right child
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 

// newNode function to make or create a new node
struct Node* newNode(int data) 
  
{ 
	// Take a temporary node
    struct Node* tmp = new Node;
    // Set the data of the temporary node to data
    tmp->data = data;
    // Set left and right child to NULL
    tmp->left = tmp->right = NULL;
    // Return the temporary node
    return(tmp); 
}

// mirrorOfTree function to convert tree into its mirror image using queue
void mirrorOfTree(struct Node* root) 
{ 
    if (root == NULL) 
        return; 
  	
  	// Take a queue
    queue<Node*> q;
    
    // Push the root node to the queue
    q.push(root); 
    
    // Loop till queue becomes empty
    while (!q.empty()) 
    { 
        Node* curr = q.front(); 
        q.pop(); 
  		
  		// Swap the left and right child
        swap(curr->left, curr->right); 
  		
  		// Check if the left child is NULL or not if not push it into the queue
        if (curr->left!=NULL) 
            q.push(curr->left);
        // Check if the right child is NULL or not if not push it into the queue
        if (curr->right!=NULL) 
            q.push(curr->right); 
    } 
}

// Function to print Inorder traversal.
void inOrderTraversal(struct Node* node) 
{ 
    if (node!= NULL) {
    	// Make recursive call to inOrderTraversal for left child
    	inOrderTraversal(node->left);
    	// Print the data of the current node
	    cout << node->data << " ";
	    // Make recursive call to inOrderTraversal for right child
	    inOrderTraversal(node->right); 
	}
}
  
// Main function
int main() 
{ 
	// Root node and its child insertion
    struct Node *root = newNode(66); 
    root->left        = newNode(12); 
    root->right       = newNode(36); 
    root->left->left  = newNode(13); 
    root->left->right = newNode(16); 
    root->right->left  = newNode(29); 
    root->right->right = newNode(99);
  
    // Print inorder traversal of the input tree
    cout << "The constructed tree is: "<<endl;
	// InOrder Traversal of the original tree 
    inOrderTraversal(root);
    cout<<endl;
  
    // Convert tree to its mirror
    mirrorOfTree(root); 
  
    // Print inorder traversal of the mirror tree
    cout << "The mirror tree is: "<<endl;
    
    // InOrder Traversal of the mirror tree 
    inOrderTraversal(root);
    cout<<endl;
  
    return 0; 
}
