import sys

def solve():
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    
    if len(s) != len(t):
        print("NO")
        return
        
    map_s_t = {}
    map_t_s = {}
    
    for c1, c2 in zip(s, t):
        if c1 in map_s_t:
            if map_s_t[c1] != c2:
                print("NO")
                return
        else:
            map_s_t[c1] = c2
            
        if c2 in map_t_s:
            if map_t_s[c2] != c1:
                print("NO")
                return
        else:
            map_t_s[c2] = c1
            
    print("YES")

solve()

