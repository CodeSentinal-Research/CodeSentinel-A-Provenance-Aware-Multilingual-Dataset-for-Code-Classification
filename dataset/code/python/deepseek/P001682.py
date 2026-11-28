Sure, here is the Python code for the problem.

from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_leaf(node):
    if node is None:
        return False
    if node.left is None and node.right is None:
        return True
    return False

def check_depth(root):
    if root is None:
        return True

    queue = deque([(root, 0)])
    min_depth = float('inf')
    max_depth = float('-inf')

    while queue:
        node, depth = queue.popleft()

        if is_leaf(node):
            if depth == min_depth or depth == max_depth:
                return 'NO'
            min_depth = max_depth = depth
        else:
            if depth < min_depth:
                min_depth = depth
            if depth > max_depth:
                max_depth = depth

        if node.left:
            queue.append((node.left, depth + 1))
        if node.right:
            queue.append((node.right, depth + 1))

    return 'YES' if min_depth == max_depth else 'NO'

def main():
    N = int(input().strip())
    nodes = [Node(data) for data in input().strip().split()]

    for i in range(N):
        if i % 2 == 0:
            nodes[i // 2].left = nodes[i]
        else:
            nodes[i // 2].right = nodes[i]

    print(check_depth(nodes[0]))

if __name__ == '__main__':
    main()

In this code, we are first creating a binary tree from the input. We then use a Breadth-First Search (BFS) to traverse the tree and check if all leaf nodes are at the same level. We store the depth of each node and check if all nodes have the same depth. If they do, the tree is a binary search tree and we print 'YES'; otherwise, we print 'NO'.