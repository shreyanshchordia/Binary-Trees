# Maximum difference between node and its ancestor  

# Taking sufficiently large initializations
_MIN = -2147483648
_MAX = 2147483648
  
# Tree node                                      
class newNode: 
    def __init__(self, key):  
        self.key = key 
        self.left = None
        self.right = None
  
"""   
 This function recursively updates value at 'res' to store the result.
 The returned value of this function is minimum value in subtree rooted with 't'
"""
def maxDiffUtil(t, res): 
  
# (one child case)
    if (t == None): 
        return _MAX, res 
  
# (leaf node case)
    if (t.left == None and t.right == None): 
        return t.key, res 
  
    # Recursively calling left and right subtree for minimum value
    a, res = maxDiffUtil(t.left, res) 
    b, res = maxDiffUtil(t.right, res) 
    val = min(a, b) 

    res = max(res, t.key - val) 
      
    """ Returning minimum value got so far """
    return min(val, t.key), res 

def maxDiff(root): 
  
    # Initialising result with minimum value 
    res = _MIN 
    x, res = maxDiffUtil(root, res) 
    return res 
  
# (print inorder traversal)
def inorder(root): 
  
    if (root): 
      
        inorder(root.left) 
        prf("%d ", root.key) 
        inorder(root.right) 
      
# Main/Driver Code  
if __name__ == '__main__': 

    root = newNode(8) 
    root.left = newNode(3) 
  
    root.left.left = newNode(1) 
    root.left.right = newNode(6) 
    root.left.right.left = newNode(4) 
    root.left.right.right = newNode(7) 
  
    root.right = newNode(10) 
    root.right.right = newNode(14) 
    root.right.right.left = newNode(13) 
    print("Maximum difference between a node and", 
          "its ancestor is :", maxDiff(root))