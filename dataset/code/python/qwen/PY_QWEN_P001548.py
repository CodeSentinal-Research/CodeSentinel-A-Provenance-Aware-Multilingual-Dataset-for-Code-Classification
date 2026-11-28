import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    current_prod = 1
    for i in range(k):
        current_prod *= nums[i]
    max_prod = current_prod
    
    for i in range(k, n):
        current_prod = current_prod // nums[i-k] * nums[i]
        max_prod = max(max_prod, current_prod)
        
    print(max_prod)

solve()

