Here is the Python code for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def build_tree(lines):
    node_map = {}
    for line in lines:
        node, left, right = line.split()
        if node not in node_map:
            node_map[node] = Node(node)
        if left != 'NONE':
            node_map[node].left = Node(left)
        if right != 'NONE':
            node_map[node].right = Node(right)
    root = next(iter(node_map))
    return root, node_map


def find_path(node_map, node1, node2):
    path1 = [node1]
    path2 = [node2]

    parent_map = {node1: None}

    while len(path1) > 0 and len(path2) > 0:
        node = path1.pop()
        if node in node_map:
            path1.append(node_map[node].left)
            path1.append(node_map[node].right)
        parent_map[node_map[node].left] = node
        parent_map[node_map[node].right] = node

        node = path2.pop()
        if node in node_map:
            path2.append(node_map[node].left)
            path2.append(node_map[node].right)
        parent_map[node_map[node].left] = node
        parent_map[node_map[node].right] = node

    path1_nodes = [node for node in path1[1:]]
    path2_nodes = [node for node in path2[1:]]

    path1_edges = len(path1_nodes)
    path2_edges = len(path2_nodes)

    return path1_edges, path2_edges


def main():
    lines = []
    n = int(input())
    for _ in range(n):
        line = input()
        lines.append(line)
    node1, node_map = build_tree(lines)
    node2, _ = build_tree(lines)
    edges = find_path(node_map, node1, node2)
    print(min(edges))


if __name__ == '__main__':
    main()

This code first builds the tree from the input lines. Then, it finds the shortest path between two nodes in the tree. It counts the number of edges in the path and prints the minimum of the two counts.

Please note that this code assumes that the tree is a binary tree. If the tree is a general tree, you will need to modify the code to handle this.