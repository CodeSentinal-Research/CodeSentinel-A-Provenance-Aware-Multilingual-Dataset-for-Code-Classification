import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    if n == 0:
        print(0)
        return
        
    unique_idx = 1
    for i in range(1, n):
        if nums[i] != nums[unique_idx - 1]:
            nums[unique_idx] = nums[i]
            unique_idx += 1
            
    print(unique_idx)
    print(*nums[:unique_idx])

solve()

