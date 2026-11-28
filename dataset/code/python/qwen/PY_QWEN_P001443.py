import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    m = int(input_data[idx]); idx += 1
    
    start_words = []
    for _ in range(n):
        start_words.append(input_data[idx]); idx += 1
        
    target_words = []
    for _ in range(m):
        target_words.append(input_data[idx]); idx += 1
        
    start_masks = Counter()
    for word in start_words:
        mask = 0
        for c in word:
            mask |= (1 << (ord(c) - ord('a')))
        start_masks[mask] += 1
        
    count = 0
    for word in target_words:
        mask = 0
        for c in word:
            mask |= (1 << (ord(c) - ord('a')))
        # Check if removing one bit from mask results in a start_mask
        for i in range(26):
            if mask & (1 << i):
                prev_mask = mask ^ (1 << i)
                if prev_mask in start_masks:
                    count += 1
                    break
                    
    print(count)

solve()

