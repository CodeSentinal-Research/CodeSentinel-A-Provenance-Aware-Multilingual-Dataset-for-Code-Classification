Here is the Python code for the problem.

from collections import deque

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def read_tree():
    n = int(input())
    values = list(map(int, input().split()))

    nodes = [None] * (n + 1)
    for i in range(n):
        parent = nodes[i // 2]
        if i % 2 == 0:
            child = nodes[i // 2 + 1]
            if parent.left is None:
                parent.left = child
            else:
                parent.right = child
        else:
            child = nodes[i // 2 - 1]
            if child.left is None:
                child.left = parent
            else:
               child.right = parent

    return nodes[1]

def sum_at_even_levels(root):
    queue = deque([(root, 0)])
    sums = []
    while queue:
        node, level = queue.popleft()
        if node is not None:
            if level % 2 == 0:
                sums.append(node.value)
            queue.append((node.left, level + 1))
            queue.append((node.right, level + 1))
    return sum(sums)

def main():
    root = read_tree()
    print(sum_at_even_levels(root))

if __name__ == "__main__":
    main()

In this code, we first read the tree and construct the nodes. Then we use BFS (Breadth-First Search) to traverse the tree level by level. For each node at an even level, we add its value to the sum. Finally, we print the sum.