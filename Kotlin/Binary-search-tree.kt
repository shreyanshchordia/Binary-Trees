/**
 * program will create Binary search tree from given inputs and print them
 in Postorder, Preorder and inorder in kotlin.

 *  Binary search tree is a binary tree in which node having child at left is
 less than node and child at right is higher than node.

 * Postorder - (Left, Right, Root)
 * Preorder - (Root, Left, Right)
 * Inorder -  (Left, Root, Right)
 */


class Node(
    var key: Int,
    var left: Node? = null,
    var right: Node? = null){

    /* this method will insert node in BST*/
    fun insert(value: Int) {
        if (value > this.key) {
            if (this.right == null) {
                this.right = Node(value)
            } else {
                this.right!!.insert(value)
            }
        } else if (value < this.key) {
            if (this.left == null) {
                this.left = Node(value)
            } else {
                this.left!!.insert(value)
            }
        }
    }

    /* this method will print tree in postorder*/
    fun postOrderPrint(){
        this.left?.postOrderPrint()
        this.right?.postOrderPrint()
        print(this.key.toString()+" ")
    }

    /* this method will print tree in preorder*/
    fun preOrderPrint(){
        print(this.key.toString()+" ")
        this.left?.preOrderPrint()
        this.right?.preOrderPrint()
    }

    /* this method will print tree in inorder*/
    fun inOrderPrint(){
        this.left?.inOrderPrint()
        print(this.key.toString()+" ")
        this.right?.inOrderPrint()
    }
}


fun main(args: Array<String>){

    println("Enter Nodes to create Binary Search Tree - ")

    val keys = readLine()!!.split(' ').run { IntArray(size) { get(it).toInt() } } // read nodes from input

    var tree : Node? = null

    for (key in keys) {
        if (tree == null) {
            tree = Node(key)
        }else{
            tree.insert(key)
        }
    }

    println("Preorder of tree - ")
    tree?.postOrderPrint()
    println("")

    println("Pretorder of tree - ")
    tree?.preOrderPrint()
    println("")

    println("inorder of tree - ")
    tree?.inOrderPrint()
    println("")

}