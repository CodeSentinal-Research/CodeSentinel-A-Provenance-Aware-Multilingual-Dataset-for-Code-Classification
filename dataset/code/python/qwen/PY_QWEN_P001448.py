import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    words = []
    for _ in range(n):
        words.append(input_data[idx]); idx += 1
    order = input_data[idx]; idx += 1
    
    order_map = {c: i for i, c in enumerate(order)}
    
    for i in range(n - 1):
        w1 = words[i]
        w2 = words[i+1]
        min_len = min(len(w1), len(w2))
        found = False
        for j in range(min_len):
            if w1[j] != w2[j]:
                if order_map[w1[j]] > order_map[w2[j]]:
                    print("NO")
                    return
                found = True
                break
        if not found and len(w1) > len(w2):
            print("NO")
            return
            
    print("YES")

solve()

