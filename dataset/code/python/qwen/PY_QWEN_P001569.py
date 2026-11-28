import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    left = 0
    max_sum = 0
    current_sum = 0
    seen = set()
    
    for right in range(n):
        while nums[right] in seen:
            seen.remove(nums[left])
            current_sum -= nums[left]
            left += 1
        seen.add(nums[right])
        current_sum += nums[right]
        max_sum = max(max_sum, current_sum)
        
    print(max_sum)

solve()

