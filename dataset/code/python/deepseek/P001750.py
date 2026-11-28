Here is the Python code for your problem. This code will read the number of nodes and their levels from input, create a binary tree from these nodes and then find the level with the minimum number of nodes.

class Node:
    def __init__(self, data, level=0):
        self.data = data
        self.left = None
        self.right = None
        self.level = level

def create_tree(nodes_info):
    nodes = [None if val == 'x' else Node(val) for val in nodes_info]
    levels = [[] for _ in range(len(nodes))]
    root_level = 0
    for i, val in enumerate(nodes):
        if val is not None:
            node = val
            node.level = levels[i % len(levels)]
            levels[i % len(levels)].append(node)
            if i < len(nodes) // 2:
                node.left = nodes[i * 2 + 1]
                node.right = nodes[i * 2 + 2]
            else:
                root_level = i
    return levels[root_level][0]

def min_nodes_level(n, nodes_info):
    root = create_tree(nodes_info)
    min_level = root.level
    min_nodes = len(root.level)
    for node in root.level:
        if len(node.level) < min_nodes:
            min_nodes = len(node.level)
            min_level = node.level
        elif len(node.level) == min_nodes and node.level[0] < min_level[0]:
            min_level = node.level
    return min_level[0] + 1

def main():
    n = int(input().strip())
    nodes_info = input().strip().split()
    print(min_nodes_level(n, nodes_info))

if __name__ == "__main__":
    main()

This code first reads the number of nodes and their levels from the input. Then it creates a binary tree from these nodes using a helper function `create_tree`. This function returns the root of the binary tree.

Then it calls the function `min_nodes_level` to find the level with the minimum number of nodes. This function first finds the level with the smallest number of nodes, then compares this level with the previous minimum. If the current level has fewer nodes, it updates the minimum and the minimum level. If the current level has the same number of nodes as the previous minimum, but the current level is smaller than the previous minimum, it updates the minimum level.

Finally, it prints the level with the minimum number of nodes.