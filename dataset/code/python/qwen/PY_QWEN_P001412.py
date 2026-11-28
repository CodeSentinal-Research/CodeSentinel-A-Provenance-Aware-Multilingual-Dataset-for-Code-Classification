import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n]))
    
    nums_set = set(nums)
    count = 0
    for num in nums:
        if num + k in nums_set:
            count += 1
            
    print(count)

solve()

