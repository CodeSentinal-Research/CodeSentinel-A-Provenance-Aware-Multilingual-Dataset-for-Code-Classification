Here is the Python code for the problem.

from collections import deque

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def insert(root, data):
    if root is None:
        return Node(data)
    else:
        if root.val < data:
            root.right = insert(root.right, data)
        else:
            root.left = insert(root.left, data)
    return root

def level_order_traversal(root):
    queue = deque([root])
    while queue:
        print(queue[0].val)
        node = queue.popleft()
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

def solve():
    N = int(input())
    values = list(map(int, input().split()))
    root = None
    for i in range(N):
        root = insert(root, values[i])
    level_order_traversal(root)

if __name__ == "__main__":
    solve()

This code first takes the number of nodes from the input and then the values of the nodes. It then creates the binary tree using these values.
After that, it prints the level order traversal of the binary tree.
In the level order traversal, for every level, it reverses the values at every alternate level.