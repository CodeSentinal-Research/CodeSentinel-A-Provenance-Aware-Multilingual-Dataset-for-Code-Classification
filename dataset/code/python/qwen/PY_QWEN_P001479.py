import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    sorted_nums = sorted(nums)
    start = 0
    end = n - 1
    
    while start < n and nums[start] == sorted_nums[start]:
        start += 1
        
    while end >= 0 and nums[end] == sorted_nums[end]:
        end -= 1
        
    if start >= end:
        print(0)
    else:
        print(end - start + 1)

solve()

