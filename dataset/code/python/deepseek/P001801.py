class Solution:
    def flatten(self, root):
        if not root:
            return None
        stack = []
        stack.append(root)
        prev = None
        while stack:
            node = stack.pop()
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
            if prev:
                prev.right = node
                node.left = prev
            prev = node
        return self.firstNode

Explanation:
This problem can be solved using a Depth-First Search approach. 

First, we traverse the binary tree using a depth-first search (DFS) strategy. For each node, we first traverse its right child, then its left child. By doing so, we ensure that the right child of a node will be the next node in the doubly linked list, and the left child will be the previous node.

Then, we set the left child of the previous node to the current node and the right child of the current node to the previous node.

Lastly, we update the previous node to the current node.

This solution assumes that the input binary tree is a valid BST. 

The time complexity of this solution is O(n) as we visit each node once. 

The space complexity is O(n) as in the worst case, the tree is a linked list where each node is a stack frame.