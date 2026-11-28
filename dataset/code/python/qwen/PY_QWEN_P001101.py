import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    parent = list(range(n + 1))
    
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
        
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx == ry:
            return False
        parent[rx] = ry
        return True
        
    redundant_edge = []
    for _ in range(n):
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        if not union(u, v):
            redundant_edge = [u, v]
            
    print(*redundant_edge)

if __name__ == "__main__":
    solve()

