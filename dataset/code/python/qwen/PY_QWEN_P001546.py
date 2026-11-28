import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    max_len = 1
    curr_len = 1
    
    for i in range(1, n):
        if (nums[i] % 2) != (nums[i-1] % 2):
            curr_len += 1
            max_len = max(max_len, curr_len)
        else:
            curr_len = 1
            
    print(max_len)

solve()

