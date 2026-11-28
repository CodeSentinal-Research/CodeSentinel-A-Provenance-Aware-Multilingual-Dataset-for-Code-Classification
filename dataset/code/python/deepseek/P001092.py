Here is the Python code for the problem:

def solve():
    N, Q = map(int, input().split())
    graph = [[] for _ in range(N+1)]
    depth = [0] * (N+1)
    parent = [0] * (N+1)
    for _ in range(N-1):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    for _ in range(Q):
        node, k = map(int, input().split())
        print(solve(node, k))

def solve(node, k):
    if k > depth[node]:
        return -1
    for i in range(k, -1, -1):
        if depth[node] - k <= i:
            return parent[node][i]
        node = parent[node][i]
    return -1

def dfs(node, depth, parent, graph):
    for child in graph[node]:
        depth[child] = depth[node] + 1
        parent[child] = node
        dfs(child, depth, parent, graph)

if __name__ == "__main__":
    solve()

This code will create a parent array for each node, which will hold the parent of each node. The depth array will hold the depth of each node from the root. The dfs function will fill these arrays using depth-first search.