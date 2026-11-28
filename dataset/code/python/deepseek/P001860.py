Here's the Python code to construct a Binary Search Tree from an Ancestor Matrix:

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def construct_bst(ancestors):
    parent = dict(ancestors)
    nodes = {i: Node(i) for i in range(len(ancestors))}
    root = None

    for node, ancestor in nodes.items():
        if ancestor.key == -1:
            root = nodes[node]
        else:
            if ancestor.key in nodes:
                if ancestor.key == ancestors[ancestor.key]:
                    ancestor.left = nodes[node]
                else:
                    ancestor.right = nodes[node]
            else:
                ancestor.left = nodes[node]

    return root


def main():
    N = int(input().strip())
    ancestors = [int(input().strip()) for _ in range(N)]

    if -1 in ancestors:
        print("IMPOSSIBLE")
    else:
        root = construct_bst(ancestors)
        print_bst(root)


def print_bst(node, indent=''):
    if node:
        print(indent + str(node.key))
        print_bst(node.left, indent + '--')
        print_bst(node.right, indent + '--')


if __name__ == "__main__":
    main()

This code first reads the number of nodes N and the ancestor matrix. Then it constructs the binary search tree from the ancestor matrix. If the ancestor matrix contains -1, it means that the node does not have an ancestor, so the tree is a single node tree. Otherwise, it prints the reconstructed tree.