import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    left_prod = [1] * n
    right_prod = [1] * n
    
    for i in range(1, n):
        left_prod[i] = left_prod[i-1] * nums[i-1]
        
    for i in range(n-2, -1, -1):
        right_prod[i] = right_prod[i+1] * nums[i+1]
        
    result = [left_prod[i] * right_prod[i] for i in range(n)]
    print(*result)

solve()

