def is_valid_coloring(V, E, edges, M):
    adj_list = [[] for _ in range(V)]
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)

    color = [0 for _ in range(V)]
    for v in range(V):
        if not color[v]:
            if not dfs(adj_list, color, v, 1, M):
                return False
    return True

def dfs(adj_list, color, v, c, M):
    color[v] = c
    for w in adj_list[v]:
        if not color[w]:
            if not dfs(adj_list, color, w, M - c, M):
                return False
        elif color[w] == c:
            return False
    return True

def main():
    V = int(input())
    E = int(input())
    edges = [list(map(int, input().split())) for _ in range(E)]
    M = int(input())

    print(is_valid_coloring(V, E, edges, M))

if __name__ == "__main__":
    main()