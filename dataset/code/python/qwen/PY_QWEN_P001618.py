import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    prefix_xor = [0] * n
    prefix_xor[0] = nums[0]
    for i in range(1, n):
        prefix_xor[i] = prefix_xor[i-1] ^ nums[i]
        
    print(*prefix_xor)

solve()

