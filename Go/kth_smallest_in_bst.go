package main

import (
	"fmt"
)

/*
 * Problem :: Find Kth Smallest Element in Binary Search Tree
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
 * functions to find kth smallest node as inorder traversal of binary search tree
 * gives us all the nodes sorted in ascending order we will keep on tracking the index
 * when index is equal to K, we have the answer
 */

func solve(root *TreeNode, K, idx, ans *int) {
	if root == nil {
		return
	}
	solve(root.Left, K, idx, ans)
	*idx++
	if *idx == *K {
		*ans = root.Val
	}
	solve(root.Right, K, idx, ans)
}

func kthSmallestInBST(root *TreeNode, K int) int {
	ans := -1
	idx := 0
	solve(root, &K, &idx, &ans)
	return ans
}

func main() {
	/**
	 *  Test-case to check correctness
	 *		       5
	 *		      / \
	 *		     3   6
	 *		    / \
	 *		   2   4
	 *		  /
	 *		 1
	 *
	 *    2nd Smallest = 2
	 *    4th Smallest = 4
	 */

	node1 := TreeNode{Val: 1, Left: nil, Right: nil}
	node4 := TreeNode{Val: 4, Left: nil, Right: nil}
	node6 := TreeNode{Val: 6, Left: nil, Right: nil}

	node2 := TreeNode{Val: 2, Left: &node1, Right: nil}
	node3 := TreeNode{Val: 3, Left: &node2, Right: &node4}
	node5 := TreeNode{Val: 5, Left: &node3, Right: &node6}

	root := &node5

	fmt.Printf("2nd Smallest = %d\n", kthSmallestInBST(root, 2))
	fmt.Printf("4th Smallest = %d\n", kthSmallestInBST(root, 9))
}
