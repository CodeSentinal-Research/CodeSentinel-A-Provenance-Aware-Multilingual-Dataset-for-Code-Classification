Here is the Python code for the problem:


class Solution:
    def maxWidth(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue = [(root, 0, 0)]
        min_val = root.val
        max_val = root.val
        max_width = 1
        while queue:
            node, depth, pos = queue.pop(0)
            min_val = min(min_val, node.val)
            max_val = max(max_val, node.val)
            max_width = max(max_width, pos - min_val + 1)
            if node.left:
                queue.append((node.left, depth + 1, 2 * pos))
            if node.right:
                queue.append((node.right, depth + 1, 2 * pos + 1))
        return max_width

This solution uses a Breadth-First Search (BFS) approach. We start from the root node and initialize the minimum and maximum values and width with the root value. Then, we process all nodes in the tree. For each node, we calculate the width and update our maximum width if necessary. If a node has a child, we append it to the queue with its corresponding depth and position (pos).