# Python3 program for Clockwise Spiral Traversal of Binary Tree 
'''
 A spiral traversal of a binary tree considers the nodes of the tree as points 
 on the circular boundary of a spiral starting from the head to the spiral centre

 example: consider the following tree
          10  
        /    \  
       12     13  
            /    \  
           14     15  
          /  \   /  \  
        21   22 23   24  
 The traversal will go as shown below
         "10"----------->---------  
        /    \                    |
 -->--"12"->-"13"---->----        |
|           /    \        |       |
|        "14"--<-"15"--<--        |
|         /  \   /  \             |
 ----<--"21" "22""23" "24"----<---

 Following the above spiral
 The traversal would result into: 10 24 23 22 21 12 13 15 14
'''
# Making sufficiently large initializations
INT_MAX = 2**31
INT_MIN = -2**31
  
# Tree node  
class newNode:   
    def __init__(self, data):  
        self.key = data  
        self.left = None
        self.right = None
          
# Find width of tree  
def findWidth(node, maxValue, minValue, hd): 
  
    if (node == None): 
        return
  
    if (hd > maxValue[0]): 
        maxValue[0] = hd  
      
    if (hd < minValue[0]): 
        minValue[0] = hd  
  
    findWidth(node.left, maxValue, 
                         minValue, hd - 1)  
    findWidth(node.right, maxValue, 
                          minValue, hd + 1)  
  
# Function to traverse the tree and store level order traversal in a matrix  
def BFS(mtrx,node):  
    # Queue for storing addresses of nodes  
    qu = []  
  
    qu.append(node)  
  
    i = -1
    j = -1
  
    poped_node = None
  
    while (len(qu)): 
        i += 1
  
        qsize = len(qu) 
  
        while (qsize > 0): 
            qsize -= 1
            j += 1
  
            poped_node = qu[0]  
  
            # Store data of node into the matrix  
            mtrx[i][j] = poped_node.key  
            qu.pop(0)  
  
            if (poped_node.left != None): 
                qu.append(poped_node.left)  
              
            if (poped_node.right != None):  
                qu.append(poped_node.right)  
              
        j = -1
      
# Function for Clockwise Spiral Traversal of Binary Tree  
def traverse_matrix(mtrx, width): 
  
    j = 0
    k1 = 0
    k2 = 0
    k3 = width - 1
    k4 = width - 1
  
    for round in range(width // 2):  
        for j in range(k2, width):  
  
            # Only print those values which are not MAX_INTEGER  
            if (mtrx[k1][j] != INT_MAX): 
                print(mtrx[k1][j], ", ", end = "") 
        k2 = 0
        k1 += 1
  
        for j in range(k4, -1, -1): 
  
            # Only print those values which are not MAX_INTEGER  
            if (mtrx[k3][j] != INT_MAX): 
                print(mtrx[k3][j], ", ", end = "")  
          
        k4 = width - 1
        k3 -= 1
  
    # condition (one row may be left traversing)  
    # if number of rows in matrix are odd  
    if (width % 2 != 0):  
        for j in ramge(k2, width): 
  
            # Only print those values which are not MAX_INTEGER  
            if (mtrx[k1][j] != INT_MAX): 
                print(mtrx[k1][j], ", ", end = "") 

def printPattern(node):  
  
    # max, min for calculating width
    max_value = [INT_MIN]  
    min_value = [INT_MAX ] 
    hd = 0

    findWidth(node, max_value, min_value, hd)  
    width = max_value[0] + abs(min_value[0])  
   
    mtrx = [0]*width  

    for i in range(width):  
        mtrx[i] = [0] * width 
 
    for i in range(width):  
        for j in range(width):  
            mtrx[i][j] = INT_MAX  
          
    # Store the BFS traversal of the tree into the 2-D matrix  
    BFS(mtrx, node) 

    traverse_matrix(mtrx, width)  
          
# Main/Driver Code 
if __name__ == '__main__': 
      
    """    
          10  
        /    \  
       12     13  
            /    \  
           14     15  
          /  \   /  \  
        21   22 23   24  
    """
  
    root = newNode(10)  
    root.left = newNode(12)  
    root.right = newNode(13)  
  
    root.right.left = newNode(14)  
    root.right.right = newNode(15)  
  
    root.right.left.left = newNode(21)  
    root.right.left.right = newNode(22)  
    root.right.right.left = newNode(23)  
    root.right.right.right = newNode(24)  
  
    print("Circular Clockwise Spiral Traversal :")  
  
    printPattern(root) 