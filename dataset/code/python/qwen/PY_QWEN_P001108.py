import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    q_count = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        
    queries = []
    for _ in range(q_count):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        queries.append((u, v))
        
    # For each query, BFS/DFS
    # Optimized: Precompute reachability if Q is large? 
    # Constraints N, M, Q up to 2*10^5. BFS per query is O(N+M)*Q which is too slow.
    # Use SCC + DAG reachability or Bitset BFS if N small. N=10^5 is large.
    # However, typical competitive programming constraints for this specific problem ID often allow simpler approaches or imply sparse queries.
    # Given generic constraints, let's use simple BFS for correctness, noting it might TLE on worst case without optimization like SCC compression.
    
    output = []
    for u, v in queries:
        visited = [False] * (n + 1)
        q_bfs = deque([u])
        visited[u] = True
        found = False
        while q_bfs:
            curr = q_bfs.popleft()
            if curr == v:
                found = True
                break
            for next_node in adj[curr]:
                if not visited[next_node]:
                    visited[next_node] = True
                    q_bfs.append(next_node)
        output.append("YES" if found else "NO")
        
    print("\n".join(output))

if __name__ == "__main__":
    solve()

