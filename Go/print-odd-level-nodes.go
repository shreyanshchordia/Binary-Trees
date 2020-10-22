package main

import (
	"fmt"
)

/*
 * Problem :: Print the odd level nodes of binary tree
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
	if _, ok := levelMapper[level]; !ok && level%2 == 1 {
		levelMapper[level] = make([]int, 0)
	}
	if level%2 == 1 {
		// If it's odd level add it to answer
		levelMapper[level] = append(levelMapper[level], root.Val)
	}
	createLevelMap(root.Left, level+1, levelMapper)
	createLevelMap(root.Right, level+1, levelMapper)
}

/*
 * function to return Odd Level Nodes of binary tree:-
 *   - Create tree view in level order manner and store odd level nodes info
 */

func oddLevelNodeOfBinaryTree(root *TreeNode) [][]int {
	levelMapper := make(map[int][]int)
	createLevelMap(root, 1, levelMapper)
	ans := make([][]int, 0)
	for id := range levelMapper {
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
	 *  Odd Level Nodes := [[1], [4, 8, 10]]
	 */

	node6 := TreeNode{Val: 10, Left: nil, Right: nil}
	node5 := TreeNode{Val: 8, Left: nil, Right: nil}
	node4 := TreeNode{Val: 4, Left: nil, Right: nil}
	node3 := TreeNode{Val: 3, Left: nil, Right: &node6}
	node2 := TreeNode{Val: 2, Left: &node4, Right: &node5}
	root := &TreeNode{Val: 1, Left: &node2, Right: &node3}

	fmt.Printf("%v\n", oddLevelNodeOfBinaryTree(root))
}
