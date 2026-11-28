import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    # Replace 0 with -1 to use prefix sum for equal 0s and 1s
    for i in range(n):
        if nums[i] == 0:
            nums[i] = -1
            
    prefix_sum = 0
    sum_indices = {0: -1}
    max_len = 0
    
    for i in range(n):
        prefix_sum += nums[i]
        if prefix_sum in sum_indices:
            max_len = max(max_len, i - sum_indices[prefix_sum])
        else:
            sum_indices[prefix_sum] = i
            
    print(max_len)

solve()

