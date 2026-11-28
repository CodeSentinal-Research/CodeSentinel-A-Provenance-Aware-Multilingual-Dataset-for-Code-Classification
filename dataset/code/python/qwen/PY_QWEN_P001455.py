import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    # Binary search on length
    low, high = 1, n
    result = ""
    
    base = 131
    mod = 10**9 + 7
    
    powers = [1] * (n + 1)
    for i in range(1, n + 1):
        powers[i] = (powers[i-1] * base) % mod
        
    hashes = [0] * (n + 1)
    for i in range(n):
        hashes[i+1] = (hashes[i] * base + ord(s[i])) % mod
        
    def get_hash(l, r):
        return (hashes[r] - hashes[l] * powers[r-l]) % mod
        
    def check(length):
        seen = {}
        for i in range(n - length + 1):
            h = get_hash(i, i + length)
            if h in seen:
                return s[seen[h]:seen[h]+length]
            seen[h] = i
        return None
        
    while low <= high:
        mid = (low + high) // 2
        sub = check(mid)
        if sub:
            result = sub
            low = mid + 1
        else:
            high = mid - 1
            
    print(result)

solve()

