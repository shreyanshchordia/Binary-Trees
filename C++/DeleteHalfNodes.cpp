#include <iostream>
using namespace std;

class Tree{
    private:
    struct node{
        int data;
        node* left;
        node* right;
    };
    node* root;

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

    void inorder(node* root){

        if(root==NULL) return;
        
        else{
            inorder(root->left);
            cout<<root->data<<'\n';
            inorder(root->right);
        }

        return;
    }

    void postorder(node* root){

        if(root == NULL) return;

        else{
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<"\n";
        }
    }

    void preorder(node* root){

        if(root == NULL) return;

        else{
            cout<<root->data<<"\n";
            preorder(root->left);
            preorder(root->right);
        }
    }

    public:
    Tree(){
        this->root = NULL;
    }

    void add(int x){

        node** p = &(this->root);
        this->add(x, p);
    }

    void inorder(){
        inorder(this->root);
    }

    void preorder(){
        preorder(this->root);
    }

    void postorder(){
        postorder(this->root);
    }

    void DeleteHalfNodes(node** temp){
        if (*temp == NULL) {
            return;
        }

        else if((*temp)->right == NULL && (*temp)->left == NULL)  return;

        else if((*temp)->right != NULL && (*temp)->left == NULL){
            *temp = (*temp)->right;
            DeleteHalfNodes(temp);
        }
        else if ((*temp)->right == NULL && (*temp)->left != NULL){
            *temp = (*temp)->left;
            DeleteHalfNodes(temp);
        }
        else{
            DeleteHalfNodes(&(*temp)->left);
            DeleteHalfNodes(&(*temp)->right);
        }
        return;
    }

    void DeleteHalfNodes(){
        node** temp = &root;

        DeleteHalfNodes(temp);
    }

};


int main(){

    Tree tree;
    tree.add(5);
    tree.add(1);
    tree.add(3);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(7);
    tree.inorder();
    cout<<"\n";
    tree.postorder();
    cout<<"\n";
    tree.preorder();
    cout<<"\n";
    tree.DeleteHalfNodes();
    cout<<"AFTER DELETING\n";
    tree.inorder();
    cout<<"\n";
    tree.postorder();
    cout<<"\n";
    tree.preorder();
}
