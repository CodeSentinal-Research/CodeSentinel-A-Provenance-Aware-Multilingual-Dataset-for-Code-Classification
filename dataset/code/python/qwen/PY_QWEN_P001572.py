import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    current_sum = sum(nums[:k])
    count = 1 if current_sum % 2 == 0 else 0
    
    for i in range(k, n):
        current_sum += nums[i] - nums[i-k]
        if current_sum % 2 == 0:
            count += 1
            
    print(count)

solve()

