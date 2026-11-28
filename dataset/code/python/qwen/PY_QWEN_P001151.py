import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    if n == 0:
        print("")
        return
        
    start = 0
    max_len = 1
    
    def expand(l, r):
        while l >= 0 and r < n and s[l] == s[r]:
            l -= 1
            r += 1
        return l + 1, r - l - 1
        
    for i in range(n):
        s1, l1 = expand(i, i)
        s2, l2 = expand(i, i + 1)
        
        if l1 > max_len:
            start = s1
            max_len = l1
        if l2 > max_len:
            start = s2
            max_len = l2
            
    print(s[start:start+max_len])

if __name__ == "__main__":
    solve()

