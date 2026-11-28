import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    left = 0
    bit_mask = 0
    max_len = 0
    
    for right in range(n):
        while bit_mask & nums[right]:
            bit_mask ^= nums[left]
            left += 1
        bit_mask |= nums[right]
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

