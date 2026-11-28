import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    current_sum = sum(nums[:k])
    min_sum = current_sum
    
    for i in range(k, n):
        current_sum += nums[i] - nums[i-k]
        min_sum = min(min_sum, current_sum)
        
    print(min_sum)

solve()

