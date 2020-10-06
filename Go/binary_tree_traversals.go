package main

import (
	"fmt"
)

/*
 * Problem :: Print the binary tree using following traversal
 *	           1) InOrder
 *             2) PreOrder
 *             3) PostOrder
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
 * functions to print various traversal for binary tree
 * each functions returns array containing preferred order
 */

func inOrder(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	array := make([]int, 0)
	array = append(array, inOrder(root.Left)...)
	array = append(array, root.Val)
	array = append(array, inOrder(root.Right)...)
	return array
}

func preOrder(root *TreeNode) []int{
	array := make([]int, 0)
	if root == nil {
		return array
	}
	array = append(array, root.Val)
	array = append(array, preOrder(root.Left)...)
	array = append(array, preOrder(root.Right)...)
	return array
}

func postOrder(root *TreeNode) []int {
	array := make([]int, 0)
	if root == nil {
		return array
	}
	array = append(array, postOrder(root.Left)...)
	array = append(array, postOrder(root.Right)...)
	array = append(array, root.Val)
	return array
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

	fmt.Printf("InOrder: %v\n", inOrder(root))
	fmt.Printf("PreOrder: %v\n", preOrder(root))
	fmt.Printf("PostOrder: %v\n", postOrder(root))
}
