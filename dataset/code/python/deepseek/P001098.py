def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, rank, x, y):
    x_root = find(parent, x)
    y_root = find(parent, y)
    if rank[x_root] < rank[y_root]:
        parent[x_root] = y_root
    elif rank[x_root] > rank[y_root]:
        parent[y_root] = x_root
    else:
        parent[y_root] = x_root
        rank[x_root] += 1

def count_components():
    parent = list(range(100001)
    rank = [0] * 100001
    graph = {i: [] for i in range(1, N+1)}
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    for node in range(1, N+1):
        u = find(parent, node)
        for v in graph[node]:
            if find(parent, v) != u:
                union(parent, rank, u, v)
    components = set()
    for node in range(1, N+1):
        components.add(find(parent, node))
    print(len(components))

if __name__ == "__main__":
    N, M = map(int, input().split())
    count_components()