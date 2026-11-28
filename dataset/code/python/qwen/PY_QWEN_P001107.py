import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    reachable = [[False] * (n + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        reachable[i][i] = True
        
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        reachable[u][v] = True
        
    # Floyd-Warshall for transitive closure
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            if reachable[i][k]:
                for j in range(1, n + 1):
                    if reachable[k][j]:
                        reachable[i][j] = True
                        
    for i in range(1, n + 1):
        row = []
        for j in range(1, n + 1):
            row.append('1' if reachable[i][j] else '0')
        print("".join(row))

if __name__ == "__main__":
    solve()

