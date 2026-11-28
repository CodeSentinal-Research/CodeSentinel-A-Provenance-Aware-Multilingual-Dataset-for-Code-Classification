from collections import deque

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def bottom_view(root):
    if root is None:
        return []

    queue = deque()
    queue.append((root, 0))
    bottom_view = []

    while queue:
        current_node, column = queue.popleft()
        if current_node.left:
            queue.append((current_node.left, column - 1))
        if current_node.right:
            queue.append((current_node.right, column + 1))
        bottom_view.append((column, current_node.data))

    bottom_view.sort(key=lambda x: x[0])

    return [node.data for node, column in bottom_view]

def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    print(bottom_view(root))

if __name__ == "__main__":
    main()