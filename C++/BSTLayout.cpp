// A Binary Search Tree Class that can used as a start for almost any problem on BST's

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
            inorder(root->left);
            inorder(root->right);
            cout<<root->data<<"\n";
        }
    }

    void preorder(node* root){

        if(root == NULL) return;

        else{
            cout<<root->data<<"\n";
            inorder(root->left);
            inorder(root->right);
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
};


int main(){

    Tree tree;
    tree.add(5);
    tree.add(6);
    tree.add(3);

    tree.inorder();
    tree.postorder();
    tree.preorder();

}
