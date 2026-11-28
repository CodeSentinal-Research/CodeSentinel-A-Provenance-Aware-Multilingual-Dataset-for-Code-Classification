import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    p = sys.stdin.readline().strip()
    
    p_counter = Counter(p)
    required = len(p_counter)
    formed = 0
    
    window_counts = Counter()
    left = 0
    results = []
    
    for right in range(len(s)):
        char = s[right]
        window_counts[char] += 1
        
        if char in p_counter and window_counts[char] == p_counter[char]:
            formed += 1
            
        if right >= len(p):
            left_char = s[left]
            window_counts[left_char] -= 1
            if left_char in p_counter and window_counts[left_char] < p_counter[left_char]:
                formed -= 1
            left += 1
            
        if formed == required:
            results.append(left)
            
    print(*results)

solve()

