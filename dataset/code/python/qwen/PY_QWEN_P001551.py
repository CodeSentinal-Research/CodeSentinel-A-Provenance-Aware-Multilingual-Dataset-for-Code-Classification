import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    left = 0
    current_sum = 0
    max_len = 0
    
    for right in range(n):
        current_sum += nums[right]
        while current_sum > k and left <= right:
            current_sum -= nums[left]
            left += 1
        if current_sum <= k:
            max_len = max(max_len, right - left + 1)
            
    print(max_len)

solve()

