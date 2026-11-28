class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert_node(node, data):
    if node is None:
        return Node(data)
    else:
        if data <= node.data:
            node.left = insert_node(node.left, data)
        else:
            node.right = insert_node(node.right, data)
    return node

def delete_leaves(node, x):
    if node is None:
        return None
    else:
        if node.left is None and node.right is None:
            if node.data == x:
                return None
            else:
                return node
        else:
            node.left = delete_leaves(node.left, x)
            node.right = delete_leaves(node.right, x)
            return node

def build_tree(nodes, data):
    if data is None:
        return None
    node = insert_node(None, data)
    for d in nodes:
        insert_node(node, d)
    return node

def print_tree(node):
    if node is None:
        return
    print_tree(node.left)
    print(node.data)
    print_tree(node.right)

def main():
    nodes = list(map(int, input().split()))[1:]
    x = int(input().strip())
    root = build_tree(nodes, None)
    while True:
        leaf = delete_leaves(root, x)
        if leaf is None:
            break
        root = leaf
    print_tree(root)

if __name__ == "__main__":
    main()
This program reads the number of nodes, the node values, and the value to delete from the input, and then constructs a binary tree from these values. It then repeatedly deletes the leaf nodes with the given value until there are no more leaf nodes left. Finally, it prints the resulting tree.