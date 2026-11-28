Here is the Python code for the problem:

def read_input():
    N = int(input().strip())
    nodes = [int(x) for x in input().strip().split()]
    tree = [[] for _ in range(N)]
    for _ in range(N-1):
        parent, child = map(lambda x: int(x) - 1, input().strip().split())
        tree[parent].append(child)
    return N, nodes, tree

def dfs(node, depth, nodes, tree, visited, min_node, max_node):
    visited[node] = True
    min_node[0] = min(min_node[0], nodes[node])
    max_node[0] = max(max_node[0], nodes[node])
    for child in tree[node]:
        if not visited[child]:
            dfs(child, depth + 1, nodes, tree, visited, min_node, max_node)

def solve():
    N, nodes, tree = read_input()
    visited = [False] * N
    min_node = [nodes[0]]
    max_node = [0]
    dfs(0, 0, nodes, tree, visited, min_node, max_node)
    max_diff = max_node[0] - min_node[0]
    return max_diff

if __name__ == "__main__":
    print(solve())

In this code, we first read the input for N, the nodes, and the tree. Then we perform a depth-first search to find the minimum and maximum node values. The maximum difference is then found by subtracting the minimum from the maximum.