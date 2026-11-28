Here's the Python code:

def is_full(root):
    if root is None:
        return True
    if root.left is None and root.right is None:
        return True
    if (root.left is not None and root.right is not None):
        return is_full(root.left) and is_full(root.right)
    return False

In this function, we check if the root is None, if it is then it is a full binary tree. If it's not None, we check if both left and right children are None. If they are, it's a full binary tree. If both children are not None, we recursively check for the left and right children. If both checks pass, the function returns True indicating that the binary tree is full. If not all checks pass, the function returns False indicating that the binary tree is not full.