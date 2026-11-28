Here is the Python code for the problem:

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def construct_tree(inorder, postorder):
    if inorder:
        root = Node(postorder.pop())
        root.right = construct_tree(inorder[inorder.index(root.val):], postorder)
        root.left = construct_tree(inorder[:inorder.index(root.val)], postorder)
        return root

def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.val, end=' ')
        inorder_traversal(node.right)

def postorder_traversal(node):
    if node:
        postorder_traversal(node.left)
        postorder_traversal(node.right)
        print(node.val, end=' ')

def main():
    n = int(input().strip())
    inorder = list(map(int, input().strip().split()))
    postorder = list(map(int, input().strip().split()))

    root = construct_tree(inorder, postorder)

    print('Inorder traversal:')
    inorder_traversal(root)
    print()
    print('Postorder traversal:')
    postorder_traversal(root)
    print()

if __name__ == "__main__":
    main()

This Python code first takes the number of nodes N from the input and the inorder and postorder traversals. It then constructs the tree using the construct_tree function, which takes two lists as input: inorder and postorder. If the inorder list is not empty, it constructs a new node with the last element of the postorder list as its value and then recursively constructs the left and right subtrees. The reconstructed tree is then printed using the inorder_traversal and postorder_traversal functions.