import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    
    def at_most_k(k_val):
        left = 0
        max_len = 0
        counter = Counter()
        for right in range(len(s)):
            counter[s[right]] += 1
            while len(counter) > k_val:
                counter[s[left]] -= 1
                if counter[s[left]] == 0:
                    del counter[s[left]]
                left += 1
            max_len = max(max_len, right - left + 1)
        return max_len
        
    if k == 0:
        print(0)
    else:
        print(at_most_k(k) - at_most_k(k - 1))

solve()

