import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    sentence1 = input_data[idx].split(); idx += 1
    sentence2 = input_data[idx].split(); idx += 1
    p = int(input_data[idx]); idx += 1
    
    parent = {}
    
    def find(x):
        if x not in parent:
            parent[x] = x
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
        
    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            parent[rx] = ry
            
    for _ in range(p):
        w1 = input_data[idx]; idx += 1
        w2 = input_data[idx]; idx += 1
        union(w1, w2)
        
    if len(sentence1) != len(sentence2):
        print("NO")
        return
        
    for w1, w2 in zip(sentence1, sentence2):
        if find(w1) != find(w2):
            print("NO")
            return
            
    print("YES")

solve()

