Here is a Python solution for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def bottom_view(root):
    if root is None:
        return

    queue = []
    map = {}

    queue.append((root, 0))

    while queue:
        node, column = queue.pop(0)

        if node is not None:
            queue.append((node.left, column-1))
            queue.append((node.right, column+1))

            if column not in map or node.data < map[column][0]:
                map[column] = (node.data, node.data)

    for i in sorted(map):
        print(map[i][1], end=' ')

def build_tree(nodes, root, i, n):
    if i < n:
        root = Node(nodes[i])
        root.left = build_tree(nodes, root.left, 2 * i + 1, n)
        root.right = build_tree(nodes, root.right, 2 * i + 2, n)
    return root

def main():
    nodes = list(map(int, input().split()))[1:]
    n = len(nodes)

    root = None
    root = build_tree(nodes, root, 0, n)

    bottom_view(root)

if __name__ == "__main__":
    main()

In this solution, we use a Breadth-first search (BFS) approach. We store the nodes in a queue and also a dictionary to store the nodes in each column. The dictionary is used to get the nodes in the bottom view in sorted order of the columns.