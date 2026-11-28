Here is a Python solution that uses a queue to solve the problem. The queue is a basic data structure that follows the FIFO (First In First Out) principle.

from collections import deque

def printLevelOrder(root):
    if root is None:
        return

    queue = deque()
    queue.append(root)

    while len(queue) > 0:
        node = queue.popleft()
        print(node.val, end=" ")

        if node.left is not None:
            queue.append(node.left)

        if node.right is not None:
            queue.append(node.right)

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

if __name__=='__main__':

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    print("Level Order Traversal of binary tree is -")
    printLevelOrder(root)

In this code, we first check if the root is None. If it is not, we add it to the queue. Then, while the queue is not empty, we pop the first node from the queue and print its value. Then, we add its children to the queue. This process continues until the queue is empty, which means we have traversed all nodes of the tree level by level.