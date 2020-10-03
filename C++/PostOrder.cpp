// function to print post-order for any binary tree

void postorder(node* root){
        
        // base condition
        if(root == NULL) return;

        else{
            postorder(root->left);      // print left
            postorder(root->right);     // print right
            cout<<root->data<<"\n";     // print current
        }
}
