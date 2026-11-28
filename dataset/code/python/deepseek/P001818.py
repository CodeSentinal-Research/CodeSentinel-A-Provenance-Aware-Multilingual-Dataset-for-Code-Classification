Sure, here is the Python code.

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def build_tree(nodes):
    if len(nodes) == 0:
        return None

    mid = len(nodes) // 2
    root = TreeNode(nodes[mid])

    root.left = build_tree(nodes[:mid])
    root.right = build_tree(nodes[mid + 1:])

    return root

def find_LCA(root, nodes):
    if root is None:
        return None

    if root.val in nodes:
        return root

    left = find_LCA(root.left, nodes)
    right = find_LCA(root.right, nodes)

    if left and right:
        return root
    else:
        return left or right

def main():
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))[:N]
    K = int(input().strip())
    nodes_set = set(map(int, input().strip().split()))

    root = build_tree(sorted(nodes))
    lca = find_LCA(root, nodes_set)

    print(lca.val)

if __name__ == '__main__':
    main()

This code first builds a binary search tree from the given sorted array. Then it finds the lowest common ancestor of the given keys.

The `build_tree` function is a recursive function that builds the binary search tree from the given sorted array. The `find_LCA` function is a recursive function that finds the lowest common ancestor of the given keys.

In the `main` function, we first read the number of nodes, the sorted array of nodes, and the number of keys. Then we build the binary search tree and find the lowest common ancestor of the given keys. Finally, we print the value of the lowest common ancestor.