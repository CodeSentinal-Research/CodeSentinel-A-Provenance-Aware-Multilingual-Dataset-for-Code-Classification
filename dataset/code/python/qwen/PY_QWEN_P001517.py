import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort()
    left = 0
    right = n - 1
    min_max_sum = 0
    
    while left < right:
        min_max_sum = max(min_max_sum, nums[left] + nums[right])
        left += 1
        right -= 1
        
    print(min_max_sum)

solve()

