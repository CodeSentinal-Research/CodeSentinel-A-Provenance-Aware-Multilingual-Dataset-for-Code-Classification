import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    masks = []
    for _ in range(n):
        word = input_data[idx]; idx += 1
        mask = 0
        for c in word:
            mask |= (1 << (ord(c) - ord('a')))
        masks.append(mask)
        
    from collections import Counter
    mask_counts = Counter(masks)
    
    pairs = 0
    for mask, count in mask_counts.items():
        pairs += count * (count - 1) // 2
        
    print(pairs)

solve()

