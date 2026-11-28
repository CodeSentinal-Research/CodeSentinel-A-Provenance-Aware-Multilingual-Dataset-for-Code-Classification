import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    nums.sort()
    results = []
    
    for i in range(n - 2):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        left = i + 1
        right = n - 1
        target = -nums[i]
        
        while left < right:
            current_sum = nums[left] + nums[right]
            if current_sum == target:
                results.append((nums[i], nums[left], nums[right]))
                while left < right and nums[left] == nums[left+1]:
                    left += 1
                while left < right and nums[right] == nums[right-1]:
                    right -= 1
                left += 1
                right -= 1
            elif current_sum < target:
                left += 1
            else:
                right -= 1
                
    for triplet in results:
        print(*triplet)

solve()

