from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def replaceValueInTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        dq = deque([root])
        root.val = 0

        while dq:
            size = len(dq)
            level_sum = 0
            cur_nodes = list(dq)
            for node in cur_nodes:
                if node.left: level_sum += node.left.val
                if node.right: level_sum += node.right.val

            for _ in range(size):
                node = dq.popleft()
                sibling_sum = (node.left.val if node.left else 0) + (node.right.val if node.right else 0)
                if node.left:
                    node.left.val = level_sum - sibling_sum
                    dq.append(node.left)
                if node.right:
                    node.right.val = level_sum - sibling_sum
                    dq.append(node.right)

        return root