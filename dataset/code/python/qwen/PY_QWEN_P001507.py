import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    if n < 2:
        print(n)
        return
        
    inc = 1
    dec = 1
    max_len = 1
    
    for i in range(1, n):
        if nums[i] > nums[i-1]:
            inc = dec + 1
        elif nums[i] < nums[i-1]:
            dec = inc + 1
        else:
            inc = 1
            dec = 1
        max_len = max(max_len, inc, dec)
        
    print(max_len)

solve()

