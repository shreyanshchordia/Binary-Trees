int heightoftree(node* root)
{
     if(root==NULL)
     {
        return 0;
     }
     return 1+max(heightoftree(root->left),heightoftree(root->right));

}
