/*The diameter of a tree is the number of nodes on the longest path between two end nodes(also known as width of tree)*/

/*The diameter of a tree T is the largest of the following quantities:
    1. the diameter of T's left subtree.
    2. the diameter of T's right subtree.
    3. the longest path between leaves that goes through the root of T.
*/


// Rescursive C++ program to find the diameter of a Binary Tree.

#include<bits/stdc++.h>

using namespace std;

class Node{
 public:
    int data;
    Node *left;
    Node *right;
};

//function to create new node
Node* newNode(int data){
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
}

//function to compute the "Height" of the binary tree
int height(Node* node){
    if(node == nullptr) return 0;

    return 1+ max(height(node->left), height(node->right));
}

//Function to calculate the "Diameter" of the Binary tree

int diameter(Node* node){

    //Base case when tree is empty
    if(node == nullptr) return 0;

    // To get the height of left and right sub-trees
    int lheight = height(node->left);
    int rheight = height(node->right);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}

//Driver Code
int main(){

    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"The diameter of the given tree is: "<<diameter(root)<<"\n";
    return 0;
}
