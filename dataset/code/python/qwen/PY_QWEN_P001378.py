import sys

def solve():
    pattern = sys.stdin.readline().strip()
    sentence = sys.stdin.readline().strip().split()
    
    if len(pattern) != len(sentence):
        print("NO")
        return
        
    map_p_w = {}
    map_w_p = {}
    
    for p, w in zip(pattern, sentence):
        if p in map_p_w:
            if map_p_w[p] != w:
                print("NO")
                return
        else:
            map_p_w[p] = w
            
        if w in map_w_p:
            if map_w_p[w] != p:
                print("NO")
                return
        else:
            map_w_p[w] = p
            
    print("YES")

solve()

