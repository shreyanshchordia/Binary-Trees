import Foundation

class TreeNode<T> {
    
    var data: T
    var leftNode: TreeNode?
    var rightNode: TreeNode?
    
    init(data: T,
        leftNode: TreeNode? = nil,
        rightNode: TreeNode? = nil) {
        self.data = data
        self.leftNode = leftNode
        self.rightNode = rightNode
    }
}

class BinarySearchTree<T: Comparable & CustomStringConvertible> {
    
    private var rootNode: TreeNode<T>?
    
    func insert(element: T) {
        let node = TreeNode(data: element)
        if let rootNode = self.rootNode {
            self.insert(rootNode, node)
        } else {
            self.rootNode = node
        }
    }
    
    // RECURSIVE FUNCTION
    private func insert(_ rootNode: TreeNode<T>, _ node: TreeNode<T>) {
        if rootNode.data > node.data {
            if let leftNode = rootNode.leftNode {
                self.insert(leftNode, node)
            } else {
                rootNode.leftNode = node
            }
        } else {
            if let rightNode = rootNode.rightNode {
                self.insert(rightNode, node)
            } else {
                rootNode.rightNode = node
            }
        }
    }
    
    func traverse() {
        print("\nPRE-ORDER TRAVERSAL")
        self.preorder(self.rootNode)
        print("\n\nIN-ORDER TRAVERSAL")
        self.inorder(self.rootNode)
        print("\n\nPOST-ORDER TRAVERSAL")
        self.postorder(self.rootNode)
        print("\n")
    }
    
    // LNR : LEFT NODE RIGHT
    private func inorder(_ node: TreeNode<T>?) {
        guard let _ = node else { return }
        self.inorder(node?.leftNode)
        print("\(node!.data)", terminator: " ")
        self.inorder(node?.rightNode)
    }
    
    // NLR : NODE LEFT RIGHT
    private func preorder(_ node: TreeNode<T>?) {
        guard let _ = node else { return }
        print("\(node!.data)", terminator: " ")
        self.preorder(node?.leftNode)
        self.preorder(node?.rightNode)
    }
    
    // LRN :  LEFT RIGHT NODE
    private func postorder(_ node: TreeNode<T>?) {
        guard let _ = node else { return }
        self.postorder(node?.leftNode)
        self.postorder(node?.rightNode)
        print("\(node!.data)", terminator: " ")
    }
}

let bst = BinarySearchTree<String>()

bst.insert(element: "F")
bst.insert(element: "G")
bst.insert(element: "H")
bst.insert(element: "D")
bst.insert(element: "E")
bst.insert(element: "I")
bst.insert(element: "J")
bst.insert(element: "A")
bst.insert(element: "B")
bst.insert(element: "C")

bst.traverse()

