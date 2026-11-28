def count_nodes(root):
    if root is None:
        return 0

    count = 0
    level = [root]

    while level:
        next_level = []
        for node in level:
            count += 1
            if node.left:
                next_level.append(node.left)
            if node.right:
                next_level.append(node.right)
        level = next_level

    return count

class Node:
    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

def main():
    N = int(input().strip())
    nodes = [Node(left=None, right=None) if i < N - 1 else None for i in range(N)]
    for i in range(N):
        if nodes[i] is not None:
            left_index = 2 * i + 1
            right_index = 2 * i + 2
            if left_index < N:
                nodes[i].left = nodes[left_index]
            if right_index < N:
                nodes[i].right = nodes[right_index]
    root = nodes[0]
    print(count_nodes(root))

if __name__ == '__main__':
    main()