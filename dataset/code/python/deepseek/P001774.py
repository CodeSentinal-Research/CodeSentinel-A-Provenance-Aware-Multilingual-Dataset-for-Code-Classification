Here is a Python solution using Level Order Traversal to count the distinct node values at every level.

from collections import deque

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def count_distinct_values_at_every_level(root):
    if not root:
        return

    queue = deque([root])
    levels = {}

    while queue:
        level = queue.popleft()
        if level in levels:
            levels[level] += 1
        else:
            levels[level] = 1

        if level.left:
            queue.append(level.left)
        if level.right:
            queue.append(level.right)

    for level, count in levels.items():
        print(count)

def create_binary_tree(node_values):
    if not node_values:
        return None

    root = Node(node_values.pop(0))
    current_nodes = [root]
    while node_values:
        new_nodes = []
        for node in current_nodes:
            if node_values:
                node.left = Node(node_values.pop(0))
                new_nodes.append(node.left)
            if node_values:
                node.right = Node(node_values.pop(0))
                new_nodes.append(node.right)
        current_nodes = new_nodes
    return root

node_values = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
input()  
root = create_binary_tree(list(map(int, input().split())))
count_distinct_values_at_every_level(root)

In this code, the `count_distinct_values_at_every_level` function uses a Breadth-First Search (BFS) to traverse the binary tree level by level. At each level, it increments a dictionary `levels` with the number of distinct node values at that level. The `create_binary_tree` function is used to create the binary tree from the given node values.