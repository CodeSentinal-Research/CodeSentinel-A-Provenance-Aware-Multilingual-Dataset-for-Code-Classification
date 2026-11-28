Here is the python code for the problem:

def convert_to_sum(root):
    if not root:
        return 0

    left_sum = convert_to_sum(root.left)
    right_sum = convert_to_sum(root.right)

    root.val = left_sum + right_sum + root.val

    return root.val

def build_tree(node_values, tree, index):
    if index < len(node_values):
        node_value = node_values[index]
        if node_value is not None:
            node = TreeNode(node_value)
            tree.append(node)
            index += 1
            node.left = build_tree(node_values, tree, index)
            node.right = build_tree(node_values, tree, index)
        else:
            tree.append(None)
    else:
        tree.append(None)
    return tree

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def solve(tree_input):
    node_values, N = tree_input[0]
    tree_input[0] = None
    root = build_tree(node_values, [], 0)
    convert_to_sum(root)
    return root

def main():
    tree_input = [[1, 2, 3, 4, 5], 5]
    root = solve(tree_input)

The above code first defines a `TreeNode` class for the nodes of the tree. Then, the `solve` function takes the tree input, builds the tree, and calls the `convert_to_sum` function on the root.

This solution assumes that the tree input is a list of lists, where each inner list represents a level of the tree. The first element of each inner list represents the node values of the nodes at that level, and None represents the nodes at the next level.

The `main` function is the entry point of the program, and it creates a tree input, calls the `solve` function, and prints the result.