import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    
    counter = Counter()
    left = 0
    max_len = 0
    max_freq = 0
    
    for right in range(len(s)):
        counter[s[right]] += 1
        max_freq = max(max_freq, counter[s[right]])
        
        while (right - left + 1) - max_freq > k:
            counter[s[left]] -= 1
            left += 1
            # Recalculate max_freq? Or just let it be an overestimate?
            # Overestimate is fine for validity check, but might shrink window too much?
            # Actually, standard optimization doesn't recalculate max_freq immediately.
            # It works because max_freq only decreases when we shrink, but we only care about max_len.
            
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

