import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
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
        
    substrings = set()
    for length in range(1, n + 1):
        for i in range(n - length + 1):
            h = get_hash(i, i + length)
            substrings.add(h)
            
    print(len(substrings))

solve()

