class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:
    def serialize(self, root: TreeNode) -> str:
        vals = []

        def preorder(node):
            if not node:
                return
            vals.append(str(node.val))
            preorder(node.left)
            preorder(node.right)

        preorder(root)
        return " ".join(vals)

    def deserialize(self, data: str) -> TreeNode:
        if not data:
            return None
        vals = list(map(int, data.split()))
        idx = 0

        def build(bound):
            nonlocal idx
            if idx == len(vals) or vals[idx] > bound:
                return None
            val = vals[idx]
            idx += 1
            node = TreeNode(val)
            node.left = build(val)
            node.right = build(bound)
            return node

        return build(float('inf'))