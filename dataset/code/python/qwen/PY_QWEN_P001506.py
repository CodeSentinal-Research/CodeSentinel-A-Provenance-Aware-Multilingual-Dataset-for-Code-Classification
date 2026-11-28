import sys

def solve():
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    
    n = len(s)
    m = len(t)
    
    min_len = float('inf')
    start_idx = -1
    
    for i in range(n):
        if s[i] == t[0]:
            j = 0
            k = i
            while k < n and j < m:
                if s[k] == t[j]:
                    j += 1
                k += 1
            if j == m:
                if k - i < min_len:
                    min_len = k - i
                    start_idx = i
                    
    if start_idx == -1:
        print("")
    else:
        print(s[start_idx:start_idx+min_len])

solve()

