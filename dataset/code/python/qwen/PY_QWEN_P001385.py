import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    for num in nums:
        index = abs(num) - 1
        if nums[index] > 0:
            nums[index] = -nums[index]
            
    missing = []
    for i in range(n):
        if nums[i] > 0:
            missing.append(i + 1)
            
    print(" ".join(map(str, missing)))

solve()

