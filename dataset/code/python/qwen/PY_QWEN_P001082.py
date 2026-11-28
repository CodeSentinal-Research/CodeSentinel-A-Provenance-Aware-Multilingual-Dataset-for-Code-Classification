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
        
    odd_nodes = [i for i in range(1, n+1) if degree[i] % 2 != 0]
    
    if len(odd_nodes) not in [0, 2]:
        print("IMPOSSIBLE")
        return
        
    start = odd_nodes[0] if odd_nodes else 1
    
    stack = [start]
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

