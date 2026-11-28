class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

def connect(root: 'Node') -> 'Node':
    if not root:
        return root

    level = root

    while level:
        dummy = Node(0)
        prev = dummy

        while level:
            if level.left:
                prev.next = level.left
                prev = level.left
            if level.right:
                prev.next = level.right
                prev = level.right

            level = level.next
        level = dummy.next

    return root

This Python code defines a binary tree node and a function to connect every node to its next node on the same level. It starts from the root of the tree and iteratively goes through each level. For each level, it creates a dummy node and connects the current node to the next node in the same level.