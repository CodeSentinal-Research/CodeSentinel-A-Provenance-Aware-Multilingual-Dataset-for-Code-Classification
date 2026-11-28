import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    target = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    left = 0
    right = n - 1
    
    while left < right:
        current_sum = nums[left] + nums[right]
        if current_sum == target:
            print(left + 1, right + 1)
            return
        elif current_sum < target:
            left += 1
        else:
            right -= 1
            
    print("-1")

solve()

