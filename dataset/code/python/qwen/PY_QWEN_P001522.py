import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    x = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    total_sum = sum(nums)
    target = total_sum - x
    
    if target < 0:
        print(-1)
        return
    if target == 0:
        print(n)
        return
        
    left = 0
    current_sum = 0
    max_inner_len = -1
    
    for right in range(n):
        current_sum += nums[right]
        while current_sum > target and left <= right:
            current_sum -= nums[left]
            left += 1
        if current_sum == target:
            max_inner_len = max(max_inner_len, right - left + 1)
            
    if max_inner_len == -1:
        print(-1)
    else:
        print(n - max_inner_len)

solve()

