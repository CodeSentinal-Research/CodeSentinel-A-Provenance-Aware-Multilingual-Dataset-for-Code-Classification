import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    current_sum = sum(nums[:k])
    max_sum = current_sum
    
    for i in range(k, n):
        current_sum += nums[i] - nums[i-k]
        max_sum = max(max_sum, current_sum)
        
    print(max_sum)

solve()

