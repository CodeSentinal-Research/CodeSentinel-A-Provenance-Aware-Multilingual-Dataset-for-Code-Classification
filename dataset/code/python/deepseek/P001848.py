Here is the Python code for the problem:

def solve(N, BST):
    inorder = []

    def inorder_traversal(node):
        if node:
            inorder_traversal(node.left)
            inorder.append(node.data)
            inorder_traversal(node.right)

    for bst in BST:
        inorder = []
        inorder_traversal(bst)
        print(' '.join(map(str, inorder)))


if __name__ == "__main__":
    N = int(input().strip())
    BST = [None] * N
    for i in range(N):
        BST[i] = eval(input().strip())
    solve(N, BST)

This code first reads the number of nodes N from the input. Then it reads each node of the BST one by one and parses it into a Node object. After that, it calls the function `inorder_traversal` which traverses the BST in inorder and appends each node's value to the `inorder` list. Finally, it prints the inorder sequence of the BST.

Note: This code assumes that the input BSTs are valid and the BST nodes are correctly formatted as in the problem statement. The input format for the BST nodes (which represent the nodes of the BST) is a tuple with two integers. The first integer is the node's data, and the second integer is the index of the left child, and the third integer is the index of the right child. If a node doesn't have a child, the integer is None.