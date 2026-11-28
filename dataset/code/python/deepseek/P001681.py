Here's the Python code with a main function and input handling.

from collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def reverse_level_order(root):
    if not root:
        return
    queue = deque([root])
    while queue:
        level = deque()
        for _ in range(len(queue)):
            node = queue.popleft()
            if node.left:
                level.appendleft(node.left)
            if node.right:
                level.appendleft(node.right)
        for node in level:
            print(node.val, end=' ')
        print()

def main():
    N = int(input().strip())
    nodes = [TreeNode(int(x)) for x in input().strip().split()]
    for i in range(N):
        if i % 2 == 0:
            nodes[i//2].left = nodes[i+1]
        else:
            nodes[i//2].right = nodes[i]
    root = nodes[0]
    reverse_level_order(root)

if __name__ == "__main__":
    main()

This code first creates a `TreeNode` class for each node in the binary tree. Then it defines the `reverse_level_order` function, which performs the level order traversal in reverse order. It prints the nodes in each level from left to right.

The `main` function reads the input and creates the binary tree. It then calls the `reverse_level_order` function to print the reverse level order traversal.