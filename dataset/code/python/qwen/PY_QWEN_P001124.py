import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    src = int(input_data[idx]); idx += 1
    dst = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        w = int(input_data[idx]); idx += 1
        adj[u].append((v, w))
        
    # DP: dist[stops][node]
    dp = [[float('inf')] * (n + 1) for _ in range(k + 2)]
    dp[0][src] = 0
    
    for stops in range(1, k + 2):
        for u in range(1, n + 1):
            if dp[stops-1][u] != float('inf'):
                for v, w in adj[u]:
                    if dp[stops][v] > dp[stops-1][u] + w:
                        dp[stops][v] = dp[stops-1][u] + w
                        
    ans = min(dp[s][dst] for s in range(k + 2))
    print(ans if ans != float('inf') else -1)

if __name__ == "__main__":
    solve()

