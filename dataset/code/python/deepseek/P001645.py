Here is the Python code using Breadth-First Search (BFS) method:

from collections import deque

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def solve():
    nodes = input()
    nodes = list(map(int, nodes.split()))
    nodes_map = {x: Node(x) for x in range(1, nodes[0] + 1)}

    for i in range(nodes[0]):
        node, left, right = nodes[i * 3 + 1], nodes[i * 3 + 2], nodes[i * 3 + 3]
        if left != -1:
            nodes_map[node].left = nodes_map[left]
        if right != -1:
            nodes_map[node].right = nodes_map[right]

    queue = deque([(nodes_map[1])])
    while queue:
        node = queue.popleft()
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
        print(node.val, end=' ')

if __name__ == "__main__":
    solve()

The code first parses the input to create a binary tree. It then performs a breadth-first search (BFS) from the leftmost node. The BFS ensures that the nodes in the same row are visited in the order they appear in the tree (left to right). This is achieved by using a queue to store the nodes to be processed in order of their appearance in the tree.