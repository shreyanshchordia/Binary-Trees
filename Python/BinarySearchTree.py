class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None

class Tree:
    def __init__(self):

        self.root = None
    
    def add(self, x):
    
        #If there is no root node present, the value added will be the root node. 
        if self.root == None:

            self.root = Node(x)
            return

        else: 
            # Set up a recursive function that begins from the root node.
            prev = None
            temp = self.root

            # Repeat the recursive function until there is no more children, then assign the input value into the child node. 
            while temp != None:
                # If x is bigger than the current node, it will go towards the right. 
                if x > temp.data:
                    # The currentNode will be the right child, and the input value will be then compared to the new currentNode.
                    prev = temp
                    temp = temp.right
                
                # If x is smaller than the current node, it will go towards the left. 
                elif x < temp.data:
                    prev = temp
                    temp = temp.left
                
                # If x is a repeated value, it will break the while loop and feedback to the user that it is a repeat. 
                else:
                    print("Your input value", x, "is a repeated input value.")
                    break
            
            # Assign the input value into the right child if the input value is bigger than the previous parent child
            if x > prev.data:
                new = Node(x)
                prev.right = new
            
            # Assign the input value into the left child if the input value is smaller than the previous parent child
            else:
                new = Node(x)
                prev.left = new
        
        return
    
    # Create a recursive, helper function for the following function.
    def inorderUtil(self, root):
        if root == None:
            return 
        else:
            # The function will go to the left most child, before going to the right child (that belongs to the same parent)
            self.inorderUtil(root.left)
            print(root.data)
            self.inorderUtil(root.right)
        return

    # The inorder function will output the values in an ascending order
    def inorder(self):
        temp = self.root
        self.inorderUtil(temp)
        return

    # Create a recursive, helper function for the following function.
    def PreorderUtil(self, root):
        if root == None:
            return 
        else:
            print(root.data)
            self.PreorderUtil(root.left)
            self.PreorderUtil(root.right)
        return
        
    # The Preoder function will output the values from top down of the binary tree, outputting the left child/branch first. 
    def Preorder(self):
        temp = self.root
        self.PreorderUtil(temp)
        return

    # Create a recursive, helper function for the following function.
    def PostorderUtil(self, root):
        if root == None:
            return 
        else:
            self.PostorderUtil(root.left)
            self.PostorderUtil(root.right)
            print(root.data)
        return
    
    # The Postorder function will output the values from bottom up of the binary tree, outputting the right child/branch first. 
    def Postorder(self):
        temp = self.root
        self.PostorderUtil(temp)
        return


tree = Tree()

tree.add(3)
# tree.inorder()
tree.add(4)
tree.add(1)
tree.add(7)
tree.add(2)
tree.add(2)
tree.add(7)
tree.add(6)
tree.add(8)
# tree.inorder()
# tree.Preorder()
tree.Postorder()
