import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    # Manacher's algorithm or DP
    # Count distinct palindromic substrings using Hashing
    
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
        
    palindromes = set()
    
    for center in range(n):
        # Odd length
        l, r = center, center
        while l >= 0 and r < n and s[l] == s[r]:
            palindromes.add(get_hash(l, r + 1))
            l -= 1
            r += 1
        # Even length
        l, r = center, center + 1
        while l >= 0 and r < n and s[l] == s[r]:
            palindromes.add(get_hash(l, r + 1))
            l -= 1
            r += 1
            
    print(len(palindromes))

solve()

