import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    v = int(input_data[idx]); idx += 1
    e = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(v)]
    for _ in range(e):
        u = int(input_data[idx]); idx += 1
        vv = int(input_data[idx]); idx += 1
        adj[u].append(vv)
        
    results = []
    
    def backtrack(node, path, visited):
        if node == v - 1:
            results.append(path[:])
            return
        for neighbor in adj[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                path.append(neighbor)
                backtrack(neighbor, path, visited)
                path.pop()
                visited.remove(neighbor)
                
    visited = {0}
    backtrack(0, [0], visited)
    for res in results:
        print(" ".join(map(str, res)))

if __name__ == "__main__":
    solve()

