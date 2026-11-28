class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def is_cousins(root, x, y):
    queue = [(root, None, None)]
    while queue:
        node, parent, depth = queue.pop(0)
        if node.value == x:
            x_parent = parent
            x_depth = depth
        elif node.value == y:
            y_parent = parent
            y_depth = depth
        if node.left:
            queue.append((node.left, node.value, depth + 1))
        if node.right:
            queue.append((node.right, node.value, depth + 1))
    return x_depth == y_depth and x_parent != y_parent

def main():
    N = int(input().strip())
    nodes = [None] + [Node(int(line[0])) for line in [input().strip().split() for _ in range(N)]
    for i in range(1, N):
        if nodes[i].left:
            nodes[i].left.parent = nodes[i]
        if nodes[i].right:
            nodes[i].right.parent = nodes[i]
    x, y = map(int, input().strip().split())
    print('YES' if is_cousins(nodes[1], x, y) else 'NO')

if __name__ == "__main__":
    main()