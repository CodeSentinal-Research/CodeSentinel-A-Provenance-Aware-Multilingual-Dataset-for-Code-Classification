Here is the Python code for the problem:


class Solution(object):
    def height(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        else:
            left_height = self.height(root.left)
            right_height = self.height(root.right)
            return max(left_height, right_height) + 1

In this code, we use recursive approach to calculate the height of the binary tree. For each node, we calculate the height of the left and right subtree and return the maximum of these two plus one for the root node.