Sure, here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(nodes, index):
    if index < len(nodes) and nodes[index] is not None:
        node = Node(nodes[index])
        node.left = construct_tree(nodes, 2 * index + 1)
        node.right = construct_tree(nodes, 2 * index + 2)
        return node
    return None

def find_rightmost_deepest_node(root):
    if root is None:
        return None
    stack = [(root, False)]
    rightmost_node = None
    while stack:
        node, is_left = stack.pop()
        if node.right is not None:
            stack.append((node.right, True))
        if node.left is not None:
            stack.append((node.left, False))
        if node.right is None and node.left is None and not is_left:
            rightmost_node = node
    return rightmost_node.val

def main():
    nodes = [None] * 100000  
    for i in range(10):
        nodes[i] = Node(i)
    nodes[2].left = Node(5)
    nodes[2].right = Node(6)
    nodes[5].left = Node(7)
    nodes[5].right = Node(8)
    nodes[6].left = Node(9)
    nodes[6].right = Node(10)
    nodes[10].left = Node(11)

    root = construct_tree(nodes, 0)
    print(find_rightmost_deepest_node(root))

if __name__ == "__main__":
    main()
This code first constructs the binary tree based on the input. Then it uses a depth-first search to find the rightmost deepest node. The depth-first search uses a stack to keep track of the nodes to be processed. The stack is popped one by one and all the left and right children of the popped node are pushed into the stack. When the node is leftmost, it is updated as the rightmost node.