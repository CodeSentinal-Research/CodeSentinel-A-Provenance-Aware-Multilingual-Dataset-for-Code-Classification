import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    prefix = [0] * n
    prefix[0] = ord(s[0]) - ord('a') + 1
    for i in range(1, n):
        prefix[i] = prefix[i-1] + (ord(s[i]) - ord('a') + 1)
        
    print(*prefix)

solve()

