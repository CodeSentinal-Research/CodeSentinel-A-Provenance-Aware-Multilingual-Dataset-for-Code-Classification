Here is a Python solution using the Breadth-First Search (BFS) algorithm for the problem:

from collections import deque

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def printTopView(root):
    if root is None:
        return

    queue = deque()
    map_line = dict()

    queue.append((root, 0))

    while len(queue) > 0:
        node_val, line_no = queue.popleft()

        if line_no not in map_line:
            map_line[line_no] = node_val

        if node_val.left is not None:
            queue.append((node_val.left, line_no - 1))

        if node_val.right is not None:
            queue.append((node_val.right, line_no + 1))

    for i in sorted(map_line.keys()):
        print(map_line[i].data, end=" ")

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    print("Following is the Breadth First Traversal (left to right) top view of the binary tree:")
    printTopView(root)

if __name__ == "__main__":
    main()

In this code, we use a Breadth-First Search (BFS) approach to traverse the binary tree. We keep track of the horizontal line (or column) that each node is on, and only add the node to the list if it is on a different line. The BFS ensures that we add nodes from left to right until we reach the top view. 

Please note that the tree in the example provided here is a binary tree with three levels. It can be any valid binary tree.