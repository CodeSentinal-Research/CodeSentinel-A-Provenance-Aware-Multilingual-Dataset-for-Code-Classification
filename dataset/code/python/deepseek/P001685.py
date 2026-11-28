Here is the Python code:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(lines):
    if not lines[0]:
        return None
    nodes = {int(x): Node(int(x)) for x in lines[1]}
    for i, node in nodes.items():
        if lines[3+i*2] and nodes[int(lines[3+i*2])].left is None:
            node.left = nodes[int(lines[3+i*2])]
        if lines[3+i*2+1] and nodes[int(lines[3+i*2+1])].right is None:
            node.right = nodes[int(lines[3+i*2+1])]
    return nodes[int(lines[2])]

def find_successor(root, target):
    if root is None:
        return None
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node.val == target:
            if node.right:
                return node.right
            else:
                return None
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    return None

def main():
    lines = [int(x) for x in input().split()]
    n = lines[0]
    tree = construct_tree(lines[1:])
    target = lines[n+1]
    successor = find_successor(tree, target)
    if successor is None:
        print("None")
    else:
        print(successor.val)

if __name__ == "__main__":
    main()

In this code, we first define a Node class to create a node with a value and left and right children. We then construct the tree from the input lines, and find the successor of a target node. The main function reads the number of nodes and the tree and the target node, constructs the tree and finds the successor of the target node.