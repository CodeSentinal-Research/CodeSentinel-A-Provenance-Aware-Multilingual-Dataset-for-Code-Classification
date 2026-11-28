import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    
    parent = list(range(n+1))
    rank = [0] * (n+1)
    
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
        
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx == ry:
            return
        if rank[rx] < rank[ry]:
            parent[rx] = ry
        elif rank[rx] > rank[ry]:
            parent[ry] = rx
        else:
            parent[ry] = rx
            rank[rx] += 1
            
    output = []
    for _ in range(q):
        op = input_data[idx]; idx += 1
        u = int(input_data[idx]); idx += 1
        v = int(input_data[idx]); idx += 1
        if op == "UNION":
            union(u, v)
        elif op == "FIND":
            if find(u) == find(v):
                output.append("YES")
            else:
                output.append("NO")
                
    print("
".join(output))

if __name__ == "__main__":
    solve()

