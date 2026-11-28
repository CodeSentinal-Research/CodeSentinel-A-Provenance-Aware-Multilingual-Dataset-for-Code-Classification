import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    count = 0
    
    for center in range(n):
        # Odd length
        l, r = center, center
        while l >= 0 and r < n and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        # Even length
        l, r = center, center + 1
        while l >= 0 and r < n and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
            
    print(count)

if __name__ == "__main__":
    solve()

