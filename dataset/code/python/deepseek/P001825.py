class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert(node, value):
    if node is None:
        return Node(value)
    if value < node.value:
        node.left = insert(node.left, value)
    else:
        node.right = insert(node.right, value)
    return node

def inorder_traversal(node, values = []):
    if node is not None:
        inorder_traversal(node.left, values)
        values.append(node.value)
        inorder_traversal(node.right)
    return values

def sorted_array_to_bst(arr, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    bst_node = Node(arr[mid])
    bst_node.left = sorted_array_to_bst(arr, start, mid - 1)
    bst_node.right = sorted_array_to_bst(arr, mid + 1, end)
    return bst_node

def rebalance_bst(root):
    sorted_values = inorder_traversal(root)
    return sorted_array_to_bst(sorted_values, 0, len(sorted_values) - 1)

def main():
    n = int(input().strip())
    root = None
    for _ in range(n):
        value = int(input().strip())
        root = insert(root, value)
    rebalanced_root = rebalance_bst(root)
    inorder_traversal(rebalanced_root)

if __name__ == "__main__":
    main()