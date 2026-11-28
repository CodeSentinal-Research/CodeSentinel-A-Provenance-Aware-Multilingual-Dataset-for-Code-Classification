Here is the Python code for the problem:

from collections import defaultdict

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def add_node(nodes, node_dict, node_id):
    if node_id in nodes:
        return
    nodes.append(node_id)
    node_dict[node_id] = TreeNode(node_id)

def create_tree(nodes_list, node_dict, node_id, left_child, right_child):
    if left_child is None and right_child is None:
        return
    node_dict[node_id].left = left_child
    node_dict[node_id].right = right_child
    if left_child is not None:
        add_node(nodes_list, node_dict, left_child)
    if right_child is not None:
        add_node(nodes_list, node_dict, right_child)

def solve(node_ids, nodes, node_dict, node_values):
    diagonal_sums = defaultdict(int)
    for node_id in node_ids:
        i = node_dict[node_id].val
        diagonal_sums[i] += node_values[node_id]
        if i - 1 in nodes:
            diagonal_sums[i - 1] -= node_values[node_id]
        if i + 1 in nodes:
            diagonal_sums[i + 1] += node_values[node_id]
    for i in sorted(diagonal_sums.keys()):
        print(diagonal_sums[i])

def main():
    N = int(input().strip())
    node_values = [int(input().strip()) for _ in range(N)]
    nodes = [int(input().strip()) for _ in range(N)]
    node_dict = {}
    nodes_list = []
    for node_id in nodes:
        add_node(nodes_list, node_dict, node_id)
    for node_id in nodes:
        create_tree(nodes_list, node_dict, node_id, nodes[2 * node_id - 1], nodes[2 * node_id - 2])
    solve(nodes_list, set(nodes_list), node_dict, node_values)

if __name__ == '__main__':
    main()

This code first reads the number of nodes and the node values from the input. Then it reads the binary tree from the input. After that, it calls the solve function to print the sum of node values on every anti-diagonal.