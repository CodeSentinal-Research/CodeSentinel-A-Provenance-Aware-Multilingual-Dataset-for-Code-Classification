Here is the python code:

def find_longest_path(root):
    if not root:
        return 0

    left = find_longest_path(root.left)
    right = find_longest_path(root.right)

    max_path = max(max_path, left + right + 1)

    return max(left, right) + 1

def longest_increasing_path(root, nodes):
    max_path = 0
    for node in nodes:
        if node in [root.val, root.left.val, root.right.val, root.left.left.val, root.right.right.val]:
            max_path = max(max_path, find_longest_path(root))
    return max_path

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def build_tree(nodes):
    if not nodes:
        return None

    node = TreeNode(nodes.pop(0))
    node.left = build_tree(nodes)
    node.right = build_tree(nodes)

    return node

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))[:N]

    root = build_tree(nodes)
    print(longest_increasing_path(root, nodes))

if __name__ == "__main__":
    main()

This code first builds the binary tree from the given nodes. Then it finds the longest increasing path for each node in the list of given nodes. Finally, it prints the longest increasing path.