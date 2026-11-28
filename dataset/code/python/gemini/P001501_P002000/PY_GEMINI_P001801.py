class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def treeToDoublyList(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        head = prev = None

        def inorder(node):
            nonlocal head, prev
            if not node:
                return
            inorder(node.left)
            if head is None:
                head = node
            else:
                prev.right = node
                node.left = prev
            prev = node
            inorder(node.right)

        inorder(root)
        prev.right = head
        head.left = prev
        return head