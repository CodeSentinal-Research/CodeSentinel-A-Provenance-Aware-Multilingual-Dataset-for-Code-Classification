class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> list:
        if not root:
            return []
        res = []

        def is_leaf(node):
            return node and not node.left and not node.right

        def add_left(node):
            cur = node.left
            while cur:
                if not is_leaf(cur):
                    res.append(cur.val)
                cur = cur.left if cur.left else cur.right

        def add_leaves(node):
            if is_leaf(node):
                res.append(node.val)
                return
            if node.left:
                add_leaves(node.left)
            if node.right:
                add_leaves(node.right)

        def add_right(node):
            cur = node.right
            st = []
            while cur:
                if not is_leaf(cur):
                    st.append(cur.val)
                cur = cur.right if cur.right else cur.left
            while st:
                res.append(st.pop())

        if not is_leaf(root):
            res.append(root.val)
        add_left(root)
        add_leaves(root)
        add_right(root)
        return res