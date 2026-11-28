Here is the Python code for the problem:

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def constructFromPreorder(preorder, inorder):
    if inorder:
        root = TreeNode(preorder.pop())
        inorderIndex = inorder.index(root.val)
        root.left = constructFromPreorder(preorder, inorder[0:inorderIndex])
        root.right = constructFromPreorder(preorder, inorder[inorderIndex+1:])
        return root

def main():
    preorder = list(map(int, input().strip().split()))[1:]
    inorder = list(map(int, input().strip().split()))[1:]
    root = constructFromPreorder(preorder, inorder)
    print(root.val)
    print(root.left and print(root.left.val))
    print(root.right and print(root.right.val))

if __name__ == '__main__':
    main()

This code first reads the preorder and inorder traversal from the input. Then, it constructs the tree using the `constructFromPreorder` function, which recursively constructs the left and right subtrees. The `main` function then prints the root of the constructed tree.