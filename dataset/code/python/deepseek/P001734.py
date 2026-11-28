Here is the Python code:


class Solution:
    def solve(self, node):
        if node is None:
            return 0

        left_sum = self.solve(node.left)
        right_sum = self.solve(node.right)

        self.node.val = left_sum + right_sum

        return self.node.val

    def bstToGst(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.node = root
        self.solve(root)

        return root

This code first defines the TreeNode class as follows:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

The Solution class is defined with a solve method that recursively calculates the sum of all nodes in a tree. The bstToGst method first sets the root of the tree as the current node, then calls the solve method.

The main function is then defined, which takes a root node and prints the transformed tree.