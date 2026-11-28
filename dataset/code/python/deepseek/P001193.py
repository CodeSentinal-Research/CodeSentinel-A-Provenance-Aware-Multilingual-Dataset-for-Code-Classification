Here is the Python code for the House Robber III problem:

def rob(root):
    if not root:
        return (0, 0)

    left = rob(root.left)
    right = rob(root.right)

    rob_root = root.val + \
               (left[0] + right[0] if root.left else 0) + \
               (left[1] + right[1] if root.right else 0)

    not_rob_root = left[0] + right[0]

    return (max(rob_root, not_rob_root), not_rob_root)

def solve(tree):
    result = rob(tree)
    print(max(result))

if __name__ == '__main__':


This code assumes that a `TreeNode` class has been defined as follows:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def build_tree(nodes):
    nodes_dict = {i: TreeNode(val) for i, val in enumerate(nodes)}
    for i, node in nodes_dict.items():
        if i in nodes[:2]:
            node.left = nodes_dict[nodes[2*i + 1]]
            node.right = nodes_dict[nodes[2*i + 2]]
    return nodes_dict[0]

The `solve` function calls `rob` function to get the maximum obtainable amount, which is the maximum value of two non-adjacent houses.

You can use it like this:

if __name__ == '__main__':
    N = int(input())
    for _ in range(N):
        line = list(map(int, input().split()))
        tree = build_tree(line)
    solve(tree)

This code works by using depth-first search to traverse the tree and find the maximum obtainable amount at each node. It uses a tuple (max_rob, max_not_rob) to store the maximum obtainable amount for two non-adjacent houses at the current node.