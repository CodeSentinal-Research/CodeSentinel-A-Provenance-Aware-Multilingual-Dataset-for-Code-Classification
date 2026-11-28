Here is the Python code for finding the minimum value in a binary search tree.


class Solution:
    def findMin(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return None
        
        current = root
        while current.left is not None:
            current = current.left
        
        return current.val

This code works by traversing the leftmost node in the BST. As soon as we find a node with no left child, the minimum value is returned.

For the input handling, we can use the following Python code:

if __name__ == "__main__":
    nodes = [int(n) for n in input().split()]
    root = None
    nodes_stack = []
    for val in nodes:
        node = TreeNode(val)
        if root is None:
            root = node
        else:
            nodes_stack.append(node)
        while len(nodes_stack) > 0:
            top = nodes_stack[-1]
            if top.left is None or top.left.val > val:
                top.left = node
                break
            nodes_stack.pop()
    print(Solution().findMin(root).val)

This Python code reads the number of nodes in the BST, then the values of the nodes. It creates a binary tree from these values. The root of the tree is then passed to the `findMin` function to find and print the minimum value. The `findMin` function works the same way as the previous code.