package main

import (
	"fmt"
)

/*
 * Problem :: The maximum depth is the number of nodes along the longest path
 *			  from the root node down to the farthest leaf node.
 */


/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/**
 * function to find max-depth-of-binary-tree
 * go to left tree then right tree and return maximum height out of them
 */

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	count := 1 + Max(maxDepth(root.Left), maxDepth(root.Right))
	return count
}

func Max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}

func main() {
	/**
	 *  Test-case to check correctness
	 *               1
	 *              / \
	 *             2   3
	 *            /
	 *           4
	 *  Longest Path from root to leaf is [1-2-4] i.e length 3
	 */
	node4 := TreeNode{Val: 4, Left: nil, Right: nil}
	node3 := TreeNode{Val: 3, Left: nil, Right: nil}
	node2 := TreeNode{Val: 2, Left: &node4, Right: nil}
	root := &TreeNode{Val: 1, Left: &node2, Right: &node3}

	fmt.Printf("Answer: %d", maxDepth(root))
}
