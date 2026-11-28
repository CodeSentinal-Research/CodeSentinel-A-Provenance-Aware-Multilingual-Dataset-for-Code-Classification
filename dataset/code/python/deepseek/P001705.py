from collections import defaultdict

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def solve(N, nodes):
    adj_list = defaultdict(list)

    for node in nodes:
        value, left, right = node.split()
        value = int(value)
        left = int(left) if left != 'None' else None
        right = int(right) if right != 'None' else None

        adj_list[value].append((left, right))

    max_width = float('-inf')

    def dfs(node, depth):
        nonlocal max_width
        if node is None:
            return

        if depth > max_width:
            max_width = depth

        dfs(node.left, depth + 1)
        dfs(node.right, depth + 1)

    dfs(adj_list[1][0][0], 1)

    return max_width + 1

def main():
    N = int(input().strip())
    nodes = [input().strip() for _ in range(N)]
    print(solve(N, nodes))

if __name__ == "__main__":
    main()