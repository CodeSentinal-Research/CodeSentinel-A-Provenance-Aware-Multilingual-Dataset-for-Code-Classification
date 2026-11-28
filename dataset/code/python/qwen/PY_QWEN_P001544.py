import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    x = int(input_data[2])
    nums = list(map(int, input_data[3:3+n]))
    
    current_sum = sum(nums[:k])
    count = 1 if current_sum > x else 0
    
    for i in range(k, n):
        current_sum += nums[i] - nums[i-k]
        if current_sum > x:
            count += 1
            
    print(count)

solve()

