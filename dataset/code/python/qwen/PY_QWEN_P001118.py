import sys
from collections import defaultdict, deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    words = []
    for _ in range(n):
        words.append(input_data[idx]); idx += 1
        
    # Build graph of character dependencies
    adj = defaultdict(set)
    in_degree = defaultdict(int)
    chars = set()
    
    for w in words:
        for c in w:
            chars.add(c)
            
    for i in range(n - 1):
        w1 = words[i]
        w2 = words[i+1]
        min_len = min(len(w1), len(w2))
        found = False
        for j in range(min_len):
            if w1[j] != w2[j]:
                if w2[j] not in adj[w1[j]]:
                    adj[w1[j]].add(w2[j])
                    in_degree[w2[j]] += 1
                found = True
                break
        if not found and len(w1) > len(w2):
            print("IMPOSSIBLE")
            return
            
    q = deque()
    for c in chars:
        if in_degree[c] == 0:
            q.append(c)
            
    order = []
    while q:
        c = q.popleft()
        order.append(c)
        for neighbor in adj[c]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                q.append(neighbor)
                
    if len(order) == len(chars):
        print("".join(order))
    else:
        print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()

