Here's the python code for the problem. The code first reads the input for the first binary search tree and then for the second binary search tree. It then merges the two binary search trees.

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def insert_in_bst(node, key):
    if node is None:
        return Node(key)
    if key < node.key:
        node.left = insert_in_bst(node.left, key)
    else:
        node.right = insert_in_bst(node.right, key)
    return node


def inorder(node, res):
    if node is not None:
        inorder(node.left, res)
        res.append(node.key)
        inorder(node.right, res)


def merge_bst(node1, node2):
    res = []
    inorder(node1, res)
    for i in res:
        node1 = insert_in_bst(node1, i)
    inorder(node2, res)
    for i in res:
        node2 = insert_in_bst(node2, i)
    return node1, node2


def main():
    N1 = int(input().strip())
    node1 = None
    for i in range(N1):
        key = int(input().strip())
        node1 = insert_in_bst(node1, key)
    N2 = int(input().strip())
    node2 = None
    for i in range(N2):
        key = int(input().strip())
        node2 = insert_in_bst(node2, key)
    node1, node2 = merge_bst(node1, node2)
    print('Merged BST:')
    inorder(node1, res)
    for i in res:
        print(i, end=' ')
    print()


if __name__ == '__main__':
    main()

In the `main` function, the first part reads the first binary search tree and then the second binary search tree. The `merge_bst` function merges the two binary search trees. The `inorder` function is used to print the inorder traversal of the merged binary search tree.