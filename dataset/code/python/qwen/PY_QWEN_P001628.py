import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    max_len = 0
    current_sum = 0
    for i in range(n):
        current_sum += nums[i]
        if current_sum > 0:
            max_len = i + 1
            
    print(max_len)

solve()

