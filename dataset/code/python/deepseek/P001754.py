class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def find_leftmost_node_at_max_depth(root):
    if not root:
        return None

    leftmost_node = root
    max_depth = 1

    queue = [(root, 1)]

    while queue:
        current, depth = queue.pop(0)

        if depth > max_depth:
            max_depth = depth
            leftmost_node = current.value

        if current.left:
            queue.append((current.left, depth + 1))

        if current.right:
            queue.append((current.right, depth + 1))

    return leftmost_node

def build_tree(lines):
    values = list(map(int, lines[1].split()))
    nodes = [None] * (len(values) + 1)

    for i, value in enumerate(values):
        if value == -1:
            nodes[i] = None
        else:
            nodes[i] = Node(value)

    for i in range(len(values)):
        if nodes[i]:
            if i * 2 + 1 < len(values):
                nodes[i].left = nodes[i * 2 + 1]
            if i * 2 + 2 < len(values):
                nodes[i].right = nodes[i * 2 + 2]

    return nodes[0]

def main():
    lines = [line.strip() for line in input().splitlines()]
    root = build_tree(lines)
    print(find_leftmost_node_at_max_depth(root))

if __name__ == "__main__":
    main()