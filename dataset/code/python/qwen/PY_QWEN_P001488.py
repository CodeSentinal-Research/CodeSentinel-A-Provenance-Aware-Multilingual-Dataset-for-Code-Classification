import sys

def solve():
    s = sys.stdin.readline().strip()
    left = 0
    right = len(s) - 1
    
    while left < right and s[left] == s[right]:
        char = s[left]
        while left <= right and s[left] == char:
            left += 1
        while left <= right and s[right] == char:
            right -= 1
            
    print(right - left + 1)

solve()

