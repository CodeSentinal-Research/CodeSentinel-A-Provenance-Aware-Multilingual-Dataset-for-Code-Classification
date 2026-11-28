Here's the Python code:

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def find_predecessor(root, target):
    queue = deque([(root, False)])
    prev_data = None

    while queue:
        node, is_left = queue.popleft()

        if node.data == target:
            if not queue and not is_left:
                return prev_data
            else:
                for next_node, is_next_left in queue:
                    if is_next_left:
                        prev_data = node.data
                    node = next_node

def build_tree(lines):
    root = None
    for line in lines:
        node_data = line[0]
        node = Node(node_data)

        if root is None:
            root = node
        else:
            if node_data < root.data:
                root.left = node
            else:
                root.right = node

    return root

def handle_input():
    N = int(input().strip())
    lines = []

    for _ in range(N):
        line = input().strip().split(' ')
        lines.append(line)

    target = int(input().strip())

    root = build_tree(lines)
    predecessor = find_predecessor(root, target)

    print(predecessor)

def main():
    handle_input()

if __name__ == "__main__":
    main()

This code first builds the binary tree from the input lines. Then it finds the predecessor of the target node in level order traversal. The predecessor is found by checking the left child of the current node if it exists and then going to the left child of the left child of the current node, and so on until the end of the tree. If the target node is the right child of the current node, it means the right child of the left child of the current node is the predecessor.