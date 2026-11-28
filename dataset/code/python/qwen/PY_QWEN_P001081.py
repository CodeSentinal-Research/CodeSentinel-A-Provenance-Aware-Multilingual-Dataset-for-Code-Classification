import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n+1)]
    degree = [0] * (n+1)
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        degree[u] += 1
        degree[v] += 1
        
    # Check if all degrees are even
    if any(d % 2 != 0 for d in degree[1:]):
        print("IMPOSSIBLE")
        return
        
    # Hierholzer's algorithm
    stack = [1]
    path = []
    while stack:
        u = stack[-1]
        if adj[u]:
            v = adj[u].pop()
            adj[v].remove(u)
            stack.append(v)
        else:
            path.append(stack.pop())
            
    print(*path[::-1])

if __name__ == "__main__":
    solve()

