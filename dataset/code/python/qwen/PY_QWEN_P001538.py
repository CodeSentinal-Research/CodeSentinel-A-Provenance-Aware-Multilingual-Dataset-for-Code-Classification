import sys
from collections import Counter

def solve():
    s1 = sys.stdin.readline().strip()
    s2 = sys.stdin.readline().strip()
    
    s1_counter = Counter(s1)
    required = len(s1_counter)
    formed = 0
    
    window_counts = Counter()
    left = 0
    
    for right in range(len(s2)):
        char = s2[right]
        window_counts[char] += 1
        
        if char in s1_counter and window_counts[char] == s1_counter[char]:
            formed += 1
            
        if right >= len(s1):
            left_char = s2[left]
            window_counts[left_char] -= 1
            if left_char in s1_counter and window_counts[left_char] < s1_counter[left_char]:
                formed -= 1
            left += 1
            
        if formed == required:
            print("YES")
            return
            
    print("NO")

solve()

