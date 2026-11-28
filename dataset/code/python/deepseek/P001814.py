Here is a Python solution using the approach of in-order traversal. It first traverses the first binary search tree (BST1) in an in-order manner, and then the second BST (BST2) in another in-order manner. For each pair of keys, it calculates their sum and compares it with the current minimum sum. If the sum of the current pair is less than the minimum sum, it updates the minimum sum and the pair of keys.

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(node, key):
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node

def inorder(node, keys):
    if node is None:
        return

    inorder(node.left, keys)
    keys.append(node.key)
    inorder(node.right, keys)

def closest_pair(tree1, tree2, x):
    min_diff = float('inf')
    min_keys = []

    keys1 = []
    inorder(tree1, keys1)

    keys2 = []
    inorder(tree2, keys2)

    i, j = 0, len(keys2) - 1

    while i < len(keys1) and j >= 0:
        sum = keys1[i] + keys2[j]

        if abs(x - sum) < min_diff:
            min_diff = abs(x - sum)
            min_keys = [keys1[i], keys2[j]]

        if sum < x:
            i += 1
        else:
            j -= 1

    return min_keys

def main():
    N1 = int(input().strip())
    tree1 = None
    for _ in range(N1):
        key = int(input().strip())
        tree1 = insert(tree1, key)

    N2 = int(input().strip())
    tree2 = None
    for _ in range(N2):
        key = int(input().strip())
        tree2 = insert(tree2, key)

    x = int(input().strip())

    pair = closest_pair(tree1, tree2, x)

    print(' '.join(map(str, pair)))

if __name__ == "__main__":
    main()

In this code, `Node` represents a node in the binary search tree. The `insert` function is used to insert a key into the BST. The `inorder` function is used to traverse the BST in an in-order manner and store the keys. The `closest_pair` function is the main function that calculates the closest pair of keys to a target sum. The `main` function reads the input and calls the `closest_pair` function.