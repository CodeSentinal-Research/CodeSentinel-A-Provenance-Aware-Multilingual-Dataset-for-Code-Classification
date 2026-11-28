# problem title : M-Coloring Problem
# Solve the stated task using standard input and standard output.
import sys
def can_color(v, adj, m):
    colors = [0] * v
    def is_safe(node, c):
        for neighbor in adj[node]:
            if colors[neighbor] == c: return False
        return True
    def backtrack(node):
        if node == v: return True
        for c in range(1, m + 1):
            if is_safe(node, c):
                colors[node] = c
                if backtrack(node + 1): return True
                colors[node] = 0
        return False
    return backtrack(0)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        v = int(tokens[0])
        e = int(tokens[1])
        adj = [[] for _ in range(v)]
        idx = 2
        for _ in range(e):
            u, w = int(tokens[idx]), int(tokens[idx+1])
            adj[u].append(w)
            adj[w].append(u)
            idx += 2
        m = int(tokens[idx])
        print("true" if can_color(v, adj, m) else "false")
if __name__ == '__main__':
    main()
