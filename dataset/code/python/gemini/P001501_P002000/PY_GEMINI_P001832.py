from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []

        def build(start, end):
            if start > end:
                return [None]
            all_trees = []
            for i in range(start, end + 1):
                left_trees = build(start, i - 1)
                right_trees = build(i + 1, end)
                for l in left_trees:
                    for r in right_trees:
                        cur = TreeNode(i)
                        cur.left = l
                        cur.right = r
                        all_trees.append(cur)
            return all_trees

        return build(1, n)