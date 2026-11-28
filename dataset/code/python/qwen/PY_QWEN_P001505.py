import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    left = 0
    product = 1
    count = 0
    
    for right in range(n):
        product *= nums[right]
        while left <= right and product >= k:
            product //= nums[left]
            left += 1
        count += right - left + 1
        
    print(count)

solve()

