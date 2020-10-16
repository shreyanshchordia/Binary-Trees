/* **************************************************************************************
 The path in which sum of nodes is maximum is called Maximum Path Sum.
 For each node there can be four ways that the max path goes through the node:
	1. Node only
	2. Max path through Left Child + Node
	3. Max path through Right Child + Node
	4. Max path through Left Child + Node + Max path through Right Child

***************************************************************************************** */

//Abhinav here....
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// User defined class
class TreeNode {
public:
	int val;
	TreeNode* right;
	TreeNode* left;

	TreeNode(int data) {
		this->val = data;
		this->right = NULL;
		this->left = NULL;
	}
};

// Building a Binary Tree
TreeNode* builtTree(TreeNode* root) {
	int data;
	cin >> data;

	if (data == -1) return NULL;
	if (root == NULL) root = new TreeNode(data);
	root->left = builtTree(root->left);
	root->right = builtTree(root->right);
	return root;
}

//  Helper function
int helper(TreeNode* root, int &global) {
	// Base Case
	if (!root) return 0;

	// Recursive Case
	int rightMax = max(0, helper(root->right, global));
	int leftMax = max(0, helper(root->left, global));

	int mereThroughpath = leftMax + rightMax + root->val;

	global = max(global, mereThroughpath);

	return max(leftMax, rightMax) + root->val;
}

int maxpathSum(TreeNode* root) {
	int global = INT_MIN;
	helper(root, global);
	return global;
}

int main() {

	TreeNode* root = builtTree(NULL);
	cout << maxpathSum(root) << endl;
	return 0;
}

/*  Input: 1 2 4 -1 -1 5 -1 -1 3 -1 -1

	Constructed binary tree is
	         1
	       /   \
	     2      3
	   /  \
	 4     5

 *************************************************** */
