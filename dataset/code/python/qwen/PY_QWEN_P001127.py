import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    parent = list(range(n))
    
    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
        
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            parent[rx] = ry
            
    for i in range(n):
        row = list(map(int, input_data[idx:idx+n]))
        idx += n
        for j in range(i + 1, n):
            if row[j] == 1:
                union(i, j)
                
    provinces = len(set(find(i) for i in range(n)))
    print(provinces)

if __name__ == "__main__":
    solve()

