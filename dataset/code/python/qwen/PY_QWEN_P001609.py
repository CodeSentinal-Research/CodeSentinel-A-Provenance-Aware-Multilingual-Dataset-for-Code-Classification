import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    total_sum = sum(nums)
    left_sum = 0
    count = 0
    
    for i in range(n):
        right_sum = total_sum - left_sum - nums[i]
        if left_sum == right_sum:
            count += 1
        left_sum += nums[i]
        
    print(count)

solve()

