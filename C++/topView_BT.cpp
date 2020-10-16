/* **************************************************************************************
 Program for printing Top View of a Binary Tree
 For each node:
  1. Calculate the distance from parent node
  2. Print all node which are at same level.

***************************************************************************************** */

//Abhinav here....
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// User defined class or struct
struct node {
  long int data;
  node *left, *right;
};

// Building Tree Level Vise Input
node* levelOrderInput() {
  // Queue to store previous and current level
  queue<node*> prevLevel, currentLevel;
  node *root = NULL;

  long int x;
  while (true) {
    long int x;
    cin >> x;
    if (root == NULL) {
      root = new node;
      root->data = x;
      root->left = root->right = NULL;
      prevLevel.push(root);
      continue;
    }

    // If level ends we break loop.
    if (prevLevel.empty())
      break;

    long int y;
    cin >> y;

    node *leftChid = NULL, *rightChild = NULL;
    node *parent = prevLevel.front();
    prevLevel.pop();

    // First Checking left node is not NULL
    if (x != -1) {
      leftChid = new node;
      leftChid->data = x;
      leftChid->left = leftChid->right = NULL;
      currentLevel.push(leftChid);
    }

    // Checking right node is not NULL
    if (y != -1) {
      rightChild = new node;
      rightChild->data = y;
      rightChild->left = rightChild->right = NULL;
      currentLevel.push(rightChild);
    }

    // assigning left and right child to its parent.
    parent->left = leftChid;
    parent->right = rightChild;

    // Changing level to level + 1.
    if (prevLevel.empty()) {
      swap(prevLevel, currentLevel);
    }
  }
  return root;
}

// Function to print Top View
void topView(node *root, map<long int, long int> &m, long int pos = 0) {
  // Base Case
  if (root == NULL)
    return;

  // Checking the frequency in map to be present only once at same dist.
  if (m[pos] == 0)
    m[pos] = root->data;

  // Recursive Case
  /* *********************************************
   Calling left and decrese the level
   Calling right and increase the
   ************************************************/
  topView(root->left, m, pos - 1);
  topView(root->right, m, pos + 1);
}

int main() {

  node *root = levelOrderInput();
  map<long int, long int> m;

  // Calling function
  topView(root, m);

  // Printing Nodes
  for (auto x : m)
    cout << x.second << " ";

  return 0;
}

/*  Input: 1 2 3 4 5 -1 -1 -1 -1 -1 -1 -1
    # LEVEL ORDER INPUT
  Constructed binary tree is
           1
         /   \
       2      3
     /  \
   4     5

 *************************************************** */