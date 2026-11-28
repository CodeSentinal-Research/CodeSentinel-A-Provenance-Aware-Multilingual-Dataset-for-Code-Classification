import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    if n == 1:
        print(nums[0])
        return
        
    max_prod = nums[0]
    min_prod = nums[0]
    result = nums[0]
    
    for i in range(1, n):
        if nums[i] < 0:
            max_prod, min_prod = min_prod, max_prod
            
        max_prod = max(nums[i], max_prod * nums[i])
        min_prod = min(nums[i], min_prod * nums[i])
        
        result = max(result, max_prod)
        
    print(result)

if __name__ == "__main__":
    solve()

