Here is the Python code for the problem:

def recover_bst(swapped_bst):
    inorder = []

    for key in inorder_traversal(swapped_bst):
        inorder.append(key)

    root = recover_bst_util(inorder, 0, len(inorder) - 1)

    return root

def inorder_traversal(root):
    if root is not None:
        yield from inorder_traversal(root.left)
        yield root.val
        yield from inorder_traversal(root.right)

def recover_bst_util(arr, start, end):
    if start > end:
        return None

    mid = (start + end) // 2

    root = arr[mid]

    root.left = recover_bst_util(arr, start, mid - 1)
    root.right = recover_bst_util(arr, mid + 1, end)

    return root

def main():
    n = int(input())
    swapped_bst = []

    for _ in range(n):
        swapped_bst.append(int(input()))

    root = recover_bst(swapped_bst)

    print_bst(root)

def print_bst(root):
    if root is None:
        return

    print(root.val, end=' ')
    print_bst(root.left)
    print_bst(root.right)

if __name__ == "__main__":
    main()
This code first reads the size of the swapped BST and then the elements of the swapped BST. It then calls the `recover_bst` function which uses the `inorder_traversal` and `recover_bst_util` functions to recover the BST. The `inorder_traversal` function is used to get the values in an ascending order, and `recover_bst_util` is used to reconstruct the BST from the sorted inorder list. Finally, it prints the recovered BST.