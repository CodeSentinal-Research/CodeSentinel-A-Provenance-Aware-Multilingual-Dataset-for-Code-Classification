Here is the Python code for your problem.

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def isComplete(root):
    if root is None:
        return True

    queue = deque([root])
    is_leaf = False

    while queue:
        temp = queue.popleft()

        if temp.left:
            if is_leaf and temp.left != root.left:
                return False
            queue.append(temp.left)
        else:
            is_leaf = True

        if temp.right:
            if is_leaf and temp.right != root.right:
                return False
            queue.append(temp.right)
        else:
            is_leaf = False

    return True

def create_tree(nodes):
    nodes_list = list(map(int, nodes.split()))
    root = Node(nodes_list[0])
    queue = deque([root])

    index = 1
    while index < len(nodes_list):
        node = queue.popleft()
        if nodes_list[index] is not None:
            node.left = Node(nodes_list[index])
            queue.append(node.left)
        index += 1
        if index < len(nodes_list):
            if nodes_list[index] is not None:
                node.right = Node(nodes_list[index])
                queue.append(node.right)
            index += 1

    return root

def main():
    root = create_tree(input())
    print('YES' if isComplete(root) else 'NO')

if __name__ == "__main__":
    main()

This code first creates a binary tree from input. The `isComplete` function checks if the binary tree is a complete binary tree or not. It uses a level order traversal approach to check if a binary tree is complete or not.