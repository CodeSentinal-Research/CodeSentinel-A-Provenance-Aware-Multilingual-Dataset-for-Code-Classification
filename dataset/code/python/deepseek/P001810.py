Here is a Python solution for the problem:

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def solve(root, cumulative_sum):
    if root is None:
        return

    solve(root.left, cumulative_sum)

    root.val = cumulative_sum[0]
    cumulative_sum[0] += root.val

    solve(root.right, cumulative_sum)


def construct_tree(nodes):
    value_map = {val: i for i, val in enumerate(nodes[::-1])}

    root = None
    cumulative_sum = [0]

    for i in range(len(nodes)):
        if nodes[i] is not None:
            node = Node(value_map[nodes[i]])
            if i % 2 == 1:
                nodes[i - 1].right = node
            else:
                nodes[i - 1].left = node
            if i % 2 == 1 and i != len(nodes) - 1:
                nodes[i - 1] = None
            if i == 0:
                root = node

    solve(root, cumulative_sum)

    return root


def print_pre_order(root):
    if root is None:
        return
    print(root.val, end=' ')
    print_pre_order(root.left)
    print_pre_order(root.right)


def main():
    n = int(input().strip())
    nodes = list(map(int, input().strip().split()))[:n]
    root = construct_tree(nodes)
    print_pre_order(root)


if __name__ == "__main__":
    main()

This code first reads the number of nodes, and then the nodes themselves. It then constructs the BST using the `construct_tree` function. The `print_pre_order` function is used to print the values of the BST in pre-order (Root, Left, Right). The `main` function is the entry point of the program.