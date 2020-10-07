# Python program to convert a Binary Tree to CDLL 
# The order is same as it's inorder traversal
  
# Tree node 
class Node:  
    def __init__(self, data):  
        self.data = data  
        self.left = self.right = None
  
v = [] 
  
# Here vector v stores the inorder traversal for the CDLL 
def inorder(root): 
    global v   
    if (root == None): 
        return  
    inorder(root.left)   
    v.append(root.data)  
    inorder(root.right) 
  
def bTreeToCList(root): 
  
    global v 

    if (root == None): 
        return None

    v = [] 

    inorder(root) 
  
    # Create the head of the linked list pointing to the root of the tree 
    head_ref = Node(v[0]) 
  
    # Create a current pointer to be used in traversal 
    curr = head_ref 
  
    i = 1
  
    while ( i < len(v)) : 

        # Create a temporary pointer pointing to current 
        temp = curr 
  
        # Current's right points to the current node in traversal 
        curr.right = Node(v[i]) 
  
        # Current points to its right 
        curr = curr.right 
  
        # Current's left points to temp 
        curr.left = temp 
        i = i + 1
  
    # Current's right points to head of the list 
    curr.right = head_ref 
  
    # Head's left points to current 
    head_ref.left = curr 
  
    # Return head of the list 
    return head_ref 

def displayCList(head): 
  
    print("Circular Doubly Linked List is :", end = "") 
  
    itr = head 
    while(True): 
        print(itr.data, end = " ") 
        itr = itr.right 
        if(head == itr): 
            break
    print() 
  
# Main/Driver Code 
root = Node(10) 
root.left = Node(12) 
root.right = Node(15) 
root.left.left = Node(25) 
root.left.right = Node(30) 
root.right.left = Node(36) 
  
head = bTreeToCList(root) 
displayCList(head)