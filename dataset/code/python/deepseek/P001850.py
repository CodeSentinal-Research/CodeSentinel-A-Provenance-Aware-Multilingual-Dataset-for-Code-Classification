Here is the Python code for your problem:

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def add_node(root, data):
    if root is None:
        return Node(data)
    else:
        if root.data < data:
            root.right = add_node(root.right, data)
        else:
            root.left = add_node(root.left, data)
    return root

def maxWidth(root):
    if root is None:
        return 0

    queue = deque([(root, 0)])
    current_level = max_level = queue[0][1]
    leftmost_node_at_current_level = queue[0][0].data
    while queue:
        if current_level > max_level:
            max_level = current_level
            leftmost_node_at_current_level = queue[0][0].data
        if current_level == max_level:
            if queue[0][0].data != leftmost_node_at_current_level:
                leftmost_node_at_current_level = queue[0][0].data
            if queue[0][0].left is not None:
                queue.append((queue[0][0].left, current_level + 1))
            if queue[0][0].right is not None:
                queue.append((queue[0][0].right, current_level + 1))
        current_level = queue[0][1]
        queue.popleft()

    return leftmost_node_at_current_level

def main():
    N = int(input())
    root = None
    for i in range(N):
        data = int(input())
        root = add_node(root, data)
    print(maxWidth(root))

if __name__ == '__main__':
    main()
This Python code first defines a Node class for the nodes of the BST. It then defines a function to add nodes to the BST. The `maxWidth` function performs level order traversal of the BST and calculates the maximum width.

The main function reads the number of nodes, and then reads the data of each node. It then constructs the BST and calls the `maxWidth` function to print the maximum width of the BST.