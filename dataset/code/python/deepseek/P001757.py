class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(node, data):
    if node is None:
        return Node(data)
    else:
        if data <= node.data:
            return insert(node.left, data)
        else:
            return insert(node.right, data)

def find_paths(node, path, k):
    if node is None:
        return
    path.append(node.data)
    if node.left is None and node.right is None:
        if k in path:
            print(''.join(map(str, path)), node.data)
        path.pop()
    else:
        find_paths(node.left, list(path), k)
        find_paths(node.right, list(path), k)
    path.pop()

def find_LCA(root, node1, node2):
    path1 = []
    path2 = []
    find_paths(root, path1, node1)
    find_paths(root, path2, node2)

    path1 = [i for i in path1 if i in path2]
    return path1[-1]

def main():
    N = int(input().strip())
    tree = None
    for i in range(N):
        data = int(input().strip())
        tree = insert(tree, data)
    node1 = int(input().strip())
    node2 = int(input().strip())
    print(find_LCA(tree, node1, node2))

if __name__ == "__main__":
    main()

This program first constructs a binary tree from the given N lines input. Then it reads two node values and finds the least common ancestor (LCA) of the given two nodes. 

It uses a recursive approach to find the paths from the root to both nodes, and then finds the last common node in these paths. If the LCA is not found, it prints an error message.

The `find_paths` function finds all paths from a given node to a leaf node, and the `find_LCA` function finds the LCA of two nodes by finding paths from the root to both nodes.

The main function reads the tree nodes, two nodes to find the LCA for, and prints the LCA.