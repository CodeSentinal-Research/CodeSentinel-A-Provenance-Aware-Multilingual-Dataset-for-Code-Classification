import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    total_ones = sum(nums)
    if total_ones == 0:
        print(0)
        return
        
    # Sliding window of size total_ones
    min_zeros = float('inf')
    current_zeros = 0
    
    for i in range(total_ones):
        if nums[i] == 0:
            current_zeros += 1
            
    min_zeros = current_zeros
    
    for i in range(total_ones, n):
        if nums[i] == 0:
            current_zeros += 1
        if nums[i - total_ones] == 0:
            current_zeros -= 1
        min_zeros = min(min_zeros, current_zeros)
        
    print(min_zeros)

solve()

