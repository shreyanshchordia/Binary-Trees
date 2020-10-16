/* **************************************************************************************
 The Diameter of a binary Tree is the longest path between any two nodes in the tree.
	Diamter is largest among
		1. Left Tree
		2. Right Tree
		3. Between Left and Right Tree
   -->>>>> OPTIMIZED SOLUTION <<<<<--
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

// User defined class
class DiaHeight {
public:
	int height;
	int diameter;
};

// Time Complexity : O(n)
DiaHeight diameterOptimized(TreeNode* root) {
	DiaHeight val;

	if (root == NULL) {
		val.diameter = 0;
		val.height = -1;
		return val;
	}

	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	int leftDiameter = leftPair.diameter;
	int rightDiameter = rightPair.diameter;

	int leftHeight = leftPair.height;
	int rightHeight = rightPair.height;

	int mereThrough = leftHeight + rightHeight + 2;

	int totalDia = max(mereThrough, max(leftDiameter, rightDiameter));

	int meriHeight = max(leftHeight, rightHeight) + 1;

	val.diameter = totalDia;
	val.height = meriHeight;
	return val;
}

int main() {

	TreeNode* root = builtTree(NULL);
	DiaHeight val = diameterOptimized(root);
	cout << val.diameter << endl;
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
