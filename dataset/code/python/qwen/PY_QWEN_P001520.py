import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    chunks = 0
    max_so_far = 0
    
    for i in range(n):
        max_so_far = max(max_so_far, nums[i])
        if max_so_far == i:
            chunks += 1
            
    print(chunks)

solve()

