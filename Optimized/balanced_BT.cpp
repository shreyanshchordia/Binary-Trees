/* **************************************************************************************
 The Balanced binary Tree is a tree in which the absolute difference of height of leftTree and RightTree
 is less than or equal to 1.
	Tree is balanced if:
		1. LeftBalance = True
		2. RightBalance = True
		3. abs(leftHeight - rightHeight) <= 1.
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
class BalanceHeight {
public:
	int height;
	bool balance;
};

// Time Complexity : O(n)
BalanceHeight balanceOptimized(TreeNode* root) {
	BalanceHeight val;

	if (root == NULL) {
		val.height = -1;
		val.balance = true;
		return val;
	}

	BalanceHeight leftPair = balanceOptimized(root->left);
	BalanceHeight rightPair = balanceOptimized(root->right);

	val.height = max(leftPair.height, rightPair.height) + 1;

	if (!leftPair.balance or !rightPair.balance) {
		val.balance = false;
		return val;
	}

	int gap = abs(leftPair.height - rightPair.height);

	if (gap > 1) {
		val.balance = false;
		return val;
	}

	val.balance = true;
	return val;

}

int main() {
	// Print 1 if balance otherwise 0.
	TreeNode* root = builtTree(NULL);
	BalanceHeight val = balanceOptimized(root);
	cout << val.balance << endl;
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
