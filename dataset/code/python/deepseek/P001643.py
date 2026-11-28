Here is a Python solution using the Breadth-First Search (BFS) algorithm to find the maximum width of the binary tree.

from collections import deque

class Node:
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def read_input():
    n = int(input())
    nodes = []
    for i in range(n):
        line = input().split()
        if line[1] == 'None':
            nodes.append(None)
        else:
            nodes.append(Node(value=line[1]))
            nodes.append(Node(value=line[3]))
    return nodes

def max_width(nodes):
    if not nodes:
        return 0

    queue = deque([(nodes[0], 0)])
    max_width = 0
    current_width = 0
    min_index = 0

    while queue:
        node, index = queue.popleft()
        if node is not None:
            current_width = index - min_index
            max_width = max(max_width, current_width)
            queue.append((node.left, 2 * index + 1))
            queue.append((node.right, 2 * index + 2))
        else:
            min_index = index

    return max_width

def main():
    nodes = read_input()
    print(max_width(nodes))

if __name__ == "__main__":
    main()

In this solution, we use a queue to keep track of the nodes to be processed. We keep track of the index of the minimum node at any given level and the current width of the nodes at any given level. The maximum width is updated as we process the nodes.

The input to this solution is the list of nodes in level order (left child, right child), where 'None' is represented by 'None'. The function `read_input()` reads the input and returns the list of nodes. The function `max_width()` returns the maximum width of the binary tree. The `main()` function calls these two functions and prints the result.