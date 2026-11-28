import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    type3 = []
    type1 = []
    type2 = []
    
    for _ in range(m):
        t = int(input_data[idx]); idx += 1
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        if t == 3:
            type3.append((u, v))
        elif t == 1:
            type1.append((u, v))
        else:
            type2.append((u, v))
            
    parent_a = list(range(n + 1))
    parent_b = list(range(n + 1))
    rank_a = [0] * (n + 1)
    rank_b = [0] * (n + 1)
    
    def find(par, x):
        while par[x] != x:
            par[x] = par[par[x]]
            x = par[x]
        return x
        
    def union(par, rank, x, y):
        rx, ry = find(par, x), find(par, y)
        if rx == ry:
            return False
        if rank[rx] < rank[ry]:
            par[rx] = ry
        elif rank[rx] > rank[ry]:
            par[ry] = rx
        else:
            par[ry] = rx
            rank[rx] += 1
        return True
        
    removed = 0
    
    # Process Type 3 first
    for u, v in type3:
        if not union(parent_a, rank_a, u, v):
            removed += 1
        else:
            union(parent_b, rank_b, u, v)
            
    # Process Type 1
    for u, v in type1:
        if not union(parent_a, rank_a, u, v):
            removed += 1
            
    # Process Type 2
    for u, v in type2:
        if not union(parent_b, rank_b, u, v):
            removed += 1
            
    # Check connectivity
    def is_connected(par):
        root = find(par, 1)
        return all(find(par, i) == root for i in range(1, n + 1))
        
    if is_connected(parent_a) and is_connected(parent_b):
        print(removed)
    else:
        print(-1)

if __name__ == "__main__":
    solve()

