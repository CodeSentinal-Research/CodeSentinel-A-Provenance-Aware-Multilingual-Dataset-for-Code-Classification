def is_tree_bst():
    N = int(input().strip())
    preorder = list(map(int, input().strip().split()))
    
    def find_children(node, parent=None):
        if node < N:
            left, right = preorder[node*2], preorder[node*2+1]
            if parent is not None and (left != parent or right != parent):
                return False
            if not find_children(left, node) or not find_children(right, node):
                return False
        return True
    
    return 'YES' if find_children(0) else 'NO'

print(is_tree_bst())
This Python program reads the number of nodes N and the preorder traversal of the binary search tree. It uses a recursive function `find_children` to check if every internal node has exactly one child. The function returns 'YES' if every internal node has exactly one child, otherwise it returns 'NO'.