class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(node, data):
    if node is None:
        return Node(data)
    else:
        if node.data < data:
            node.right = insert(node.right, data)
        else:
            node.left = insert(node.left, data)
    return node

def find_deepest_left_leaf(root):
    if root is None:
        return "NONE"

    depth_dict = {}
    stack = [(root, 0)]

    while stack:
        node, depth = stack.pop()

        if node.left is not None:
            stack.append((node.left, depth + 1))

        if node.right is not None and depth + 1 not in depth_dict:
            depth_dict[depth + 1] = node.right.data

        if node.left is None and node.right is None and depth + 1 not in depth_dict:
            depth_dict[depth + 1] = node.data

    if len(depth_dict) == 0:
        return "NONE"

    return min(depth_dict, key=depth_dict.get)

def main():
    n = int(input().strip())

    root = None
    for i in range(n):
        data = int(input().strip())
        root = insert(root, data)

    print(find_deepest_left_leaf(root))

if __name__ == "__main__":
    main()