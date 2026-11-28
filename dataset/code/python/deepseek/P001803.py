Here is the python code:

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def sorted_array_to_bst(arr):
    if not arr:
        return None
    mid = len(arr) // 2
    root = Node(arr[mid])
    root.left = sorted_array_to_bst(arr[:mid])
    root.right = sorted_array_to_bst(arr[mid+1:])
    return root

def merge_bsts(root1, root2):
    arr1 = in_order_traversal(root1)
    arr2 = in_order_traversal(root2)
    merged_arr = arr1 + arr2
    return sorted_array_to_bst(merged_arr)

def in_order_traversal(root, arr=[]):
    if root:
        in_order_traversal(root.left, arr)
        arr.append(root.key)
        in_order_traversal(root.right, arr)
    return arr

def pre_order_traversal(root, arr=[]):
    if root:
        arr.append(root.key)
        pre_order_traversal(root.left, arr)
        pre_order_traversal(root.right, arr)
    return arr

def post_order_traversal(root, arr=[]):
    if root:
        post_order_traversal(root.left, arr)
        post_order_traversal(root.right, arr)
        arr.append(root.key)
    return arr

def print_tree(root):
    if root:
        print_tree(root.left)
        print(root.key, end=' ')
        print_tree(root.right)

def main():
    root1 = Node(10)
    root1.left = Node(30)
    root1.right = Node(60)
    root1.left.left = Node(20)
    root1.left.right = Node(50)
    root1.right.left = Node(40)
    root1.right.right = Node(70)

    root2 = Node(20)
    root2.left = Node(10)
    root2.right = Node(40)
    root2.left.left = Node(5)
    root2.left.right = Node(15)
    root2.right.left = Node(35)
    root2.right.right = Node(70)

    merged_root = merge_bsts(root1, root2)
    print_tree(merged_root)

main()

The above code first defines a Node class to create Binary Search Tree (BST) nodes. The `sorted_array_to_bst` function converts sorted array to BST. The `merge_bsts` function merges two BSTs into a balanced BST. The `in_order_traversal`, `pre_order_traversal`, `post_order_traversal` are used for tree traversal. The `print_tree` function prints the tree in in-order, pre-order, and post-order traversals.