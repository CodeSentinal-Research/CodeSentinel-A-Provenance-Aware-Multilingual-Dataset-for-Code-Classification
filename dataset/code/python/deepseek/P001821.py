class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(node, data):
    if node is None:
        return Node(data)
    if data < node.data:
        node.left = insert(node.left, data)
    else:
        node.right = insert(node.right, data)
    return node

def in_order(node):
    if node is not None:
        in_order(node.left)
        print(node.data)
        in_order(node.right)

def bst_to_min_heap(root):
    if root is None:
        return

    total = root.data

    if root.right:
        total += bst_to_min_heap(root.right)

    if root.left:
        total += bst_to_min_heap(root.left)

    root.data = total

    root.left = Node(total - root.data)
    root.right = Node(total - root.data)

    if root.left:
        bst_to_min_heap(root.left)

    if root.right:
        bst_to_min_heap(root.right)

def main():
    nodes = list(map(int, input().split()))[1:]
    root = None
    for data in nodes:
        root = insert(root, data)
    bst_to_min_heap(root)
    in_order(root)

if __name__ == "__main__":
    main()

In this code, we use the concept of Tree Traversal and Heap property to convert the given BST to a Min-Heap. First, we traverse the BST in in-order (left-root-right) to get the sorted data, which is then used to convert the BST to a Min-Heap.