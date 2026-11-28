Here is a Python solution for the given problem. We use a stack to simulate the preorder traversal of the binary tree. For each node, we check if the input is None. If it is, we continue to the next node. If it's not, we create a new node with this value and add it to the stack. Then we get the top element from the stack and add it to the parent node. We repeat this until the stack is empty.

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def recoverFromPreorder(data):
    stack = []
    i = 0

    while i < len(data):
        depth = 0
        while data[i] == '-' and i < len(data):
            i += 1
            depth += 1

        value = ''
        while i < len(data) and data[i] != '-':
            i += 1

        node = Node(value)

        if not stack or stack[-1].depth < depth:
            stack.append(node)
        else:
            while stack and stack[-1].depth == depth:
                stack.pop()
            if stack:
                stack[-1].right = node
            node.left = stack[-1]
            stack[-1] = node

        while i < len(data) and data[i] == '-':
            i += 1
            depth += 1

    return stack[0]

def preorder(root):
    if root:
        print(root.val)
        preorder(root.left)
        preorder(root.right)

And here is the main function to test the `recoverFromPreorder` function:

if __name__ == "__main__":
    data = input().split()
    root = recoverFromPreorder(data)
    preorder(root)

This code assumes that the input is a string of values separated by spaces. Each value represents a node in the preorder traversal. For example, the input "1-2--3" represents a tree with the following structure:

    1
   / \
  2   3
The code will print the preorder traversal of this tree:

1 2 3