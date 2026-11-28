import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    
    def max_consecutive(char):
        left = 0
        changes = 0
        max_len = 0
        for right in range(len(s)):
            if s[right] != char:
                changes += 1
            while changes > k:
                if s[left] != char:
                    changes -= 1
                left += 1
            max_len = max(max_len, right - left + 1)
        return max_len
        
    print(max(max_consecutive('T'), max_consecutive('F')))

solve()

