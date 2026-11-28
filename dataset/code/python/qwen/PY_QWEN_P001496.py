import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    for i in range(n - 1):
        if nums[i] == nums[i+1]:
            nums[i] *= 2
            nums[i+1] = 0
            
    non_zeros = [x for x in nums if x != 0]
    zeros = [0] * (n - len(non_zeros))
    
    print(*(non_zeros + zeros))

solve()

