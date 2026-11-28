from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def create_tree(nodes):
    queue = deque()
    root = Node(nodes.popleft())
    queue.append(root)
    while nodes:
        node = queue.popleft()
        if nodes[0] is not None:
            node.left = Node(int(nodes.popleft()))
            queue.append(node.left)
        if nodes[0] is not None:
            node.right = Node(int(nodes.popleft()))
            queue.append(node.right)
        nodes.popleft()
    return root

def max_value_at_level(root):
    max_values = []
    queue = deque([(root, 0)])
    while queue:
        node, level = queue.popleft()
        if len(max_values) == level:
            max_values.append(node.value)
        else:
            max_values[level] = node.value
        if node.left:
            queue.append((node.left, level + 1))
        if node.right:
            queue.append((node.right, level + 1))
    return max_values

def main():
    N = int(input().strip())
    nodes = deque(int(node) for node in input().strip().split())
    root = create_tree(nodes)
    max_values = max_value_at_level(root)
    print('\n'.join(map(str, max_values)))

if __name__ == '__main__':
    main()