import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    # Bad pairs: j - i != nums[j] - nums[i] => nums[i] - i != nums[j] - j
    # Total pairs - Good pairs
    # Good pairs: nums[i] - i == nums[j] - j
    
    diffs = [nums[i] - i for i in range(n)]
    from collections import Counter
    counter = Counter(diffs)
    
    good_pairs = 0
    for c in counter.values():
        good_pairs += c * (c - 1) // 2
        
    total_pairs = n * (n - 1) // 2
    print(total_pairs - good_pairs)

solve()

