class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def flatten(root):
    if not root:
        return
    stack = [root]
    while stack:
        node = stack.pop()
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
        if stack:
            node.right = stack[-1]
            stack[-1].left = node
        node.left = None

def print_list(head):
    while head:
        print(head.val)
        head = head.right

def create_tree(nodes):
    node_values = [nodes[i] for i in range(len(nodes)) if nodes[i] is not None]
    if not node_values:
        return None
    nodes = [Node(val) for val in node_values]
    for i in range(len(nodes)):
        if 2*i+1 < len(nodes_values):
            nodes[i].left = nodes[2*i+1]
        if 2*i+2 < len(nodes_values):
            nodes[i].right = nodes[2*i+2]
    return nodes[0]

def main():
    nodes = [1, 2, 5, 3, 4, None, 6]
    root = create_tree(nodes)
    flatten(root)
    print_list(root)

if __name__ == "__main__":
    main()

In this Python code, we are first defining a Node class for the binary tree. A Node object has a value, and references to its left and right children.

Then, the `flatten` function is implemented. This function takes a binary tree root as input and performs the preorder traversal to flatten the tree. It uses a stack to keep track of the nodes to be processed. In each iteration of the loop, the current node is popped from the stack, and its right child is added to the stack. After that, its left child is added if it exists. The last node in the stack (which is the right child of the last node processed) is set as the right child of the current node.

The `print_list` function is used to print the flattened list of nodes.

The `create_tree` function is used to create the binary tree from the given list of nodes.

The main function is the entry point of the program. It creates a binary tree from the given list of nodes, flattens the tree, and prints the list of nodes.