
# Data structure to store a Binary Search Tree node
class Node:
	def __init__(self, data, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right


# Recursive function to insert a key into BST
def insert(root, key):

	# if the root is None, create a node and return it
	if root is None:
		return Node(key)

	# if given key is less than the root node, recur for left subtree
	if key < root.data:
		root.left = insert(root.left, key)

	# if given key is more than the root node, recur for right subtree
	else:
		root.right = insert(root.right, key)

	return root


# Function to find k'th smallest element in BST
# Here i denotes the number of nodes processed so far
def kthSmallest(root, i, k):

	# base case
	if root is None:
		return float('inf'), i

	# search in left subtree
	left, i = kthSmallest(root.left, i, k)

	# if k'th smallest is found in left subtree, return it
	if left != float('inf'):
		return left, i

	i = i + 1

	# if current element is k'th smallest, return its value
	if i == k:
		return root.data, i

	# else search in right subtree
	return kthSmallest(root.right, i, k)


# Function to find k'th smallest element in BST
def findKthSmallest(root, k):

	# maintain index to count number of nodes processed so far
	i = 0

	# traverse the tree in in-order fashion and return k'th element
	return kthSmallest(root, i, k)[0]


if __name__ == '__main__':

	root = None
	keys = [15, 10, 20, 8, 12, 16, 25]

	for key in keys:
		root = insert(root, key)

	k = 2
	res = findKthSmallest(root, k)

	if res != float('inf'):
		print(res)
	else:
		print("Invalid Input")
