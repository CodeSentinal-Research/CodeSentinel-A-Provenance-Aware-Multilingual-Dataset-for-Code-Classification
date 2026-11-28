import sys
from collections import Counter

def reverse_num(x):
    rev = 0
    while x > 0:
        rev = rev * 10 + x % 10
        x //= 10
    return rev

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    # nums[i] + rev(nums[j]) = nums[j] + rev(nums[i])
    # nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
    
    diffs = [num - reverse_num(num) for num in nums]
    counter = Counter(diffs)
    
    pairs = 0
    MOD = 10**9 + 7
    for count in counter.values():
        pairs += count * (count - 1) // 2
        
    print(pairs % MOD)

solve()

