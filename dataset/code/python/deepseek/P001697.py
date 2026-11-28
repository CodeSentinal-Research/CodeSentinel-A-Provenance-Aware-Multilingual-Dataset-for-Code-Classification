Here is the Python code:

def isSubtree(root):
    if root is None:
        return True
    if root.val == 0 and root.left is None and root.right is None:
        return False
    if root.val == 1 and root.left is not None and root.right is not None:
        return False
    if root.val == 1:
        return isSubtree(root.left) and isSubtree(root.right)
    if root.val == 0:
        return isSubtree(root.left) or isSubtree(root.right)

def prune(root):
    if root is None:
        return True
    if root.val == 0 and root.left is None and root.right is None:
        return False
    if root.val == 1 and root.left is not None and root.right is not None:
        return False
    if root.val == 1:
        left = prune(root.left)
        right = prune(root.right)
        if left or right:
            return True
        return False
    if root.val == 0:
        left = prune(root.left)
        right = prune(root.right)
        if left or right:
            return True
        return False

def solve(n, nodes, tree):
    root = None
    nodes.append(0)
    tree.append(0)
    index_nodes = {val: i for i, val in enumerate(nodes)}
    build_tree(root, index_nodes, 0, len(nodes) - 1)

    for i in range(n):
        if tree[i] == 1:
            if not isSubtree(root):
                print('Prune', i + 1)
            else:
                print('Keep', i + 1)
        else:
            if prune(root):
                print('Prune', i + 1)
            else:
                print('Keep', i + 1)
This code first defines a function `isSubtree` that checks if a subtree with a value 1 exists in the binary tree. It uses recursion to check every subtree. 

Then, it defines a function `prune` that prunes the binary tree if it is not a subtree with a value 1. It uses recursion to check every node.

Finally, it defines a main function `solve` that takes the number of nodes, the list of nodes, and the list of tree values as input. It constructs the binary tree and then checks each node based on its value. If the value is 1, it checks if the subtree rooted at the current node is a subtree with a value 1. If it is not, it prunes the tree; otherwise, it keeps the tree. If the value is 0, it checks if the subtree rooted at the current node is a subtree with a value 1. If it is not, it prunes the tree; otherwise, it keeps the tree.