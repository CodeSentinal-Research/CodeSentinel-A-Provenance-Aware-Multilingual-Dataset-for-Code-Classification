import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()
    
    if not t:
        print("")
        return
        
    t_counter = Counter(t)
    required = len(t_counter)
    formed = 0
    
    window_counts = Counter()
    left = 0
    min_len = float('inf')
    start_idx = 0
    
    for right in range(len(s)):
        char = s[right]
        window_counts[char] += 1
        
        if char in t_counter and window_counts[char] == t_counter[char]:
            formed += 1
            
        while left <= right and formed == required:
            if right - left + 1 < min_len:
                min_len = right - left + 1
                start_idx = left
                
            left_char = s[left]
            window_counts[left_char] -= 1
            if left_char in t_counter and window_counts[left_char] < t_counter[left_char]:
                formed -= 1
            left += 1
            
    if min_len == float('inf'):
        print("")
    else:
        print(s[start_idx:start_idx+min_len])

solve()

