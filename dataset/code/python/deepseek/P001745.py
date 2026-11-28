Sure, here is the Python code:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def build_tree(nodes):
    if nodes[0] is None:
        return None

    root = Node(nodes[0])
    nodes.pop(0)

    queue = [root]
    while len(queue) > 0:
        current_node = queue.pop(0)

        if nodes[0] is not None:
            current_node.left = Node(nodes[0])
            queue.append(current_node.left)
            nodes.pop(0)
        if nodes[0] is not None:
            current_node.right = Node(nodes[0])
            queue.append(current_node.right)
            nodes.pop(0)

        if len(queue) == 0:
            break

    return root

def height(root):
    if root is None:
        return 0

    left_height = height(root.left)
    right_height = height(root.right)

    if left_height > right_height:
        return left_height + 1
    else:
        return right_height + 1

def solve(nodes):
    root = build_tree(nodes)
    return height(root)

if __name__ == "__main__":
    N = int(input().strip())
    nodes = list(map(int, input().strip().split()))
    print(solve(nodes))

This code reads the input and constructs the binary tree. The height of a node is calculated by recursively calling the height function on the left and right children of the node, and taking the maximum of the two plus one for the node itself.