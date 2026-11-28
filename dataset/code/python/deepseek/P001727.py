Here is the Python code for your problem:

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def print_paths(root, path=[]):
    if root is None:
        return

    path.append(root.data)
    if root.left is None and root.right is None:
        print(' -> '.join(map(str, path)))
    else:
        print_paths(root.left, path.copy())
        print_paths(root.right, path.copy())

def main():
    N = int(input().strip())
    nodes = [Node(int(input().strip())) for _ in range(N)]
    for i in range(N):
        parent, left, right = map(int, input().strip().split())
        if left != -1:
            nodes[parent].left = nodes[left]
        if right != -1:
            nodes[parent].right = nodes[right]

    root = nodes[0]
    print_paths(root)

if __name__ == "__main__":
    main()

In this code, a Node class is created to represent each node in the binary tree. The Node class has a constructor which takes an integer data and two references to the left and right children nodes.

The `print_paths` function is a recursive function that prints all the distinct paths from the root to each leaf in the binary tree. It uses a list path to keep track of the current path and appends the data of each node to it. If the current node is a leaf node, it prints the path. Otherwise, it recursively calls `print_paths` on the left and right children.

The `main` function handles the input and builds the binary tree. It reads the number of nodes N, and then reads the nodes and their children. It sets the root of the binary tree as the first node, and then calls `print_paths` on the root.

The `main` function is the entry point of the program. It calls `main` and starts the program.