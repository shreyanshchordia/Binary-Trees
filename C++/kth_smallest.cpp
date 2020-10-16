//Find k-th smallest element in BST 

#include <iostream> 
using namespace std; 

struct Node { 
	int data; 
	Node *left, *right; 
	Node(int x) 
	{ 
		data = x; 
		left = right = NULL; 
	} 
}; 

Node* insert(Node* root, int x) 
{ 
	if (root == NULL) 
		return new Node(x); 
	if (x < root->data) 
		root->left = insert(root->left, x); 
	else if (x > root->data) 
		root->right = insert(root->right, x); 
	return root; 
} 

Node* small(Node* root, int& k) 
{ 

	if (root == NULL) 
		return NULL; 
 
	Node* left = small(root->left, k); 

	if (left != NULL) 
		return left; 

	k--; 
	if (k == 0) 
		return root; 

	return small(root->right, k); 
} 

void ShowSmall(Node* root, int k) 
{ 

	int count = 0; 
	Node* res = small(root, k); 
	if (res == NULL) 
		cout << "There are less than k nodes in the BST"; 
	else
		cout << "K-th Smallest Element is " << res->data; 
} 

int main() 
{ 
	Node* root = NULL; 
	int keys[] = { 88,21,15,32,72,50 }; 

	for (int x : keys) 
		root = insert(root, x); 

	int k = 2; 
	ShowSmall(root, k); 
	return 0; 
}
