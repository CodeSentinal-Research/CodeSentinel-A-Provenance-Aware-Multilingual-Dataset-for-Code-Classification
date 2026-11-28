class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def boundaryOfBinaryTreeClockwise(self, root: TreeNode) -> list:
        if not root:
            return []
        res = []

        def is_leaf(node):
            return node and not node.left and not node.right

        def add_right(node):
            cur = node.right
            while cur:
                if not is_leaf(cur):
                    res.append(cur.val)
                cur = cur.right if cur.right else cur.left

        def add_leaves_rev(node):
            if is_leaf(node):
                res.append(node.val)
                return
            if node.right: add_leaves_rev(node.right)
            if node.left: add_leaves_rev(node.left)

        def add_left(node):
            cur = node.left
            st = []
            while cur:
                if not is_leaf(cur):
                    st.append(cur.val)
                cur = cur.left if cur.left else cur.right
            while st:
                res.append(st.pop())

        if not is_leaf(root):
            res.append(root.val)
        add_right(root)
        add_leaves_rev(root)
        add_left(root)
        return res