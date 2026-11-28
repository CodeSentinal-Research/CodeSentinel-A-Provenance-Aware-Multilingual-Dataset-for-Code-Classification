import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    target = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    nums.sort()
    results = []
    
    for i in range(n - 3):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        for j in range(i + 1, n - 2):
            if j > i + 1 and nums[j] == nums[j-1]:
                continue
            left = j + 1
            right = n - 1
            remaining = target - nums[i] - nums[j]
            
            while left < right:
                current_sum = nums[left] + nums[right]
                if current_sum == remaining:
                    results.append((nums[i], nums[j], nums[left], nums[right]))
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif current_sum < remaining:
                    left += 1
                else:
                    right -= 1
                    
    for quad in results:
        print(*quad)

solve()

