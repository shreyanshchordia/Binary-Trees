package main

import (
	"fmt"
)

/*
 * Problem :: Print the binary tree in zigZag manner
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
 * functions to find nodes at various level
 * our map will store list of nodes at each level
 */

func createLevelMap(root *TreeNode, level int, levelMapper map[int][]int) {
	if root == nil {
		return
	}
	if _, ok := levelMapper[level]; !ok {
		levelMapper[level] = make([]int, 0)
	}
	levelMapper[level] = append(levelMapper[level], root.Val)
	createLevelMap(root.Left, level+1, levelMapper)
	createLevelMap(root.Right, level+1, levelMapper)
}

func reverseArray(array []int) {
	for left, right := 0, len(array)-1; left < right; left, right = left+1, right-1 {
		array[left], array[right] = array[right], array[left]
	}
}

/*
 * function to return zigZagTraversal of binary tree
 * 1) Create tree view in level order manner
 * 2) Reverse alternate levels value
 */

func zigZagTraversal(root *TreeNode) [][]int {
	levelMapper := make(map[int][]int)
	createLevelMap(root, 0, levelMapper)
	ans := make([][]int, 0)
	for id := range levelMapper {
		if id%2 == 1 {
			reverseArray(levelMapper[id])
		}
		ans = append(ans, levelMapper[id])
	}
	return ans
}

func main() {
	/**
	 *  Test-case to check correctness
	 *               1
	 *              / \
	 *             2   3
	 *            / \   \
	 *           4  8   10
	 *  ZigZag Traversal := [[1], [3, 2], [4, 8, 10]]
	 */

	node6 := TreeNode{Val: 10, Left: nil, Right: nil}
	node5 := TreeNode{Val: 8, Left: nil, Right: nil}
	node4 := TreeNode{Val: 4, Left: nil, Right: nil}
	node3 := TreeNode{Val: 3, Left: nil, Right: &node6}
	node2 := TreeNode{Val: 2, Left: &node4, Right: &node5}
	root := &TreeNode{Val: 1, Left: &node2, Right: &node3}

	fmt.Printf("%v\n", zigZagTraversal(root))
}
