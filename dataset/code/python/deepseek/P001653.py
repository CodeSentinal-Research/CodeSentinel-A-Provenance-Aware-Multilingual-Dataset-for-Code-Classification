Here is the Python code for the problem:

def maxPathSum(root):
    def helper(node):
        if not node:
            return 0
        left = max(0, helper(node.left))
        right = max(0, helper(node.right))
        self.res = max(self.res, left + right + node.val)
        return max(left, right) + node.val

    self.res = float('-inf')
    helper(root)
    return self.res

The helper function is a recursive function which calculates the maximum path sum ending at the current node. It returns the maximum path sum that can be achieved by taking a path from the left or the right child. The result is then updated with the maximum of the current value and the sum of left and right children paths plus the current node's value.

The `self.res` variable is used to store the maximum path sum found so far. When the recursive function `helper()` is called for the first time (i.e., for the root of the tree), `self.res` is initially set to negative infinity.

The main function is used to initialize the `self.res` variable and call the helper function with the root node. The result will be stored in `self.res` and returned.

The input to the main function is a binary tree represented as a list of nodes, where each node is a tuple containing the node's value and the indices of its children in the list. This is not handled here, as the input is not given in the problem statement.