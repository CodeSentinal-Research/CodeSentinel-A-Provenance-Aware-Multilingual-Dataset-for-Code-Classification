import sys
from collections import defaultdict, deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    e = int(input_data[idx]); idx += 1
    
    graph = defaultdict(dict)
    for _ in range(e):
        num = input_data[idx]; idx += 1
        den = input_data[idx]; idx += 1
        val = float(input_data[idx]); idx += 1
        graph[num][den] = val
        graph[den][num] = 1.0 / val
        
    q_count = int(input_data[idx]); idx += 1
    
    results = []
    for _ in range(q_count):
        src = input_data[idx]; idx += 1
        dst = input_data[idx]; idx += 1
        
        if src not in graph or dst not in graph:
            results.append("-1.0")
            continue
        if src == dst:
            results.append("1.0")
            continue
            
        # BFS
        visited = set([src])
        queue = deque([(src, 1.0)])
        found = False
        while queue:
            node, prod = queue.popleft()
            if node == dst:
                results.append(f"{prod:.1f}")
                found = True
                break
            for neighbor, weight in graph[node].items():
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, prod * weight))
        if not found:
            results.append("-1.0")
            
    print("\n".join(results))

if __name__ == "__main__":
    solve()

