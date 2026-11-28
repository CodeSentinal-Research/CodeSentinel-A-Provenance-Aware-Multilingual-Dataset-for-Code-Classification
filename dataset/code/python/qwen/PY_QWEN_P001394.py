import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    prefix_sum = 0
    sum_indices = {}
    max_len = 0
    
    for i in range(n):
        prefix_sum += nums[i]
        if prefix_sum == k:
            max_len = i + 1
        if (prefix_sum - k) in sum_indices:
            max_len = max(max_len, i - sum_indices[prefix_sum - k])
        if prefix_sum not in sum_indices:
            sum_indices[prefix_sum] = i
            
    print(max_len)

solve()

