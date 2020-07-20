
class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None

class Tree:
    def __init__(self):

        self.root = None
    
    def add(self, x):

        if self.root == None:

            self.root = Node(x)
            return

        else:
            prev = None
            temp = self.root

            while temp != None:
                if x > temp.data:
                    prev = temp
                    temp = temp.right
                
                elif x < temp.data:
                    prev = temp
                    temp = temp.left
            
            if x > prev.data:
                new = Node(x)
                prev.right = new
            
            else:
                new = Node(x)
                prev.left = new
        
        return
    
    def inorderUtil(self, root):
        if root == None:
            return 
        else:
            self.inorderUtil(root.left)
            print(root.data)
            self.inorderUtil(root.right)
        return

    def inorder(self):
        temp = self.root
        self.inorderUtil(temp)
        return

    def PreorderUtil(self, root):
        if root == None:
            return 
        else:
            print(root.data)
            self.PreorderUtil(root.left)
            self.PreorderUtil(root.right)
        return
        
    def Preorder(self):
        temp = self.root
        self.PreorderUtil(temp)
        return

    def PostorderUtil(self, root):
        if root == None:
            return 
        else:
            self.PostorderUtil(root.left)
            self.PostorderUtil(root.right)
            print(root.data)
        return
        
    def Postorder(self):
        temp = self.root
        self.PostorderUtil(temp)
        return


tree = Tree()

tree.add(3)
tree.inorder()
tree.add(4)
tree.add(1)
tree.add(7)
tree.add(2)
tree.inorder()
tree.Preorder()
tree.Postorder()

