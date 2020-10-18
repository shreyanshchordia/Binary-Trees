using System;

namespace BinaryTreeNode
{
    public class BinaryTreeOperations
    {
        public static void OperationsOnBinaryTree()
        {
            BinaryTree tree = new BinaryTree();
            tree.root = new Node(8);
            tree.root.left = new Node(6);
            tree.root.left.left = new Node(5);
            tree.root.left.right = new Node(7);


            tree.root.right = new Node(11);
            tree.root.right.left = new Node(10);
            tree.root.right.right = new Node (15);
            tree.root.right.right.right = new Node(20);

            var minimumDepth = tree.FindMinimumDepthOfBinarySearchTree(tree.root, 0);
        }
    }

    public class BinaryTree
    {
        public Node root;
                
        /// <summary>
        /// Returns minimum depth of Binary Tree.
        /// </summary>
        /// <returns>Returns the minimum depth of the Binary tree from the root</returns>
        public int FindMinimumDepthOfBinarySearchTree(Node node, int level)
        {
            if (node == null)
            {
                return level;
            }
            else
            {
                var left = FindMinimumDepthOfBinarySearchTree(node.left, level+1);
                var right = FindMinimumDepthOfBinarySearchTree(node.right, level+1);

                return Math.Min(left, right);
            }
        }

        public static int Height(Node node)
        {
            if (node == null) return 0;
 
            return 1 + Math.Max(Height(node.left), Height(node.right));
        }

        public static bool NodeToLeafPathSum(Node node, int sum)
        {
            if(node == null)
            {
                return sum == 0;
            }
            else
            {
                bool ans = false;
                int subsum = sum - node.data;
                if (node.left == null && node.right == null && subsum == 0)
                {
                    return true;
                }
                
                if(node.left != null)
                {
                    ans = ans || NodeToLeafPathSum(node.left, subsum);
                }

                if (node.right != null)
                {
                    ans = ans || NodeToLeafPathSum(node.right, subsum);
                }

                return ans;
            }
        }
    }

    public class Node
    {
        public int data;
        public Node left,right;
        public Node(int d)
        {
            data = d;
        }
    }
}