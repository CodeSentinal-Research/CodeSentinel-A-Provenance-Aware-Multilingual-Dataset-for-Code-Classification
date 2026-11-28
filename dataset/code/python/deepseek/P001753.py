Here is a Python code to solve the problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(lines):
    root = None
    for line in lines:
        if line == '-1':
            node = None
        else:
            node = Node(int(line))
            if root is None:
                root = node
            else:
                parent = None
                for parent in root.left, root.right:
                    if node.data < parent.data:
                        if parent.left is None:
                            parent.left = node
                            break
                        else:
                            parent = parent.left
                    else:
                        if parent.right is None:
                            parent.right = node
                            break
                        else:
                            parent = parent.right
    return root

def find_lowest_internal_node(root):
    if root.left is None and root.right is None:
        return root

    if root.left is not None and root.right is None:
        left_lowest_node = find_lowest_internal_node(root.left)
        if left_lowest_node.left is None and left_lowest_node.right is None:
            return left_lowest_node
        else:
            return find_lowest_internal_node(left_lowest_node.left if left_lowest_node.left is not None else left_lowest_node.right)

    else:
        return find_lowest_internal_node(root.right)

def main():
    N = int(input().strip())
    lines = [input().strip() for _ in range(N)]
    root = build_tree(lines)
    lowest_internal_node = find_lowest_internal_node(root)
    print(lowest_internal_node.data)

if __name__ == "__main__":
    main()

In the above code, we first define a Node class to represent each node in the binary tree. Then we define a function `build_tree` to create the binary tree from the input lines. The function takes a list of lines as input, and for each line, if the line is '-1', it sets the corresponding node to `None`, otherwise, it creates a node with the given data.

The function `find_lowest_internal_node` is used to find the leftmost node that is not a leaf node. If the leftmost node has no child, then the leftmost node is returned. Otherwise, we recursively call `find_lowest_internal_node` on the left child of the leftmost node.

In the `main` function, we first read the number of nodes N from the input. Then we read the lines of the input. We create the binary tree using the `build_tree` function, and then find the leftmost node that is not a leaf node using the `find_lowest_internal_node` function. Finally, we print the data of the found node.