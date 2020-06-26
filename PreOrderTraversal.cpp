// a function for pre-order traversal of any tree

void preorder(node* root){
        
        // base condition
        if(root==NULL) return;
        
        else{
            cout<<root->data<<'\n';    // printing current
            preorder(root->left);      // printing left
            preorder(root->right);     // printing right
        }

        return;
}
