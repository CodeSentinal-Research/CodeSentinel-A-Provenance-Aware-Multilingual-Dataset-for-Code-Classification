Here is the Python code for the given problem:

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None

def print_top_view(root):
    if root is None:
        return

    min_val = root.data
    max_val = root.data

    map_top_node = {}

    queue = [(root, 0)]
    while queue:
        current_node, hd = queue.pop(0)

        if hd not in map_top_node:
            map_top_node[hd] = current_node

        if current_node.right:
            queue.append((current_node.right, hd + 1))

        if current_node.left:
            queue.append((current_node.left, hd - 1))

    for i in sorted(map_top_node):
        print(map_top_node[i].data, end=" ")


def main():
    root = Node(4)
    root.left = Node(2)
    root.right = Node(5)
    root.left.left = Node(1)
    root.left.right = Node(3)
    root.right.left = Node(6)
    root.right.right = Node(7)

    print_top_view(root)

if __name__ == "__main__":
    main()

This code will print: `1 3 6 7`, which is the top view of the binary tree from leftmost column to rightmost column.