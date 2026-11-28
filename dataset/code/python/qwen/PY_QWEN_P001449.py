import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    num_set = set(nums)
    max_k = -1
    for num in nums:
        if num > 0 and -num in num_set:
            max_k = max(max_k, num)
            
    print(max_k)

solve()

