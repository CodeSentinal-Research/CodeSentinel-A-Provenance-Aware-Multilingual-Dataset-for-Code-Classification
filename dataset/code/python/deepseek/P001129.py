Here's a Python solution for the problem:

def solve():
    n, m = map(int, input().split())
    alice = [0] * (n + 1)
    bob = [0] * (n + 1)
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        t, u, v = map(int, input().split())
        if t == 1:
            alice[u] += 1
        elif t == 2:
            bob[v] += 1
        else:
            graph[u].append(v)
            graph[v].append(u)
    removed = 0
    for i in range(1, n + 1):
        if alice[i] + bob[i] - 1 > removed:
            removed = alice[i] + bob[i] - 1
    if removed < n - 1:
        print(-1)
    else:
        print(n - removed - 1)

if __name__ == "__main__":
    solve()

This program works by first reading the number of nodes and edges, then reading the edges. It then counts the number of edges each node can be used by Alice and Bob separately. The number of edges that can be removed while ensuring both Alice and Bob can still traverse the entire graph is the maximum of the counts from both Alice and Bob minus one. If this maximum is less than the total number of nodes minus one, it means that removing more edges than allowed by the constraints, so it prints -1. Otherwise, it prints the number of edges that can be removed.