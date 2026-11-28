Here is the python code for the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def merge_trees(tree1, tree2):
    if not tree1 and not tree2:
        return None
    elif not tree2:
        return tree1
    elif not tree1:
        return tree2
    else:
        node = Node(tree1.data + tree2.data)
        node.left = merge_trees(tree1.left, tree2.left)
        node.right = merge_trees(tree1.right, tree2.right)
        return node


def build_tree(lines):
    data = lines.pop(0)
    if data == 'N':
        return None
    node = Node(int(data))
    node.left = build_tree(lines)
    node.right = build_tree(lines)
    return node


def main():
    tree1_lines = [line.strip() for line in open('tree1.txt', 'r').readlines()]
    tree2_lines = [line.strip() for line in open('tree2.txt', 'r').readlines()]
    tree1 = build_tree(tree1_lines)
    tree2 = build_tree(tree2_lines)
    merged_tree = merge_trees(tree1, tree2)


if __name__ == '__main__':
    main()

In this code, we define a class `Node` to represent a node in the binary tree, and a function `merge_trees` to merge two trees. The `build_tree` function reads a tree from a file, and the `main` function reads the trees from two files, builds the trees, merges the trees, and prints the merged tree.

Please note that the code assumes that you have two files, `tree1.txt` and `tree2.txt`, where each file contains the nodes of the first and second tree, respectively. The nodes are separated by space and each line of the file represents a node. The 'N' at the start of a line represents a None node.