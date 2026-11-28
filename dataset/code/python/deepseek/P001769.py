from collections import deque

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(nodes, index, n):
    if index > n:
        return None
    node = Node(nodes[index])
    node.left = construct_tree(nodes, 2 * index, n)
    node.right = construct_tree(nodes, 2 * index + 1, n)
    return node

def bfs(root):
    if not root:
        return
    queue = deque([root])
    while queue:
        node = queue.popleft()
        print(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

def find_min_at_each_level(nodes, n):
    root = construct_tree(nodes, 1, n)
    bfs(root)

find_min_at_each_level([1, 2, 3, 4, 5, 6, 7], 6)