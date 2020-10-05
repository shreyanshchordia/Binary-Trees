class Node:
    # initializing attributes of class using constructor, to create new node
    # __init__ is a reserved method
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    
# recursive function to find the path from root to n1 and root to n2
def find_path(self, n, path):
    if self is None:
        return False
        
    path.append(self.key)   # appending correct node to path
    if self.key == n:
        return True
        
    # to check if n is found in the right or left sub-tree
    if((self.left != None and find_path(self.left, n, path)) or (self.right != None and find_path(self.right, n, path))):
        return True
        
    # if not found, removing root from path and returning False
    path.pop()
    return False
        
# function to find the lowest common ancestor node of given two nodes
def find_lca(self, n1, n2):
    path1 = []
    path2 = []
    
    # if any of n1 or n2 doesn't exist
    if(not find_path(self, n1, path1) or not find_path(self, n2, path2)):
        return False
    
    i = 0
    # comparing paths to get the first value that differs
    while(i<len(path1) and i<len(path2)):
        if(path1[i] != path2[i]):
            break
        i+=1
    return path1[i-1]

# creating the tree
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
print("LCA(4, 2) = ",(find_lca(root, 4, 2)))
