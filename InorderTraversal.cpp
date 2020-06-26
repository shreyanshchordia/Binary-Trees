// a function for inorder traversal of any tree

void inorder(node* root){
        
        // base condition
        if(root==NULL) return;
        
        else{
            inorder(root->left);      // printing left
            cout<<root->data<<'\n';   // printing current
            inorder(root->right);     // printing right
        }

        return;

}
