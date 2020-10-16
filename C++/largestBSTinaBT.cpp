/* **************************************************************************************
 Program to find largets Binary search Tree in a Binary Tree.
 BST is a tree in which:
  1. LeftNode has smaller value than parent.
  2. RightNode has greater value than parent.
  --- Applicable at every Node of BST.

***************************************************************************************** */

//Abhinav here....
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// User defined class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Build Tree from preorder and Inorder traversal of Tree.
int preIndex = 0;
TreeNode* buildTreeFromPreorderInorder(int pre[], int in[], int start, int end) {
    // Base Case
    if (start > end) {
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[preIndex]);

    int mid = -1;

    // Finding midValue
    for (int i = start; i <= end; i++) {
        if (in[i] == pre[preIndex]) {
            mid = i;
            break;
        }
    }

    preIndex++;
    // Calling for right and left subtree.
    root->left = buildTreeFromPreorderInorder(pre, in, start, mid - 1);
    root->right = buildTreeFromPreorderInorder(pre, in, mid + 1, end);

    return root;
}

// User defined class
class DetailedTree {
public:
    int size;
    bool bst;
    int minValue;
    int maxValue;
};

// function to calculate largest BST using MinRange and MaxRange.
DetailedTree maxBSTinBT(TreeNode* root) {
    DetailedTree obj;
    // Base Case
    if (root == NULL) {
        obj.bst = true;
        obj.size = 0;
        obj.maxValue = INT_MIN; // INT_MAX
        obj.minValue = INT_MAX; // INT_MIN
        return obj;
    }

    // Calling for right and left Subtree and checking their range.
    DetailedTree leftStatus = maxBSTinBT(root->left);
    DetailedTree rightStatus = maxBSTinBT(root->right);

    // Checking for minValue and maxValue
    if (!leftStatus.bst or !rightStatus.bst or root->val < leftStatus.maxValue or root->val > rightStatus.minValue) {
        // NOT A BST
        obj.bst = false;
        obj.size = max(leftStatus.size, rightStatus.size);
        return obj;
    }

    // BST
    obj.bst = true;
    obj.size = leftStatus.size + 1 + rightStatus.size;
    // Setting the minValue and maxValue by checking null conditon.
    obj.maxValue = root->right != NULL ? rightStatus.maxValue : root->val;
    obj.minValue = root->left != NULL ? leftStatus.minValue : root->val;
    return obj;
}

int main() {
    int n;
    cin >> n;
    int pre[n];

    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    int in[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    TreeNode* root = NULL;
    root = buildTreeFromPreorderInorder(pre, in, 0, n - 1);
    DetailedTree obj = maxBSTinBT(root);

    // Print the Size of largest BST in Binary Tree.
    cout << obj.size << endl;
    return 0;
}

/* ************************************************************
    Input : - N:-  4
             Pre:- 60 65 50 70
             Ino:- 50 65 60 70

    The tree looks like

             60
          /      \
       65           70
     /
   50
The largest BST subtree is

       65
     /
   50
which has the size 2 i.e. it has 2 nodes in it.

 ********************************************************************/