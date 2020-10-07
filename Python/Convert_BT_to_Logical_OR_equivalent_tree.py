# Python program to convert a given binary tree to a tree holding child's logical OR equivalent
  
# Tree node 
class newNode:  
    def __init__(self, key):  
        self.data = key  
        self.left = None
        self.right = None

def convertTree(root) : 
    if (root == None) :  
        return

    convertTree(root.left)  
   
    convertTree(root.right)  
  
    if (root.left and root.right):  
        root.data = ((root.left.data) |  
                    (root.right.data))  

# (inorder traversal for result)
def printInorder(root) :  
    if (root == None) :  
        return
    printInorder(root.left)  
    print( root.data, end = " ")  
    printInorder(root.right)  
  
# Main/Driver Code  
if __name__ == '__main__':  
      
    root = newNode(0)  
    root.left = newNode(1)  
    root.right = newNode(0)  
    root.left.left = newNode(0)  
    root.left.right = newNode(1)  
    root.right.left = newNode(1)  
    root.right.right = newNode(1)  
  
    convertTree(root)  
    printInorder(root)