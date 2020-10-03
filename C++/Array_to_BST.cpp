#include<bits/stdc++.h>

using namespace std;

// Array to Balanced Binary Search Tree
// Convert an Array to a Balanced Binary Search Tree

struct node {       // Single Node
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left=right=NULL;
    }
};

class tree {        // Binary Tree Class
    private:
    node *root;
    void inorder(node* root){       // Inorder Traversal

        if(root==NULL) return;
        
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        return;
    }

    void postorder(node* root){     // Postorder Traversal

        if(root == NULL) return;

        else{
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

    void preorder(node* root){      // Preorder Traversal

        if(root == NULL) return;

        else{
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    public:
    tree() {        // Contructor
        this->root=NULL;
    }


    void add(int val) {     // Add Element to BST
        if(root==NULL) {
            root = new node(val);
            return;
        }
        node *it = root;
        while(it) {
            if(val > it->data) {
                if(it->right) {
                    it = it->right;
                }
                else {
                    it->right = new node(val);
                    return;
                }
            }
            else {
                if(it->left) {
                    it = it->left;
                }
                else {
                    it->left = new node(val);
                    return;
                }
            }
        }
        return;
    }


    void inorder(){
        inorder(this->root);
        cout<<"\n";
    }

    void preorder(){
        preorder(this->root);
        cout<<"\n";
    }

    void postorder(){
        postorder(this->root);
        cout<<"\n";
    }
};

void build_tree(vector<int> &a,int l,int r,tree &t) {   // Build BST
    if(l==r) {
        t.add(a[l]);
        return;
    }
    if(l>r) return;
    int mid = (l+r)/2;
    t.add(a[mid]);
    build_tree(a,l,mid-1,t);
    build_tree(a,mid+1,r,t);
    return;
}


int main() {
    int n;
    cin>>n;     // Number of Elements in Array

    vector<int> a;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        a.push_back(num);       // Array Input
    }

    sort(a.begin(),a.end());    // Sorting Array    

    tree t;
    build_tree(a,0,n-1,t);

    t.preorder();
    t.inorder();        // It will be Sorted
    t.postorder();


}