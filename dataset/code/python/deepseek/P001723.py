Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def find_max_sum(root):
    if not root:
        return 0

    if not root.left and not root.right:
        return root.val

    return root.val + max(find_max_sum(root.left), find_max_sum(root.right))

def main():
    N = int(input().strip())

    nodes = list(map(int, input().strip().split()))
    tree = [Node(nodes[i]) for i in range(N)]

    for i in range(N):
        left_child = None
        right_child = None

        if 2 * i + 1 < N:
            left_child = tree[2 * i + 1]

        if 2 * i + 2 < N:
            right_child = tree[2 * i + 2]

        tree[i].left = left_child
        tree[i].right = right_child

    max_sum = find_max_sum(tree[0])

    print(max_sum)

if __name__ == "__main__":
    main()

In this code, we first define a Node class to represent each node in the tree. Then, we define a function `find_max_sum(root)` that recursively calculates the maximum sum of all nodes in a binary tree.

In the `main()` function, we first read the number of nodes, then the node values. We then create a list of Node objects from the node values, and connect each node with its children using a tree representation. Finally, we call `find_max_sum(tree[0])` to find the maximum sum of all nodes in the tree and print it.