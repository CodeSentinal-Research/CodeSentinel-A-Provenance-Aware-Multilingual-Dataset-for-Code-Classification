import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    
    left = 0
    max_len = 0
    counter = Counter()
    max_freq = 0
    
    for right in range(len(s)):
        counter[s[right]] += 1
        max_freq = max(max_freq, counter[s[right]])
        
        while (right - left + 1) - max_freq > k:
            counter[s[left]] -= 1
            left += 1
            
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

