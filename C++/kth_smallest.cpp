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
		cout << "K-th Smallest Element is " << res->data;  // 2nd smallest number in BST is 21
} 

int main() 
{ 
	Node* root = NULL; 
	int keys[] = { 88,21,15,32,72,50 }; //Inorder or Ascending Order : 15,21,32,50,72,80

	for (int x : keys) 
		root = insert(root, x); 

	int k = 2;  // k=2, So 2nd smallest number in the BST
	ShowSmall(root, k);  //If k=2, OP should be 21
	return 0; 
}
