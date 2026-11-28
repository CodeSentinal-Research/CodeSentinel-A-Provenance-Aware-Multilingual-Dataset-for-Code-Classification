Here's a Python solution for the problem:

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert(node, value):
    if node is None:
        return Node(value)
    else:
        if node.value < value:
            node.right = insert(node.right, value)
        else:
            node.left = insert(node.left, value)
    return node

def find_largest_smaller(root, x):
    if root is None:
        return None

    if root.value < x and root.right is None:
        return None

    if root.value < x:
        return find_largest_smaller(root.right, x)
    else:
        return find_largest_smaller(root.left, x)

def main():
    n = int(input().strip())
    values = list(map(int, [input().strip() for _ in range(n)]))
    x = values[-1]
    values = values[:-1]

    root = None
    for value in values:
        root = insert(root, value)

    largest_smaller = find_largest_smaller(root, x)
    print(largest_smaller if largest_smaller else 'None')

if __name__ == '__main__':
    main()

This code first reads the number of nodes and the values of the nodes from the input. Then, for each node, it is inserted into the binary search tree. Finally, it finds the largest key smaller than the given value and prints it. If no such key exists, it prints 'None'.