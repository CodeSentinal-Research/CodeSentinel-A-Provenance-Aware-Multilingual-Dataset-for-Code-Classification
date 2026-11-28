class Node:
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def count_paths(root, path, path_length, path_sum, is_decreasing):
    if root is None:
        return 0

    path.append(root.data)

    if (root.left is None) and (root.right is None) and path_length == 1:
        if is_decreasing:
            return 0
        return 1

    if (root.left is None) and (root.right is None) and path_length == 2:
        if is_decreasing:
            return 1
        return 0

    increasing = root.left and root.right and root.data > path[path_length-1]
    decreasing = root.left and root.right and root.data < path[path_length-1]

    if increasing and not is_decreasing:
        return count_paths(root.left, path, path_length, path_sum + root.data, False) + count_paths(root.right, path, path_length, path_sum + root.data, False)
    elif decreasing and is_decreasing:
        return count_paths(root.left, path, path_length, path_sum + root.data, True) + count_paths(root.right, path, path_length, path_sum + root.data, True)
    else:
        return count_paths(root.left, path, path_length, path_sum + root.data, is_decreasing) + count_paths(root.right, path, path_length, path_sum + root.data, is_decreasing)

def main():
    N = int(input().strip())
    nodes = [int(i) for i in input().strip().split()]
    root = None

    for i in range(len(nodes)):
        if nodes[i] == -1:
            if root is not None:
                if root.left is None:
                    root.left = Node(nodes[i])
                else:
                    root.right = Node(nodes[i])
            else:
                root = Node(nodes[i])
        else:
            if i % 2 == 0:
                if root.left is None:
                    root.left = Node(nodes[i])
                else:
                    root.right = Node(nodes[i])
            else:
                if root.left is None:
                    root.left = Node(nodes[i])
                else:
                    root.right = Node(nodes[i])

    path = []
    print(count_paths(root, path, 1, 0, False))

main()