
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def insert(self, root: Optional[TreeNode], val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        if val < root.val:
            root.left = self.insert(root.left, val)
        elif val > root.val:
            root.right = self.insert(root.right, val)
        return root

    def search(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root or root.val == key:
            return root
        if key < root.val:
            return self.search(root.left, key)
        return self.search(root.right, key)

    def inorder(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        return self.inorder(root.left) + [root.val] + self.inorder(root.right)
