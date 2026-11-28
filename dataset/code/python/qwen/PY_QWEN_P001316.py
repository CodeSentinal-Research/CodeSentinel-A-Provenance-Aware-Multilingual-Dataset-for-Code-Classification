import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    v = int(input_data[idx]); idx += 1
    e = int(input_data[idx]); idx += 1
    m_colors = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(v + 1)]
    for _ in range(e):
        u = int(input_data[idx]); idx += 1
        vv = int(input_data[idx]); idx += 1
        adj[u].append(vv)
        adj[vv].append(u)
        
    color = [0] * (v + 1)
    
    def is_safe(node, c):
        for neighbor in adj[node]:
            if color[neighbor] == c:
                return False
        return True
        
    def backtrack(node):
        if node > v:
            return True
        for c in range(1, m_colors + 1):
            if is_safe(node, c):
                color[node] = c
                if backtrack(node + 1):
                    return True
                color[node] = 0
        return False
        
    print("YES" if backtrack(1) else "NO")

if __name__ == "__main__":
    solve()

