import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    target = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    left = 0
    current_sum = 0
    min_len = float('inf')
    
    for right in range(n):
        current_sum += nums[right]
        while current_sum >= target:
            min_len = min(min_len, right - left + 1)
            current_sum -= nums[left]
            left += 1
            
    print(min_len if min_len != float('inf') else 0)

solve()

