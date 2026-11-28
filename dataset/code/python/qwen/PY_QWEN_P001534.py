import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    
    left = 0
    max_len = 0
    counter = Counter()
    
    for right in range(len(s)):
        counter[s[right]] += 1
        while len(counter) > 2:
            counter[s[left]] -= 1
            if counter[s[left]] == 0:
                del counter[s[left]]
            left += 1
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

