#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(){};
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
    

class Tree{
    private:
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

    // declarations
    node* TreeToDLL(node* &head, node* prev, node* root);

    node* TreeToDLL();

    // helper functions
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

node* Tree:: TreeToDLL(){
    node* head = NULL;
    node* prev = NULL;
    prev = TreeToDLL(head, prev, root);
    head->left = prev;
    prev->right = head;
    return head;
}

node* Tree:: TreeToDLL(node* &head, node* prev, node* root){

    if(root == NULL) return prev;

    prev = TreeToDLL(head, prev, root->left);

    if(head == NULL){
        head = new node(root->data);
        prev = head;
    }

    else{
        root->left = prev;
        prev->right = root;
        prev = root;
    }

    return TreeToDLL(head, prev, root->right);
}

void PrintDLL(node* head){
    node* temp = head;

    do{
        cout<<temp->data<<" ";
        temp = temp->right;
    }while(temp != head);

    cout<<"\n";

    return;    
}

void PrintDLLReverse(node* head){
    node* temp = head->left;

    do{
         cout<<temp->data<<" ";
         temp = temp->left;
    }while(temp != head->left);
    cout<<endl;
    return;
}

int main(){

    Tree tree;
    tree.add(1);
    tree.add(4);
    tree.add(7);
    tree.add(2);
    tree.add(9);
    tree.add(0);

    node* head = tree.TreeToDLL();

    PrintDLL(head);
    PrintDLLReverse(head);
}
