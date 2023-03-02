/* 
Function for inverting binary tree's using javascript

invert is done through recursion

to invert the whole tree, call the function on the root node, root node cannot be null
*/

function invert(node) {
    place = node.left;
    node.left = node.right;
    node.right = place;

    if(node.left != null) invert(node.left);
    if(node.right != null) invert(node.right);
}

