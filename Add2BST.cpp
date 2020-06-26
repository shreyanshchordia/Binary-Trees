// Function to add data to a Binary Search Tree using double pointers.
// Double pointers can make things simpler

void add(int x, node** p){

    if( *p == NULL){

        node* newnode = new node;
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        *p = newnode;

        return;
    }
    else{
        if (x > (*p)->data){
            add(x, &(*p)->right);
        }
        else{
            add(x, &(*p)->left);
        }
    }

    return;
}
