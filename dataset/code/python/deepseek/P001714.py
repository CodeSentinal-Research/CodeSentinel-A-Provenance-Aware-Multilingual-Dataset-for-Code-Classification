def count_half_nodes(tree):
    count = 0
    for node in tree:
        if node is not None:
            count += 1
            if node.left is not None:
                count -= 1
            if node.right is not None:
                count -= 1
    return count

def create_tree(lines):
    import sys
    from collections import deque

    class Node:
        def __init__(self, data=None):
            self.data = data
            self.left = None
            self.right = None

    root = Node(int(lines.pop(0)))
    current_nodes = deque([root])

    while len(lines) > 0:
        node = current_nodes.popleft()
        line = lines.pop(0)
        if line != '-':
            node.left = Node(int(line))
            current_nodes.append(node.left)
        if len(lines) > 0:
            line = lines.pop(0)
            if line != '-':
                node.right = Node(int(line))
                current_nodes.append(node.right)
    return root

def main():
    lines = []
    while True:
        line = input()
        if line == '0':
            break
        else:
            lines.append(line)
    tree = create_tree(lines)
    print(count_half_nodes(tree))

if __name__ == '__main__':
    main()