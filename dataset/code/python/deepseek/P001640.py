def isSymmetric(root):
    def isMirror(node1, node2):
        if node1 is None and node2 is None:
            return True
        elif node1 is None or node2 is None:
            return False
        else if node1.val == node2.val:
            return isMirror(node1.left, node2.right) and isMirror(node1.right, node2.left)
        else:
            return False

    return isMirror(root, root)
This code defines a recursive function isMirror that compares the left and right children of the nodes in the binary tree. If the nodes' values are the same, it calls isMirror on the left and right children of the nodes. If the values are not the same, it returns False.

The main function, isSymmetric, just calls isMirror with the root of the binary tree as the argument. If isMirror returns True, the binary tree is symmetric; otherwise, it is not symmetric.