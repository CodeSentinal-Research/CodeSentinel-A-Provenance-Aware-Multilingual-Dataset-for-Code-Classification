Sure, below is the Python code using BFS approach to solve this problem:

from collections import deque, defaultdict

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def verticalOrder(root):
    if not root:
        return []

    column_dict = defaultdict(list)
    queue = deque([(root, 0)])

    while queue:
        node, column = queue.popleft()

        column_dict[column].append(node.val)

        if node.left:
            queue.append((node.left, column - 1))
        if node.right:
            queue.append((node.right, column + 1))

    return [column_dict[column] for column in sorted(column_dict.keys())]

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

print(verticalOrder(root))  

This code first creates a queue for BFS, and a dictionary to store the nodes in each column. The queue is initialized with the root node and its column index as 0.

The while loop continues until the queue is empty. It dequeues a node, appends its value to the column index list in the dictionary, and appends its left and right children to the queue (with their column index decreased and increased by 1).

Finally, it returns a list of sorted keys in the dictionary, which represents the vertical columns, and the corresponding node values.