// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.

class Solution
{
public:
    int mctFromLeafValues(vector<int> &A)
    {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A)
        {
            while (stack.back() <= a)
            {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i)
        {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};