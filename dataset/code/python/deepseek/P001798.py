Sure, here is the Python code with the main function and input handling:

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(node, key):
    if node is None:
        return Node(key)
    if key < node.val:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
    return node

def inorder(node, k):
    if node is None:
        return
    inorder(node.left, k)
    k.append(node.val)
    inorder(node.right, k)

def kthSmallest(root, k):
    k = []
    inorder(root, k)
    return k[k.index(min(k))]

def main():
    n = int(input().strip())
    root = None
    for i in range(n):
        line = input().strip().split()
        val = int(line[0])
        root = insert(root, val)
    k = int(input().strip())
    print(kthSmallest(root, k))

if __name__ == "__main__":
    main()

In this code, we first define the Node class for the binary search tree. Then, we insert nodes into the tree. After that, we use the inorder traversal to traverse the tree and store the values in a list. Finally, we return the kth smallest element in the list.