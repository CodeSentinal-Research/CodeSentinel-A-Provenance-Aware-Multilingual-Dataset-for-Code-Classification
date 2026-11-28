Here is the Python code for the given problem:

from collections import deque

class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def is_palindromic(tree):
    if tree is None:
        return True

    deque = deque([(tree, 0)])

    while deque:
        node, level = deque.popleft()

        if node is not None:
            if level not in level_dict or level_dict[level] != node.value:
                return False
            level_dict[level] = node.value

            deque.append((node.left, level + 1))
            deque.append((node.right, level + 1))
        else
            deque.append(None)
            deque.append(None)

    return True

if __name__ == "__main__":
    level_dict = {}

    N = int(input())

    for i in range(N):
        line = input().split()
        node_values = [int(value) for value in line[1:]]

        left_index = 2 * i + 1
        right_index = 2 * i + 2

        left = None if left_index >= len(line) else Node(node_values[left_index])
        right = None if right_index >= len(line) else Node(node_values[right_index])

        parent = Node(node_values[i], left, right)

        if i == 0:
            root = parent

    print('YES' if is_palindromic(root) else 'NO')
This Python code first defines a Node class to create a binary tree node. Then, it defines the `is_palindromic` function which checks whether every level of the binary tree is palindromic. The function uses a deque to store nodes at each level, and a dictionary to store the values at each level. The main function reads the input and creates the binary tree. It then prints 'YES' if the binary tree is palindromic, and 'NO' otherwise.