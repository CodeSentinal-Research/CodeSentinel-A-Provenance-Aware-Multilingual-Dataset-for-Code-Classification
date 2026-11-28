Here is a Python code that implements the problem:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def insert_level(root, x, d):
    if d == 1:
        node = TreeNode(x)
        node.left = root
        return node
    else:
        q = [(root, 1)]
        while q:
            node, depth = q.pop(0)
            if depth + 1 == d:
                new_node = TreeNode(x)
                new_node.left = node.right
                node.right = new_node
            else:
                if node.left:
                    q.append((node.left, depth + 1))
                if node.right:
                    q.append((node.right, depth + 1))
        return root

def build_tree(lines):
    x = int(lines[0])
    lines.pop(0)
    values = list(map(int, lines))
    tree = [TreeNode(v) for v in values]
    for i in range(x):
        tree[i].left = tree[i * 2 + 1]
        tree[i].right = tree[i * 2 + 2]
    return tree[0]

def main():
    lines = [int(line) for line in input().split()]
    N, D = lines[0], lines[1]
    lines.pop(0)
    root = build_tree(lines)
    x, d = lines
    new_root = insert_level(root, x, d)
    for node in new_root.in_order():
        print(node.val)

if __name__ == "__main__":
    main()

This code defines a binary tree node and a function to insert a new level into the binary tree. The `insert_level` function uses a breadth-first search (BFS) to insert a new level into the tree. It starts at the root node and processes each node layer by layer. When it reaches the depth D to insert a new level, it creates a new node with value X and links it to the right child of the parent node.

The `build_tree` function builds a binary tree from a list of values. It assumes that the tree is a complete binary tree, and that the values are stored in a list.

The `main` function reads the input, builds the tree, inserts a new level into the tree, and prints the values of the modified tree.