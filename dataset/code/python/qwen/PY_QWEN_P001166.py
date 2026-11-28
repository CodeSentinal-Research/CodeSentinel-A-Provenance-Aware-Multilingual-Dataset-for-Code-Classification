import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    max_kadane = nums[0]
    current_max = nums[0]
    total_sum = nums[0]
    min_kadane = nums[0]
    current_min = nums[0]
    
    for i in range(1, n):
        current_max = max(nums[i], current_max + nums[i])
        max_kadane = max(max_kadane, current_max)
        
        current_min = min(nums[i], current_min + nums[i])
        min_kadane = min(min_kadane, current_min)
        
        total_sum += nums[i]
        
    if max_kadane < 0:
        print(max_kadane)
    else:
        print(max(max_kadane, total_sum - min_kadane))

if __name__ == "__main__":
    solve()

