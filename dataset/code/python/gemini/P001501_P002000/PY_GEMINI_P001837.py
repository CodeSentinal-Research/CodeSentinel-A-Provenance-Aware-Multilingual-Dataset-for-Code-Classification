class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTReverseIterator:
    def __init__(self, root: TreeNode):
        self.stack = []
        self._push_right(root)

    def _push_right(self, node):
        while node:
            self.stack.append(node)
            node = node.right

    def next(self) -> int:
        node = self.stack.pop()
        self._push_right(node.left)
        return node.val

    def hasNext(self) -> bool:
        return len(self.stack) > 0