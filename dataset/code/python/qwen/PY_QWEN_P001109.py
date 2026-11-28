import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        adj[u].append(v)
        adj[v].append(u)
        
    colors = list(map(int, input_data[idx:idx+n]))
    
    valid = True
    for u in range(1, n + 1):
        for v in adj[u]:
            if colors[u-1] == colors[v-1]:
                valid = False
                break
        if not valid:
            break
            
    print("VALID" if valid else "INVALID")

if __name__ == "__main__":
    solve()

