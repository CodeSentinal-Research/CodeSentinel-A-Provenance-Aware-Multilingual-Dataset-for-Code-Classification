import sys

def solve():
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    
    si = 0
    ti = 0
    n = len(s)
    m = len(t)
    
    while si < n and ti < m:
        if s[si] == t[ti]:
            ti += 1
        si += 1
        
    print(m - ti)

solve()

