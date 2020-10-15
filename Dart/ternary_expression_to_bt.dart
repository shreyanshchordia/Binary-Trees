/* 
Given a string that contains ternary expressions. The expressions may be nested, task is convert the given ternary expression to a binary Tree.

Examples:

Input :  string expression =   a?b:c 
Output :        c

          a

                b
                

Input : expression =  a?b?c:d
Output :         

          a
                      c
                b     
                      d
*/


import 'dart:io';

void main() {
  String exp = "a?b:c";
  BinaryTree tree = new BinaryTree();
  Node root = tree.convertExpression(exp, 0);
  tree.print2D(root); 
}


// Class to represent the binary nodes
class Node {
  String data;
  Node left, right;

  Node(String item) {
    data = item;
    left = null;
    right = null;
  }
}

// Class to contain functions to 
class BinaryTree {
  
  // no of spaces between the no.
  static final int COUNT = 10;

  // to convert ternary operation in binary treea and returning the node
  Node convertExpression(String expression, int i) {
    if (i >= expression.length) {
      return null;
    }
    Node root =  Node(expression[i]);

    i++;

    if (i < expression.length && expression[i] == '?') {
        root.left = convertExpression(expression, i + 1);
    } 
    
    if (i+2 < expression.length && expression[i+2]==':')
        root.right = convertExpression(expression, i + 3);
    return root;
  }


  static void print2DUtil(Node root, int space)  
  {  
    
    if (root == null)  
        return;  
   
    space += COUNT;  
  
    print2DUtil(root.right, space);  
  
    stdout.write("\n");  

    for (int i = COUNT; i < space; i++)  
        stdout.write(" "); 

    stdout.write(root.data + "\n");

    print2DUtil(root.left, space);  
  } 

  void print2D(Node root)  
  {  
      // Passing initial space count as 0  
      print2DUtil(root, 0);  
  } 
}

