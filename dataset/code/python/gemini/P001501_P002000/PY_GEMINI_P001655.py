class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def treeToDoublyList(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        self.first = self.last = None

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            if self.last:
                self.last.right = node
                node.left = self.last
            else:
                self.first = node
            self.last = node
            inorder(node.right)

        inorder(root)
        self.last.right = self.first
        self.first.left = self.last
        return self.first