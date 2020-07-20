
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


def deleteHalfNodesUtil(tree, prev, connect, root):
    if (root.left== None and root.right == None):
        return

    if (root.left == None and root.right != None):
        if prev == None:
            tree.root = root.right
            deleteHalfNodesUtil(tree, None, 'left', root.right)

        elif connect == 'left':
            prev.left = root.right
            deleteHalfNodesUtil(tree, prev, 'left', root.right)
        else:
            prev.right = root.right
            deleteHalfNodesUtil(tree, prev, 'right', root.right)

    elif (root.left != None and root.right == None):
        if prev == None:
            tree.root = root.left
            deleteHalfNodesUtil(tree, None, 'left', root.left)
            
        elif connect == 'left':
            prev.left = root.left
            deleteHalfNodesUtil(tree, prev, 'left', root.left)
        else:
            prev.right = root.left
            deleteHalfNodesUtil(tree, prev, 'right', root.left)
    
    else:
        deleteHalfNodesUtil(tree, root, 'left', root.left)
        deleteHalfNodesUtil(tree, root, 'right', root.right)
        return


def deleteHalfNodes(tree):
    prev = None
    connect = 'left'
    root = tree.root
    deleteHalfNodesUtil(tree, prev, connect, root)


tree = Tree()

tree.add(3)
tree.add(5)
tree.add(6)
tree.add(4)
tree.add(7)
tree.inorder()
tree.Preorder()
tree.Postorder()
deleteHalfNodes(tree)
tree.inorder()
