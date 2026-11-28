Here is the Python code for the given problem:

def get_string(node):
    if node is None:
        return ""
    left = get_string(node.left)
    right = get_string(node.right)
    return left + node.val + right

def smallest_string(root):
    return get_string(root)

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def create_tree(node_list, parent_list):
    root = TreeNode(node_list[0])
    parent_map = {node_list[0]: None}
    nodes = [root]
    i = 1
    while i < len(node_list):
        child_node = TreeNode(node_list[i])
        nodes.append(child_node)
        parent = parent_map[parent_list[i]]
        if parent is None:
            parent_map[child_node.val] = root
            root.left = child_node
        else:
            if parent.right is None:
                parent.right = child_node
            else:
                parent.left = child
            child_node.parent = parent
        i += 1
    return root

def main():
    node_list, parent_list = map(list, [iter(input().split()) for _ in range(int(input().strip()))])
    root = create_tree(node_list, parent_list)
    print(smallest_string(root))

if __name__ == '__main__':
    main()

This code firstly defines the TreeNode class and the function to create a binary tree from a list of nodes and parent nodes. It then defines the main function that reads the input, creates the binary tree and prints the smallest lexicographically string.